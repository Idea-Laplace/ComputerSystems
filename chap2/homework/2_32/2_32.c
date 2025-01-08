/*
   You are assinged the task of writing code for a function
   tsub_ok, with arguments x and y, that will return 1 if
   computing x-y does not cause overflow. Having just written
   the code for Problem 2.30, you write the following:

   int sub_ok(int x, int y) {
       return tadd_ok(x, -y);
	}
	For what values of x and y will this function give
	incorrect results? Writing a correct version of this function
	is left as an exercise Prob. 2.74
*/

int tadd_ok(int x, int y) {
	int s = x + y;
	int p_overflow = (x > 0 && y > 0 && s <= 0);
	int n_overflow = (x < 0 && y < 0 && s >= 0);
	return !p_overflow && !n_overflow;
}

/*
   When y is the TMin, y = -y, Since TMin +(t,w) TMin = 0
   so, tadd_ok(x, -TMin) should be tadd_ok(x, TMin)
   If x < 0, then x - TMin = x + (2^(w-1)), which causes no overflow.
   However, we showed tsub_ok(-1, TMin) = tadd_ok(-1, -TMIn) = tadd(-1, TMin),
   and that'd be evaluated as 0, meaning that -1 - TMin causes overflow, which
   is not true.
*/
