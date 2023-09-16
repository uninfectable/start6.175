import Vector::*;
import Complex::*;

import FftCommon::*;
import Fifo::*;

interface Fft;
    method Action enq(Vector#(FftPoints, ComplexData) in);
    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
endinterface

(* synthesize *)
module mkFftCombinational(Fft);
    Fifo#(2,Vector#(FftPoints, ComplexData)) inFifo <- mkCFFifo;
    Fifo#(2,Vector#(FftPoints, ComplexData)) outFifo <- mkCFFifo;
    Vector#(NumStages, Vector#(BflysPerStage, Bfly4)) bfly <- replicateM(replicateM(mkBfly4));

    function Vector#(FftPoints, ComplexData) stage_f(StageIdx stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[stage][i].bfly4(twid, x);

            for(FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction

    rule doFft;
        if( inFifo.notEmpty && outFifo.notFull ) begin
            inFifo.deq;
            Vector#(4, Vector#(FftPoints, ComplexData)) stage_data;
            stage_data[0] = inFifo.first;

            for (StageIdx stage = 0; stage < 3; stage = stage + 1) begin
                stage_data[stage+1] = stage_f(stage, stage_data[stage]);
            end
            outFifo.enq(stage_data[3]);
        end
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

(* synthesize *)
module mkFftFolded(Fft);
    Fifo#(2,Vector#(FftPoints, ComplexData)) inFifo <- mkCFFifo;
    Fifo#(2,Vector#(FftPoints, ComplexData)) outFifo <- mkCFFifo;
    Vector#(16, Bfly4) bfly <- replicateM(mkBfly4);
    Reg#(StageIdx) stage <- mkRegU;
    Reg#(Vector#(FftPoints, ComplexData)) stage_data <- mkRegU;

    function Vector#(FftPoints, ComplexData) stage_f( Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[i].bfly4(twid, x);

            for(FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction

    rule doFft;
        let in = ?;
        if( stage == 0 ) begin
            inFifo.deq;
            in = inFifo.first;
        end else in = stage_data;
        let out = stage_f(in);
        if( stage == 2 ) outFifo.enq(out);
        else stage_data <= out;
        stage <= (stage == 2) ? 0 : stage + 1;
        //TODO: Implement the rest of this module
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in) if( inFifo.notFull );
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq if( outFifo.notEmpty );
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

(* synthesize *)
module mkFftInelasticPipeline(Fft);
    Fifo#(2,Vector#(FftPoints, ComplexData)) inFifo <- mkCFFifo;
    Fifo#(2,Vector#(FftPoints, ComplexData)) outFifo <- mkCFFifo;
    Vector#(3, Vector#(16, Bfly4)) bfly <- replicateM(replicateM(mkBfly4));
    Reg#(Maybe#(Vector#(FftPoints, ComplexData))) sd1 <- mkRegU;
    Reg#(Maybe#(Vector#(FftPoints, ComplexData))) sd2 <- mkRegU;

    function Vector#(FftPoints, ComplexData) stage_f(StageIdx stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[stage][i].bfly4(twid, x);

            for(FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction

    rule doFft;
        // if( inFifo.notEmpty && ( outFifo.notFull || !isValid(sd2) )) begin
        //     inFifo.deq;
        //     sd1 <= tagged Valid (stage_f(0,inFifo.first));
        // end else sd1 <= tagged Invalid;
        // case( sd1 ) matches
        //     tagged Invalid : sd2 <= tagged Invalid;
        //     tagged Valid .x : sd2 <= tagged Valid (stage_f(1,x));
        // endcase
        // case( sd2 ) matches
        //     tagged Valid .x : outFifo.enq(stage_f(2,x)); // no need tagged last time
        // endcase
        if( inFifo.notEmpty ) begin
            inFifo.deq;
            sd1 <= tagged Valid (stage_f(0,inFifo.first));
        end else sd1 <= tagged Invalid;
        case( sd1 ) matches
            tagged Invalid : sd2 <= tagged Invalid;
            tagged Valid .x : sd2 <= tagged Valid (stage_f(1,x));
        endcase
        case( sd2 ) matches
            tagged Valid .x : outFifo.enq(stage_f(2,x)); // no need tagged last time
        endcase //make sure high throughout but miss the correction
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

(* synthesize *)
module mkFftElasticPipeline(Fft);
    Fifo#(2,Vector#(FftPoints, ComplexData)) inFifo <- mkCFFifo;
    Fifo#(2,Vector#(FftPoints, ComplexData)) outFifo <- mkCFFifo;
    Vector#(3, Vector#(16, Bfly4)) bfly <- replicateM(replicateM(mkBfly4));
    Fifo#(2,Vector#(FftPoints, ComplexData)) f1 <- mkCFFifo;
    Fifo#(2,Vector#(FftPoints, ComplexData)) f2 <- mkCFFifo;

    function Vector#(FftPoints, ComplexData) stage_f(StageIdx stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp, stage_out;
        for (FftIdx i = 0; i < fromInteger(valueOf(BflysPerStage)); i = i + 1)  begin
            FftIdx idx = i * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            for (FftIdx j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(stage, idx+j);
            end
            let y = bfly[stage][i].bfly4(twid, x);

            for(FftIdx j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end

        stage_out = permute(stage_temp);

        return stage_out;
    endfunction
     
    //TODO: Implement the rest of this module
    // You should use more than one rule
    rule s1;
        inFifo.deq;
        f1.enq(stage_f(0,inFifo.first));
    endrule

    rule s2;
        f1.deq;
        f2.enq(stage_f(1,f1.first));
    endrule

    rule s3;
        f2.deq;
        outFifo.enq(stage_f(2,f2.first));
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

interface SuperFoldedFft#(numeric type radix);
    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
    method Action enq(Vector#(FftPoints, ComplexData) in);
endinterface

module mkFftSuperFolded(SuperFoldedFft#(radix)) provisos(Div#(TDiv#(FftPoints, 4), radix, times), Mul#(radix, times, TDiv#(FftPoints, 4)));
    Fifo#(2,Vector#(FftPoints, ComplexData)) inFifo <- mkCFFifo;
    Fifo#(2,Vector#(FftPoints, ComplexData)) outFifo <- mkCFFifo;
    Vector#(radix, Bfly4) bfly <- replicateM(mkBfly4);
    Reg#(Bit#(6)) single <- mkReg(0);
    Reg#(Vector#(FftPoints, ComplexData)) stage_data <- mkRegU;
    let ub = fromInteger(valueOf(radix));

    function Vector#(FftPoints, ComplexData) stage_f(Bit#(6) stage, Vector#(FftPoints, ComplexData) stage_in);
        Vector#(FftPoints, ComplexData) stage_temp = stage_in;
        for (Bit#(6) i = 0; i < ub; i = i + 1)  begin
            FftIdx idx = ({0,stage[3:0]}+i) * 4;
            Vector#(4, ComplexData) x;
            Vector#(4, ComplexData) twid;
            Bit#(3) rs = {0 , stage[5:4]};
            for (Bit#(6) j = 0; j < 4; j = j + 1 ) begin
                x[j] = stage_in[idx+j];
                twid[j] = getTwiddle(rs, idx+j);
            end
            let y = bfly[i].bfly4(x, twid);

            for(Bit#(6) j = 0; j < 4; j = j + 1 ) begin
                stage_temp[idx+j] = y[j];
            end
        end
        let t = 5'b10000-ub;
        if( stage[3:0] == t[3:0] ) return permute(stage_temp);
        else return stage_temp;
    endfunction

    rule doFft;
        // if( single[5:4] == 0 ) begin
        //     inFifo.deq;
        //     stage_data <= stage_f(single, inFifo.first);
        //     single <= single + fromInteger(valueOf(radix));
        // end else if( single[5:4] == 1 ) begin
        //     stage_data <= stage_f(single, stage_data);
        //     single <= single + fromInteger(valueOf(radix));
        // end else begin
        //     outFifo.enq(stage_f(single, stage_data));
        //     single <= 0;
        // end
        let sxIn = ?;
        if (single == 0) begin inFifo.deq; sxIn = inFifo.first; end
        else sxIn = stage_data;
        let sxOut = stage_f(single, sxIn);
        if (single == 48 - ub) begin outFifo.enq(sxOut); single <= 0; end
        else begin stage_data <= sxOut; single <= single + ub; end
    endrule

    method Action enq(Vector#(FftPoints, ComplexData) in);
        inFifo.enq(in);
    endmethod

    method ActionValue#(Vector#(FftPoints, ComplexData)) deq;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule

function Fft getFft(SuperFoldedFft#(radix) f);
    return (interface Fft;
        method enq = f.enq;
        method deq = f.deq;
    endinterface);
endfunction

(* synthesize *)
module mkFftSuperFolded4(Fft);
    SuperFoldedFft#(4) sfFft <- mkFftSuperFolded;
    return (getFft(sfFft));
endmodule