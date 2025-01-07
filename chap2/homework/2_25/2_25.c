// Warning: This is buggy code.
float sum_element(float arr[], unsigned len) {
	int i;
	float result = 0;
	// Since the variable len is of type unsigned,
	// i should casted to unsigned.
	// when the len == 0, len - 1 is not -1,
	// actually it would be UINT_MAX
	// Clearly outindex the length of the given array.
	for (i = 0; i <= len - 1; i++) 
		result += arr[i];
	return result;
}

/*
   When run with argument len equal to 0, this code should
   return 0.0. Instead, it encountered a memory error.
   Explain why this happens. Show how this code can be
   corrected.
*/

float sum_element_revised(float arr[], unsigned len) {
	int i;
	float result = 0;
	for (i = 0; i < len; i++) 
		result += arr[i];
	return result;
}
