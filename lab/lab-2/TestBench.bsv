import TestBenchTemplates::*;
import Multipliers::*;

// Example testbenches
(* synthesize *)
module mkTbDumb();
    function Bit#(16) test_function( Bit#(8) a, Bit#(8) b ) = multiply_unsigned( a, b );
    Empty tb <- mkTbMulFunction(test_function, multiply_unsigned, True);
    return tb;
endmodule

(* synthesize *)
module mkTbFoldedMultiplier();
    Multiplier#(8) dut <- mkFoldedMultiplier();
    Empty tb <- mkTbMulModule(dut, multiply_signed, True);
    return tb;
endmodule

// Exercise 1
(* synthesize *)
module mkTbSignedVsUnsigned();
    function Bit#(16) test_function1( Bit#(8) a, Bit#(8) b ) = multiply_unsigned( a, b );
    function Bit#(16) test_function2( Bit#(8) a, Bit#(8) b ) = multiply_signed( a, b );
    Empty tb <- mkTbMulFunction(test_function1, test_function2, True);
    return tb;
endmodule

// Exercise 3
(* synthesize *)
module mkTbEx3();
    function Bit#(16) test_function1( Bit#(8) a, Bit#(8) b ) = multiply_unsigned( a, b );
    function Bit#(16) test_function2( Bit#(8) a, Bit#(8) b ) = multiply_by_adding( a, b );
    Empty tb <- mkTbMulFunction(test_function1, test_function2, True);
    return tb;
endmodule

// Exercise 5
(* synthesize *)
module mkTbEx5();
    Multiplier#(8) mod <- mkFoldedMultiplier();
    Empty tb <- mkTbMulModule(mod, multiply_by_adding(), True);
    return tb;
endmodule

// Exercise 7
(* synthesize *)
module mkTbEx7a();
    Multiplier#(8) mod <- mkBoothMultiplier();
    Empty tb <- mkTbMulModule(mod, multiply_signed, True);
    return tb;
endmodule

// Exercise 7
(* synthesize *)
module mkTbEx7b();
    Multiplier#(31) mod <- mkBoothMultiplier();
    Empty tb <- mkTbMulModule(mod, multiply_signed, True);
    return tb;
endmodule

// Exercise 9
(* synthesize *)
module mkTbEx9a();
Multiplier#(64) mod <- mkBoothMultiplierRadix4();
    Empty tb <- mkTbMulModule(mod, multiply_signed, True);
    return tb;
endmodule

// Exercise 9
(* synthesize *)
module mkTbEx9b();
Multiplier#(32) mod <- mkBoothMultiplierRadix4();
    Empty tb <- mkTbMulModule(mod, multiply_signed, True);
    return tb;
endmodule

