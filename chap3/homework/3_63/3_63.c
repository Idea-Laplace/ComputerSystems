long switch_prob(long x, long n) {
	long result = x;
	switch(n) {
	case 60: case 62:
		result *= 8;
		break;
	case 63:
		result >>= 3;
		break;
	case 64:
		x *= 15;
	case 65:
		x *= x;
	default:
		result = x + 75;
		break;
	}
	return result;
}


/*
   At first, we can identify that the case starts with
   60 from assembly code sub $0x3c, %rsi, which means n - 60.

   Second, number of case is 6 with reference to the assembly code
   cmp $0x5, %rsi and the following ja.
   Cases ranges from case 60 to case 65, correspoding to the number of
   elements in the jump table given.
   However, some of them could be falls into default.


   default code block is at 0x4005c3.
   result += 75; // 0x4b = 64 + 11 + 75.

   case 60: code at 4005a1
   case 61: code at 4005c3, default
   case 62: code at 4005a1, equivalent to case 60.
   case 63: code at 4005aa.
   case 64: code at 4005b2.
   case 65: code at 4005bf

   When we align cases with respect to their code address, then:

   case 60:
   case 62:
   case 63:
   case 64:
   case 65:

   Well, they were in order already though.
   Following the assembly code, we see that 
   from case 64 to default, we find the cases are fall through.
*/

   

