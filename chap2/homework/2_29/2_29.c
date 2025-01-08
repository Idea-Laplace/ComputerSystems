/*
   Fill in the followng table in the style of figure 2.25.
   Give the integer values of 5-bit arguments, the values
   of both their integer and two's complement sums, the bit
   level representation of the two's complement sum, and the
   case from the derivation of equation 2.13.

   10100 + 10001 (negative overflow)
   (-12) + (-15)
   -27 < -16 (case 1)
   -27 + 32 = 5 (00101)

   11000 + 11000 (normal)
   (-8)  + (-8)
   -16 (case 2)
   -16 (10000)

   10111 + 01000 (normal)
   (-9)  + 8 = -1
   -1 (case 2)
   -1 (11111)

   00010 + 00101 (normal)
     2   +   5  = 7
	 7 (case 3)
	 7 (00111)

   01100 + 00100 (positive overflow)
     12  +   4  = 16
	 16 >= 16 (case 4)
	 16 - 32 = -16 (10000)
