// linux> gcc -0g -S mstore.c
long mult2(long, long);

void multstore(long x, long y, long *dest) {
	long t = mult2(x, y);
	// The value of t will be stored in the address dest.
	*dest = t;
}


/*
   A key lesson to learn from this is that the program executed
   by the machine is simply a sequence of bytes encoding a series
   of instructions. The machine has very little information about
   the source code from which these instructions were generated.

   To inspect the contents of machine code files, a class of programs
   known as disassemblers can be invaluable, These programs generate a
   format similar to assembly code from the machine code. With Linux
   systems, the program objdump can serve this role given the -d command
   -line flag.

   linux> objdump -d mstore.o
*/
