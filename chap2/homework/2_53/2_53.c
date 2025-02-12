/* 
   Fill in the following macro definitions to generate the double-precision
   values +infinity, -infinity, and -0:

#define POS_INFINITY
#define NEG_INFINITY
#define NEG_ZERO

	You cannot use any include files (such as math.h), but you can make use of
	the fact that the largest finite number that can be represented with double
	precision is around 1.8 * 10^308.
*/


#define POS_INFINITY 1e310
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (1.0 / NEG_INFINITY) // #define NEG_ZERO (-1.0 / POS_INFINITY)
