library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

module calculator(

output std_logic_vector [31:0] result;
input std_logic_vector [15:0] dIn;
input std_logic clk, load, add, clear;
);

reg std_logic_vector [31:0] dReg;

begin
 always@(posedge clk) begin
	if (clear)
	 dReg = 0;
	elsif(load)
	 dReg[15:0] <= dIn;
	elsif(add)
	 dReg <= dReg + dIn;
			
end	
 result <= dReg;

end

endmodule
