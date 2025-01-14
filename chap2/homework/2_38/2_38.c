/*
   As we will see in the chapter 3, the LEA instruction can perform
   computation of the form (a << k) + b, where k is either 1, 2, or 3,
   and b is either 0 or some program value. The complier often
   uses this instruction to perform multiplications by constant fators.
   For example, we can compute 3 * a as a << 1 + a.
    Consider cases where b is either 0 or equal to a,and all possible
   values of k, what multiplies of a can be computed with a single
   instruction?

   a * 1 = a
   a * 2 = a << 1
   a * 3 = a << 1 + a
   a * 4 = a << 2
   a * 5 = a << 2 + a
   a * 6 (Cannot be computed with a single instruction.)
   a * 7 (Cannot by computed with a single instruction.)
   a * 8 = a << 3
   a * 9 = a << 3 + a
   a * 10 (After 10, Cannot be computed with a single instruction.)
   In brief, multiplying by 1, 2, 3, 4, 5, 8, 9 can be computed with
   a single LEA instruction.
*/
