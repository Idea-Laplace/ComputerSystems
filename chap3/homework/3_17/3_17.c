// A
long lt_cnt = 0;
long ge_cnt = 0;

long alternative_gotodiff_se(long x, long y) {
	long result;
	if (x < y)
		goto then;
	ge_cnt++;
	result = x - y;
	goto done;

then:
	lt_cnt++;
	result = y - x;

done:
	return result;
}

// B
/*
   In most respect, the choic is arbitrary. But the original
   rule works better for the common case where there is no
   else statement. For this case, we can simply modify the
   translation rule to be as follows:

   t = test-expr;
   if (!t)
       goto done;
   then-statement;
done:
   A translation based on the alterante rule is more cumbersome.
