// A
void code_goto_ver(short a, short *p) {
	if (a == 0)
		goto label_zero_ge;
	if (*p >= a)
		goto label_zero_ge;
	*p = a;

label_zero_ge:
	return;
}


// B
/*
   The first conditional branch is part of the implementation
   of the logical and, &&. If the test for 'a' being non-null
   fails, the code will skip the test of a >= *p, just as you
   have learned from C textbooks. The compilation from C code
   to assembly one explains such 'fast track'
*/
