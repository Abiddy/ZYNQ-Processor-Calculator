----------------------------------------------------------------------------------
-- Simple Binary Calculator
-- Mohammad Nouman Abidi
-- ZYNQ Processor
--
-- The calculator has three main functions: 
--
--		clear stored value
--		enter new value
--		add to stored value
--
-- Inputs and outputs are 32 bit
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
--use work.commonDefs.all;

entity calculator is port (
	clk: in std_logic;
	clear, load, add: in std_logic;	-- signals to enable operations
	dIn: in std_logic_vector (31 downto 0);		-- input data
	result: out std_logic_vector (31 downto 0));	-- output result
end calculator;

architecture a1 of calculator is
signal dReg: std_logic_vector (31 downto 0);
begin
	process (clk) begin
		if rising_edge(clk) then
			if clear = '1' then
				dReg <= (others => '0');
			elsif load = '1' then
				dReg <= dIn;
			elsif add = '1' then
				dReg <= dReg + dIn;
			end if;
		end if;
	end process;
	result <= dReg;
end a1;
