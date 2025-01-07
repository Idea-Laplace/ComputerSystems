#include <stdio.h>
#include <limits.h>


int main(void) {
	printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);

	printf("%s\n", -2147483647 - 1 == 2147483648U ? "True" : "False"); // 2147483648U == 2147483648U True;
	printf("%s\n", -2147483647 - 1 < 2147483647 ? "True" : "False");   // -21474836248 < 2147483647  True;
	printf("%s\n", -2147483647 - 1U < 2147483648U ? "True" : "False"); // 2147483649U - 1U < 2147483648U False;
	printf("%s\n", -2147483647 - 1 < -2147483647 ? "True" : "False");  // -2147483648 < -2147483647 True;
	printf("%s\n", -2147483647 - 1U < -2147483647 ? "True" : "False");  // 2147483648U < 2147483649U True;

	return 0;
}

