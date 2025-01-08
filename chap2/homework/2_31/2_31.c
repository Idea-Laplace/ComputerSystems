/*
   Your coworker gets impatient with your analysis of the overflow
   conditions for 2's complement addition and presents you with the
   following implementation of tadd_ok:

   // Warning: This cod is buggy.
   int tadd_ok_buggy(int x, int y) {
       int s = x + y;
	   return (s - x == y) && (s - y == x);
	}

	You look at the code and laugh. Explain why.
*/

int tadd_ok_buggy(int x, int y) {
	int s = x + y;
	return (s - x == y) && (s - y == x);
}

/*
   Without loss of generality, s - x could be
   one of y, y + 2^w, y - 2^w.
   In the case of y itself, there are no harms,
   and y - 2^w happens only if 0 < y < 2^(w-1),
   -2^w < y - 2^w < -2^(w-1), which should be
   adjusted by +2^w, resulting in y itself.
   Finally, in the case of y + 2^w, it only happens
   TMIn <= y < 0, which make the range of y + 2^w be:
   2^(w-1) <= y < 2^w, which should be adjusted by
   -2^w, resulting in y itself.
   Hence, That function cannot detect ANY overflow.
   What a dumb function.
*/


/*
   Actually, +(t, w) is both commutative and associative.
   Since +(t, w)(x, y) is same as U2T(+(u, w)(T2U(x), T2U(y))
   (a +(t, w) b) + (t, w) c = U2T(((ua + ub)mod 2^w) +(t, w) c
                            = U2T((ua + ub + uc)mod 2^w)
							= U2T(ua +(u, w) (ub + uc)mod2^w)
							= a +(t,w) U2T((ub + uc)mod2^w)
							= a +(t,w) (b +(t,w) c))
   so, s -(t, w) x = x +(t, w) +(t, w)(-x)
                   = (x -(t, w)x) +(t, w)y
				   = y
*/
   
