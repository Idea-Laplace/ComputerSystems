#include <stdio.h>

#define SIZE(arr) ((sizeof arr) / (sizeof arr[0]))

int main(void) {
	char str1[8] = "June 14"; // Just right.
	char str2[9] = "June 14"; // No harm, the array will be filled with null characters along the trailing empty spaces.
	char str3[7] = "June 14"; // There is no room for \0, but does not evoke error, but the array is not usuable as a string.
	//char str4[6] = "June 14"; // If a string initializer is longer than the array size, let alone the null character, error will rise.

	for (int i = 0; i < SIZE(str1); i++) {
		printf("%c", str1[i]);
		if (str1[i] == '\0')
			printf("\\0");
	}
	putchar('\n');

	for (int i = 0; i < SIZE(str2); i++) {
		printf("%c", str2[i]);
		if (str2[i] == '\0')
			printf("\\0");
	}
	putchar('\n');

	for (int i = 0; i < SIZE(str3); i++) {
		printf("%c", str3[i]);
		if (str3[i] == '\0')
			printf("\\0");
	}
	putchar('\n');

	/*
	for (int i = 0; i < SIZE(str4); i++) {
		printf("%c", str4[i]);
		if (str4[i] == '\0')
			printf("\\0");
	}
	putchar('\n');
	*/
	return 0;
}


