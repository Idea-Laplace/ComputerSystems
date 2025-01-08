/*
   You are given assignment to develop code for a function tmult_ok
   that will determine whether can be multiplicated without causing
   overflow.

   // Determine whether arguments can be multiplied without oveflow
   int tmult(int x, int y) {
   int p = x * y;
   return !x || p/x == y;
   }

   You test this code for a number of values of x and y, and it seems
   to work properly. Your coworker challenges you, saying, "If I can't
   use subtraction to test whether addition has overflowed(prob. 2.31)
   , then how can you use division to test whether multiplication has
   overflowed?"
    Devise a mathematical justification of your approach, along the fo-
	-llowing lines.
   First: aruge that the case x=0 is handled correctly.
   Otherwise, consider w-bit x(x!=0), y, p and q, where p is the result
   of performing two's complement multiplication on x and y, and q is 
   the result of dividing p by x.

   1. Show that x * y, the integer product of x and y, can be written
   in the form of p + t*2^w, where t != 0 iff the computation of p
   overflows.

   2. Show that p can be written in the form of p = x * q + r.
   3. Show that q = y iff r = t = 0
*/

int tmult_ok(int x, int y) {
	int p = x * y;
	return !x || p / x == y;
}

/*
   Showing that x * y doesn't cause overflow when x = 0 is trivial,
   since x * y = 0, clearly not overflowed.

   x * y = p + t * 2^w,
   Let z = x * y.
   -2^(w-1) <= p < 2^(w-1), that is, x *(t, w) y.
   -2^(w-1) <= p < 2^(w-1)
   if t = 0;
   z = p, clearly not overflowed.
   if z is not overflowed, then
   -2^(w-1) <= p + t*2^w < 2^(w-1).
   It is sufficient to show that t != 1 and t != -1.
   2^(w-1) <= p + 2^w < 2^(w-1) + 2^w
   -2^(w-1) -2^w <= p -2^w < -2^(w-1)
   clearly in the ranged of overflow, so t must be 0.

   p = x * y - t * 2^w = x(y + q') + r = x * q + r
   q := q' + y
   q = y iff q' is 0, where t * 2^w = x * q' + r
   since 2^w is never 0, t * 2 ^ w = 0 iff t = 0,
   when t = 0, x * q' + r = 0, since x != 0 and |r| < |x|,
   both r and q' should be 0, the inverse is obivous.

   q' and r are 0 iff t = 0, meaning q = y and r = 0 iff t = 0.

   The difference between addition-subtraction and multplication-division
   is that, the value of residue could happen while computing division,
   which causes  x * y / x != y.
   and the residue is nonzero only if x *(t, w) y causes overflow.
   In addition-subtraction cases, however, such 'loss' never happens,
   this is because addition and subtraction are closed operation under
   Z_2^w group, while the division is not.
*/




