/*
   For each of the following values of K, find ways to express x * K
   using only the specified number of operations, where we consider
   both additions and subtractions to have comparable cost. You may
   need to use some tricks beyond the simple form A and B rules we
   have considered so far.

   1. K = 7, shift = 1, Add/Subs = 1
   x * 7 = (x << 3) - x

   2. K = 30, shifts = 4, Add/Subs = 3
   x * 30 = (x << 4) + (x << 3) + (x << 2) + (x << 1)
   x * 30 = (x << 5) - (x << 1)

   3. K = 28, shifts = 2, Add/Subs = 1
   x * 28 = (x << 5) - (x << 2)

   4. K = 55, shifts = 2, Add/Subs = 2
   x * 55 = (x << 6) - (x << 3) - x
*/
