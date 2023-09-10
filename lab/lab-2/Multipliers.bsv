// Reference functions that use Bluespec's '*' operator
function Bit#(TAdd#(n,n)) multiply_unsigned( Bit#(n) a, Bit#(n) b );
    UInt#(n) a_uint = unpack(a);
    UInt#(n) b_uint = unpack(b);
    UInt#(TAdd#(n,n)) product_uint = zeroExtend(a_uint) * zeroExtend(b_uint);
    return pack( product_uint );
endfunction

function Bit#(TAdd#(n,n)) multiply_signed( Bit#(n) a, Bit#(n) b );
    Int#(n) a_int = unpack(a);
    Int#(n) b_int = unpack(b);
    Int#(TAdd#(n,n)) product_int = signExtend(a_int) * signExtend(b_int);
    return pack( product_int );
endfunction

// Exercise 2
// Multiplication by repeated addition
function Bit#(TAdd#(n,n)) multiply_by_adding( Bit#(n) a, Bit#(n) b );
    UInt#(TAdd#(n,n)) a_uint = zeroExtend(unpack(a));
    UInt#(n) b_uint = unpack(b);
    UInt#(TAdd#(n,n)) sum = 0;
    for(Integer i = 0 ; i < valueof(n) ; i = i+1 )
    begin
        if (pack(b_uint)[0] == 1)
        begin
        sum = sum + zeroExtend(a_uint);
        end
        a_uint = a_uint << 1;
        b_uint = b_uint >> 1;
    end
    return pack(sum);
endfunction

// function Bit#(TAdd#(n,n)) multiply_by_adding( Bit#(n) a, Bit#(n) b );
//     UInt#(TAdd#(n,n)) a_uint = zeroExtend(unpack(a));
//     UInt#(n) b_uint = unpack(b);
//     UInt#(TAdd#(n,n)) sum = 0;
//     for(Integer i = 0 ; i < toInteger(b) ; i = i+1 )
//     begin
//         sum = sum + zeroExtend(a_uint);
//     end
//     return pack(sum);
// endfunction

