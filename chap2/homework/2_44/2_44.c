/*
   Assume data type int is 32 bits long and uses a two's complement
   representation for signed values. Right shifts are performed ari-
   -thmetically for signed values and logically for unsigned values.
   The variables are delcared and initialized as follows:

   int x = foo(); // Arbitary value
   int y = bar(); // Arbitary value

   unsigned ux = x;
   unsigned uy = y;

   For each of the following C expressions, either (1) argue that
   it is true for all values of x and y, or
   (2) give values of x and y for which it is false

   A. (x > 0) || (x - 1 < 0)
   False, x = TMin, x < 0 and x - 1 > 0;

   B. (x & 7) != 7 || (x << 29 < 0)
   True
   x & 7 == 7 iff the last 3 digits are 111.
   Which result in the MSB to be 1 after << 29 operation.

   C. (x * x) >= 0
   False
   x = 2^16 - 1,
   x * x = 2^32 - 2^17 + 1
         = 2^31 + ... + 2^17 + 1
   Since MSB, representing the 2^31, is nonzero
   hence x*x is negative in the view of two's complement representation.
   
   D. x < 0 || -x <= 0
   True, if x >= 0, always -x <= 0.

   E. x > 0 || -x >= 0 
   False when x = TMin.

   F. x + y == ux + uy
   True, x + y is casted to unsigned.

   G. x * ~y + uy * ux == -x
   Refering to bit-level equivalence between sign type and unsigned type,
   x * ~y + ux * uy = T2U(x * (~y + y)) = T2U(-x),
*/


