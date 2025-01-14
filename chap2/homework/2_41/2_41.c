/*
   For a run of ones starting at bit position n down to bit position m
   (n >= m), we saw that we can generate 2 forms of code, A and B(p.139)
   How should the compiler decide which form to use?

	ans: For consecutive 1's, say, 11111 (n-m+1),
	in the form A, generally
	n-m+1 shifts, n-m addition 
	in the form B, generally
	2 shifts, 1 subtraction (when n > m)
	2(n - m) + 1 versus 3 (n >m), when n - m <= 1
	both sides are equal. n - m >= 2, Form B takes 
	advantages over from A.

	We can divide bit patterns to a couple of bit chunks
	in the criterion of consecutive ones or zeros:

	1110001001101011111000 -> (111)000(1)00(11)0(1)0(11111)000
	For each chunk, selection btw the form A and B affects on the number
	of operation independently.
*/

	
	
	
