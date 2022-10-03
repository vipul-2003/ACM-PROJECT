----------------------------------------------------------------------------------
-- Company: Research Paper
-- Engineer: 
-- 
-- Create Date:    12:12:06 09/15/2022 
-- Design Name: 32 Bit Multiplier
-- Module Name:    Multiplier - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------

library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Multiplier32x32 is
generic (no_of_bits : Natural:= 32);
Port ( InputA : in STD_LOGIC_VECTOR (no_of_bits-1 DOWNTO 0);
       InputB : in STD_LOGIC_VECTOR (no_of_bits-1 DOWNTO 0);
       OutputC : out STD_LOGIC_VECTOR (2*no_of_bits-1 DOWNTO 0)); 
end Multiplier32X32;
architecture Behavioral of Multiplier32x32 is
signal MUL : STD_LOGIC_VECTOR (2*no_of_bits-1 DOWNTO 0); 
begin
P1: process (InputA,InputB)
begin 
 MUL <= STD_LOGIC_VECTOR ( InputA * InputB ) ; --multiplication of two inputs (Input A and Input B) and stores them in mul 
end process P1;
outputC <= MUL ;
end Behavioral;
