/*
   You are given the task of patching the vulnerability in the XDR code
   shown in the aside on page 136 for the case where both data types int
   and size_t are 32 bits. You decide to eliminate the possibility of the
   multiplication overflowing by computing the number of bytes to allocate
   using data type uint64_t. You replace the original call to malloc as 
   follows:

	uint64_t asize = 
		ele_cnt * (uint64_t) ele_size;
	void *result = malloc(asize);

	Recall that the argument to malloc has type size_t.

	A. Does your code provide any improvement over the original?
	B. How would you change the code to eliminate the vulnerability?

*/

void *copy_elements(void *ele_src[]. int ele_cnt, size_t ele_size) {
	// B. There is no way to extend memory of the argument for malloc.
	// Insted, we can make an exception handling for the case of overflow.
	uint64_t required_size = (uint64_t) ele_cnt * ele_size;
	size_t request_size = (size_t) required_size;
	if (required_size != request_size)
		return NULL;

	void *result = malloc(ele_cnt * ele_size);

	if (result == NULL)
		return NULL;

	void *next = result;
	for (int i = 0; i < ele_cnt; i++) {
		memcpy(next, ele_src, ele_src[i], ele_size);
		next += ele_size;
	}

	return result;
}

/*
   A. No, even though asize is of uint64_t type, the argument type
   for malloc is size_t, which has 32-bit size. So when copied to
   the malloc argument, the asize should be truncated to 32-bit size,
   which causes overflow.
*/
