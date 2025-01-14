/*
   As mentioned Problem 2.6, the integer 3,510,593 has hexadecimal
   representation 0x00359141, while the single-precision floating-
   point number 3,510,593.0 has hexadecimal representation 0x4a564504.
   Derive this floating point representation and explain the correlation
   between the bits of the integer and floating-point representation.

                        3   5    9   1    4   1
   (int):   00000000 00110101 10010001 01000001
   (float): 1.101011001000101000001 * 2^21

   e = 21 + 127 = 148, 10010100

   (float): 0 10010100 10101100100010100000100
                  4   a    5   6    4   5    0   4
   (bytewise): 01001010 01010110 01000101 00000100 

   integer representiation: 0x359141
   floating-point representation: 0x4a564504

*/



