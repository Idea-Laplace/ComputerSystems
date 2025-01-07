/* Problem 2.10
   As the name implies we claim that the effect of this procedure
   is to swap the values stred at the location denoted by pointer
   variables x and y. Note that unlike the usual technique for
   swapping two values, we do not need a third location to store
   one value while we are moving the other. There is no performance
   advantage, however, to this way of swapping: it is merely an
   intellectual amusement.
*/

#include <stdio.h>

void inplace_swap(int *x, int *y);

int main(void) {
	int i, j;

	printf("Enter 2 integers: ");
	scanf(" %d %d", &i, &j);
	while (getchar() != '\n');

	printf("integer 1: %d\n", i);
	printf("Bit pattern: %b\n", i);
	putchar();
	printf("integer 2: %d\n", j);
	printf("Bit pattern: %b\n", j);
	putchar();

	printf("After inplace_swap:\n");
	inplace_swap(&i, &j);
	putchar();

	printf("integer 1: %d\n", i);
	printf("Bit pattern: %b\n", i);
	putchar();
	printf("integer 2: %d\n", j);
	printf("Bit pattern: %b\n", j);

	return 0;
}


void inplace_swap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

/*
   Step    *x               *y
   init    a                b
   1st     a                a^b
   2nd     a^(a^b)=b        a^b
   3rd     b                b^(a^b)=a

   This is because the ^ operator is both commutative and associative.
   Proof of the commutativity is trivial, while proof of associativity is:

   In the context of ^, 0 is actually the identity for ^,
   while the inverse of an element is the element itself.
   Since ^ is a bitwise operator, it is sufficient to prove it in the case of sigle bit.

   case 1: All 3 bits are same.

   (a^a)^a = 0^a = a
   a^(a^a) = a^0 = a

   case 2: One of them is different from the others.

   (a^b)^a = 1^a = b
   a^(b^a) = a^1 = b

   (b^a)^a = 1^a = b
   b^(a^a) = b^0 = b
   QED.

   Now You can cancel out same bits pairs regardless of their order in a series of ^ formula.

   Caution!

   inplace_swap(x, x)
   would be..

   *x = *x^*x = a^a = 0
   *x = 0^0 = 0
   *x = 0^0 = 0.
   which only results in 0 whatever the value of *x was.
*/
