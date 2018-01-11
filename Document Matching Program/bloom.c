<<<<<<< HEAD

/***********************************************************
 File Name: bloom.c
 Description: implementation of bloom filter goes here 
 **********************************************************/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "bloom.h"

/* Constants for bloom filter implementation */
const int H1PRIME = 4189793;
const int H2PRIME = 3296731;
const int BLOOM_HASH_NUM = 10;

/* The hash function used by the bloom filter */
int
hash_i(int i, /* which of the BLOOM_HASH_NUM hashes to use */ 
       long long x /* the element (a RK value) to be hashed */)
{
	return ((x % H1PRIME) + i*(x % H2PRIME) + 1 + i*i);
}

/* Initialize a bloom filter by allocating a character array that can pack bsz bits.
   Furthermore, clear all bits for the allocated character array. 
   Each char should contain 8 bits of the array.
   Hint:  use the malloc and memset library function 
	 Return value is the allocated character array.*/
bloom_filter
bloom_init(int bsz /* size of bitmap to allocate in bits*/ )
{
	bloom_filter f;

	assert((bsz % 8) == 0);
	f.bsz = bsz;

	/* your code here*/
	return f;
}

/* Add elm into the given bloom filter 
 * We use a specific bit-ordering convention for the bloom filter implemention.
   Specifically, you are expected to use the character array in big-endian format. As an example,
   To set the 9-th bit of the bitmap to be "1", you should set the left-most
   bit of the second character in the character array to be "1".
*/
void
bloom_add(bloom_filter f,
	long long elm /* the element to be added (a RK hash value) */)
{
	/* Your code here */
}

/* Query if elm is a probably in the given bloom filter */ 
int
bloom_query(bloom_filter f,
	long long elm /* the query element (a RK hash value) */ )
{

	/* Your code here */
	return 0;
}

void 
bloom_free(bloom_filter *f)
{
	free(f->buf);
	f->buf = (char *)0;
       	f->bsz = 0;
}


/* print out the first count bits in the bloom filter, 
 * where count is the given function argument */
void
bloom_print(bloom_filter f,
            int count     /* number of bits to display*/ )
{
	assert(count % 8 == 0);
	for(int i=0; i< (f.bsz>>3) && i < (count>>3); i++) {
		printf("%02x ", (unsigned char)(f.buf[i]));
	}
	printf("\n");
	return;
}
=======

/***********************************************************
 File Name: bloom.c
 Description: implementation of bloom filter goes here 
 **********************************************************/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "bloom.h"

/* Constants for bloom filter implementation */
const int H1PRIME = 4189793;
const int H2PRIME = 3296731;
const int BLOOM_HASH_NUM = 10;

/* The hash function used by the bloom filter */
int
hash_i(int i, /* which of the BLOOM_HASH_NUM hashes to use */ 
       long long x /* the element (a RK value) to be hashed */)
{
	return ((x % H1PRIME) + i*(x % H2PRIME) + 1 + i*i);
}

/* Initialize a bloom filter by allocating a character array that can pack bsz bits.
   Furthermore, clear all bits for the allocated character array. 
   Each char should contain 8 bits of the array.
   Hint:  use the malloc and memset library function 
	 Return value is the allocated character array.*/
bloom_filter
bloom_init(int bsz /* size of bitmap to allocate in bits*/ )
{
	bloom_filter f;

	assert((bsz % 8) == 0);
	f.bsz = bsz;

	// gets size needed for memory allocation
	int size = (bsz >> 2) + (bsz % 8 ? 0 : 1);
	// sets required memory buffer
	f.buf = (char*) malloc(size);
	// sets all bits in f.buf to 0 for size-bits
	memset(f.buf, 0, size);
	// finished
	return f;
}

/* Add elm into the given bloom filter 
 * We use a specific bit-ordering convention for the bloom filter implemention.
   Specifically, you are expected to use the character array in big-endian format. As an example,
   To set the 9-th bit of the bitmap to be "1", you should set the left-most
   bit of the second character in the character array to be "1".
*/
void
bloom_add(bloom_filter f,
	long long elm /* the element to be added (a RK hash value) */)
{
	//  printf("%lld position", elm);
	int j, position; 

	// iterates from 0 to 10 and updates the bits of f.buf
	for (j = 0; j < BLOOM_HASH_NUM; j++){
		int rk_hash_val = hash_i(j,elm);
		position = rk_hash_val % f.bsz;
		// sets the value of the bit to f.buf
		f.buf[position / 8] |= 1 << (7 - position % 8);
	}
	return 0;
}

/* Query if elm is a probably in the given bloom filter */ 
int
bloom_query(bloom_filter f,
	long long elm /* the query element (a RK hash value) */ )
{ 
	int j, position;
	for (j = 0; j < BLOOM_HASH_NUM; j++){	
		int rk_hash_val = hash_i(j,elm);
		position = rk_hash_val % f.bsz;
		// checks to see if the elm bit is equal to the f.buf[position] bit
		if (! (f.buf[position / 8] & (1 << (7 - position % 8)))){
			//printf("mismatch");
			return 0;
		}
	}
	return 1;
}




void 
bloom_free(bloom_filter *f)
{
	free(f->buf);
	f->buf = (char *)0;
       	f->bsz = 0;
}


/* print out the first count bits in the bloom filter, 
 * where count is the given function argument */
void
bloom_print(bloom_filter f,
            int count     /* number of bits to display*/ )
{
	assert(count % 8 == 0);
	for(int i=0; i< (f.bsz>>3) && i < (count>>3); i++) {
		printf("%02x ", (unsigned char)(f.buf[i]));
	}
	printf("\n");
	return;
}
>>>>>>> 8ac63c23874f4d26d0a9189c6729305a7cf7953b
