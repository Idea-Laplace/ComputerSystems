/*
   You are given the assignment of writing a functio that
   determines whether one string is longer than another.
   You decide to make use of thr string library function
   strlen having the following declaration:

   size_t strlen(const char *s);

   Here is tour first attempt at the function:

   int strlonger(char *s, char *t) {
    	return strlen(s) - strlen(t) > 0;
	}
	When you test this on some sample data, things do not
	seem to work quite rigt. You investigate further and 
	determine that, when compiled as a 32-bit program,
	data type size_t is defined in header file stdio.h
	to unsigned.

	A: For what causes will this function produce an incorrenct value?
	B: Explain how this incorrection result come about?
	C: Show how to fix the code so that it will work reliably.
*/

int strlonger(char *s, char *t) {
	return strlen(s) - strlen(t) > 0;
}

// A: When strlen(s) < strlen(t)
// B: Since strlen(s) and strlen(t) are unsigned type, when strlen(s) < strlen(t)
// strlen(s) - strlen(t) would return a positive value, which is not meant to.
// C: return strlen(s) > strlen(t);

