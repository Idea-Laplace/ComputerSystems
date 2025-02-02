short test(short x, short y, short z) {
	short val = z + y - x;
	if (z > 5) {
		if (y > 2)
			val = x / z;
		else
			val = x / y;
	} else if (z < 3)
		val = z / y;

	return val;
}


/*
   Follow the standard control flow:
   t = test_expr;
   if (!t)
       goto false;
   then_statement;
   goto done;
false:
   else_statement;
done:
*/
