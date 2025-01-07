/* Problem 2.11
   Imagine you'd like to write a reversing array algorithm
   with the inplace_swap function you've written in the prob2.10.

   What an unexpected accident would arise, especially the number of
   elements in an array is odd? And why?

   void reverse_array(int *a, size_t len) {
       int first, last;
	   for (first = 0, last = len - 1;
	   		first <= last;
			first++, last--)
			inplace_swap(a + first, a + last);
	}

   What simple modification to the code for reverse_array would
   eliminate this problem?
*/

#include <stdio.h>
#define SIZE(arr) ((int) ((sizeof(arr)) / (sizeof(arr[0]))))

void inplace_swap(int *x, int *y);
void reverse_array(int *arr, size_t len);

int main(void) {
	int a[5] = {4, 7, 1, 9, 5};
	int b[6] = {4, 7, 1, 9, 5, 2};
	int i;

	printf("{");
	for (i = 0; i < SIZE(a); i++) {
		if (i != SIZE(a) - 1)
			printf("%d, ", a[i]);
		else
			printf("%d}\n", a[i]);
	}
	printf("{");
	for (i = 0; i < SIZE(b); i++) {
		if (i != SIZE(b) - 1)
			printf("%d, ", b[i]);
		else
			printf("%d}\n", b[i]);
	}

	reverse_array(a, SIZE(a));
	reverse_array(b, SIZE(b));
	
	printf("{");
	for (i = 0; i < SIZE(a); i++) {
		if (i != SIZE(a) - 1)
			printf("%d, ", a[i]);
		else
			printf("%d}\n", a[i]);
	}
	printf("{");
	for (i = 0; i < SIZE(b); i++) {
		if (i != SIZE(b) - 1)
			printf("%d, ", b[i]);
		else
			printf("%d}\n", b[i]);
	}

	return 0;
}


void inplace_swap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void reverse_array(int *a, size_t len) {
	int first, last;
	for (first = 0, last = len - 1;
		//first <= last;
		first < last; // Modification
		first++, last--)
		inplace_swap(a + first, a + last);
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
