import Ehr::*;
import Vector::*;
import FIFO::*;
import FIFOF::*;
import SpecialFIFOs::*;

interface Fifo#(numeric type n, type t);
    method Action enq(t x);
    method Action deq;
    method t first;
    method Bool notEmpty;
endinterface

module mkCFifo1(Fifo#(1, t)) provisos (Bits#(t, tSz));
    // donot init this register
    Reg#(t) data <- mkRegU;
    Reg#(Bool) valid <- mkReg(False);
    method Action enq(t x) if (!valid);
        data <= x;
        valid <= True;
    endmethod
    method Action deq if (valid);
        valid <= False;
    endmethod
    method t first if (valid);
        return data;
    endmethod
    method Bool notEmpty;
        return valid;
    endmethod
endmodule

module mkCFifo3(Fifo#(3, t)) provisos (Bits#(t, tSz));
    // Vector#(3, Fifo#(1, t)) fifos <- replicateM(mkCFifo1);
    Vector#(3, Fifo#(1, t)) fifos <- replicateM(mkPipelineFifo);
    // Vector#(3, Fifo#(2, t)) fifos <- replicateM(mkCFFifo);
    function Bool indexNotEmpty(Integer i);
        return fifos[i].notEmpty;
    endfunction
    Vector#(3, Integer) indexing = genVector;
    Bool fifoNotEmpty = unpack(|pack(map(indexNotEmpty, indexing)));
    // Bool fifoNotFull = unpack(&pack(map(indexNotEmpty, indexing)));
    Vector#(3, Wire#(Bool)) blocking <- replicateM(mkDWire(False));

    for (Integer i = 1; i < 3; i = i + 1) begin
        rule pipeline if (!blocking[i - 1]);
            fifos[i].enq(fifos[i - 1].first);
            fifos[i - 1].deq;
        endrule
    end

    method Action enq(t x);
        fifos[0].enq(x);
    endmethod

    method t first if (fifoNotEmpty);
        t result = unpack('0);
        for (Integer i = 0; i < 3; i = i + 1) begin
            if (indexNotEmpty(i)) begin
                result = fifos[i].first;
            end
        end
        return result;
    endmethod
    method Action deq if (fifoNotEmpty);
        Bool poped = False;
        for (Integer i = 2; i >= 0; i = i - 1) begin
            if (indexNotEmpty(i) && !poped) begin
                fifos[i].deq;
                poped = True;
                blocking[i] <= True;
            end
        end
    endmethod

    method Bool notEmpty;
        return fifoNotEmpty;
    endmethod
endmodule

// `CF' = Conflict Free
module mkCFBypassFifo3(Fifo#(3, t)) provisos (Bits#(t, tSz));
    FIFOF#(t) bsfif <- mkSizedBypassFIFOF(3);
    method Action enq(t x);
        bsfif.enq(x);
    endmethod
    method Action deq = bsfif.deq;
    method t first = bsfif.first;
    method Bool notEmpty = bsfif.notEmpty;
endmodule

// Exercise 1
module mkFifo(Fifo#(3,t)) provisos (Bits#(t,tSz));
   // define your own 3-elements fifo here.     

endmodule


// Two elements conflict-free fifo given as black box
module mkCFFifo( Fifo#(2, t) ) provisos (Bits#(t, tSz));
    Ehr#(2, t) da <- mkEhr(?);
    Ehr#(2, Bool) va <- mkEhr(False);
    Ehr#(2, t) db <- mkEhr(?);
    Ehr#(2, Bool) vb <- mkEhr(False);

    rule canonicalize;
        if( vb[1] && !va[1] ) begin
            da[1] <= db[1];
            va[1] <= True;
            vb[1] <= False;
        end
    endrule

    method Action enq(t x) if(!vb[0]);
        db[0] <= x;
        vb[0] <= True;
    endmethod

    method Action deq() if(va[0]);
        va[0] <= False;
    endmethod

    method t first if (va[0]);
        return da[0];
    endmethod

    method Bool notEmpty();
        return va[0];
    endmethod
endmodule

module mkCF3Fifo(Fifo#(3,t)) provisos (Bits#(t, tSz));
    FIFO#(t) bsfif <-  mkSizedFIFO(3);
    method Action enq( t x);
        bsfif.enq(x);
    endmethod

    method Action deq();
        bsfif.deq();
    endmethod

    method t first();
        return bsfif.first();
    endmethod

    method Bool notEmpty();
        return True;
    endmethod

endmodule

module mkPipelineFifo(Fifo#(1, t)) provisos(Bits#(t, tSz));
    Reg#(t) d <- mkRegU;
    Ehr#(2, Bool) v <- mkEhr(False);

    let notFull_ = !v[1];
    let notEmpty_ = v[0];
    // method Bool notFull = notFull_;
    method Bool notEmpty = notEmpty_;
    method Action enq(t x) if (notFull_);
        d <= x;
        v[1] <= True;
    endmethod
    method Action deq if (notEmpty_);
        v[0] <= False;
    endmethod
    method t first if (notEmpty_);
        return d;
    endmethod
endmodule

module mkBypassFifo(Fifo#(1, t)) provisos(Bits#(t, tSz));
    Ehr#(2, t) d <- mkEhr(?);
    Ehr#(2, Bool) v <- mkEhr(False);

    let notFull_ = !v[0];
    let notEmpty_ = v[1];
    // method Bool notFull = notFull_;
    method Bool notEmpty = notEmpty_;
    method Action enq(t x);
        d[0] <= x;
        v[0] <= True;
    endmethod
    method Action deq;
        v[1] <= False;
    endmethod
    method t first;
        return d[1];
    endmethod
endmodule