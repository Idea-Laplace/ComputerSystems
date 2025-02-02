short loop_while(short a, short b) {
	short result = 0;
	while (a > b) {
		result = result + a * b ;  // Or just result += a * b;
		a = a - 1;  			   // Or just a -= 1;
	}

	return result;
}


