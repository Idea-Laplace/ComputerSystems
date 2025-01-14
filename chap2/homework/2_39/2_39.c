/*
   How could we modify the expression for form B for the
   case where bit position n is the most significant bit?

   Form B: (x << (n + 1)) - (x << m)
   x << (n + 1) == 0, thus
   Form B: -(x << m) = ~(x << m) + 1 (when the position n is the MSB.)
*/