// Multiplier Interface
interface Multiplier#( numeric type n );
    method Bool start_ready();
    method Action start( Bit#(n) a, Bit#(n) b );
    method Bool result_ready();
    method ActionValue#(Bit#(TAdd#(n,n))) result();
endinterface


// Exercise 4
// Folded multiplier by repeated addition
module mkFoldedMultiplier( Multiplier#(n) )
    provisos(Add#(1, __a , n));
    // You can use these registers or create your own if you want
    Integer tn = fromInteger(valueOf(n))-1;
    Reg#(Bit#(n)) a <- mkRegU();
    Reg#(Bit#(n)) b <- mkRegU();
    Reg#(Bit#(n)) prod <- mkRegU();
    Reg#(Bit#(n)) tp <- mkRegU();
    Reg#(Bit#(TAdd#(TLog#(n),1))) i <- mkReg( fromInteger(valueOf(n)+1) );

    rule mulStep(i < fromInteger(valueOf(n)));
        Bit#(n) tmp = b[i] == 1 ? a : 0;
        Bit#(TAdd#(n,1)) sum = zeroExtend(tmp)+zeroExtend(tp); 
        tp <= truncateLSB(sum);
        prod <= {sum[0] , prod [tn:1] };//provisos suit for here
        i <= i + 1;
    endrule

    method Bool start_ready();
        if ( i == fromInteger(valueOf(n)+1) )
        begin
            return True;
        end else begin
            return False;
        end
    endmethod

    method Action start( Bit#(n) aIn, Bit#(n) bIn );
        a <= aIn;
        b <= bIn;
        prod <= 0;
        tp <= 0;
        i <= 0;
    endmethod

    method Bool result_ready();
        if ( i == fromInteger(valueOf(n)) )
        begin
            return True;
        end else begin
            return False;
        end
    endmethod

    method ActionValue#(Bit#(TAdd#(n,n))) result ();
        i <= i+1;
        return {tp , prod};
    endmethod
endmodule



function Bit#(n) arth_shift(Bit#(n) a, Integer n, Bool right_shift);
    Int#(n) a_int = unpack(a);
    Bit#(n) out = 0;
    if (right_shift) begin
        out = pack(a_int >> n);
    end else begin //left shift
        out = pack(a_int <<n); end
    return out;
endfunction



// Exercise 6
// Booth Multiplier
module mkBoothMultiplier( Multiplier#(n) );
    Reg#(Bit#(TAdd#(TAdd#(n,n),1))) m_neg <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),1))) m_pos <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),1))) p <- mkRegU;
    Reg#(Bit#(TAdd#(TLog#(n),1))) i <- mkReg( fromInteger(valueOf(n)+1) );

    rule mul_step(i < fromInteger(valueOf(n)));
        let pr = p[1:0];
        if ( pr == 2'b01 )
        begin
            p <= arth_shift(p + m_pos, 1, True);
        end else if ( pr == 2'b10 )
        begin
            p <= arth_shift(p + m_neg, 1, True);
        end else
        begin
            p <= arth_shift(p , 1 , True);
        end
        i <= i + 1;
    endrule

    method Bool start_ready();
        if( i == fromInteger(valueOf(n)+1) )
        begin
            return True;
        end else begin
            return False;
        end
    endmethod

    method Action start( Bit#(n) m, Bit#(n) r );
        p <= {0, r, 1'b0};
        m_pos <= {m, 0};
        m_neg <= {(-m),0};
        i <= 0;
    endmethod

    method Bool result_ready();
        if( i == fromInteger(valueOf(n)) )
        begin
            return True;
        end else begin
            return False;
        end
    endmethod

    method ActionValue#(Bit#(TAdd#(n,n))) result();
        i <= i + 1;
        return p[valueOf(TAdd#(n,n)):1];
    endmethod
endmodule



// Radix-4 Booth Multiplier
module mkBoothMultiplierRadix4( Multiplier#(n) );
    Reg#(Bit#(TAdd#(TAdd#(n,n),2))) m_neg <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),2))) m_pos <- mkRegU;
    Reg#(Bit#(TAdd#(TAdd#(n,n),2))) p <- mkRegU;
    Reg#(Bit#(TAdd#(TLog#(n),1))) i <- mkReg( fromInteger((valueOf(n)+1)/2+1) );
    rule mul_step(i < fromInteger(valueOf(n)+1)/2);
        let pr = p[2:0];
        if ( pr == 3'b001 || pr == 3'b010 )
        begin
            p <= arth_shift( p + m_pos , 2 , True);
        end else if( pr == 3'b011 )
        begin
            p <= arth_shift( p + arth_shift(m_pos ,1 , False) , 2, True);
        end else if( pr == 3'b100 )
        begin
            p <= arth_shift( p + arth_shift(m_neg ,1 ,False), 2 ,True);
        end else if( pr == 3'b101 || pr == 3'b110 )
        begin
            p <= arth_shift( p + m_neg , 2, True);
        end else
        begin
            p <= arth_shift(p , 2, True);
        end
        i <= i + 1;
    endrule

    method Bool start_ready();
        if( i == fromInteger(valueOf(n)+1)/2+1 )
        begin
            return True;
        end else begin
            return False;
        end
    endmethod

    method Action start( Bit#(n) m, Bit#(n) r );
        p <= {0, r, 1'b0};//if odd should be what?
        m_pos <= {msb(m),m, 0};
        m_neg <= {msb(-m),-m,0};
        i <= 0;
    endmethod

    method Bool result_ready();
        if( i == fromInteger(valueOf(n)+1)/2 )
        begin
            return True;
        end else begin
            return False;
        end
    endmethod

    method ActionValue#(Bit#(TAdd#(n,n))) result();
        i <= i+1;
        return p[valueOf(TAdd#(n,n)):1];
    endmethod
endmodule