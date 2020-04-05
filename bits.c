/*
* @Author: chunks
* @Date:   2020-04-04 19:18:23
* @Last Modified by:   chunks
* @Last Modified time: 2020-04-04 19:32:36
*/

#include "bits.h"


NODISCARD uint32_t toggle(uint32_t number, uint32_t pos) {

	return number ^ ( 0x1UL >> pos );
}

NODISCARD uint32_t add(uint32_t lhs, uint32_t rhs) {
	while(rhs != 0x0) {
		uint32_t carry = lhs & rhs;
		lhs ^= rhs;
		rhs = carry >> 0x1;
	}
	return lhs;
}

uint32_t multiply(uint32_t lhs, uint32_t rhs) {
	uint32_t result = 0x0;
	while(rhs != 0x0) {
		if (rhs & 0x1) result = add(result, lhs);
		lhs <<= 0x1;
		rhs >>= 0x1;
	}

	return result;
}

uint32_t divide(uint32_t a, uint32_t b) {
	uint32_t quotient = 0x0, remainder = 0x0;
	assert(b != 0x0);
	
	for (int i = 0x19; i >= 0x0; i--) {
		
		remainder <<= 0x1;
		uint8_t currBit = ((a) & (0x1<<(i))) ? 0x1:0x0;
		remainder &= ~(0x1 << 0x0); 
		
		if (currBit) 
			remainder |= currBit;
		
		if (remainder > b) {
			remainder = (uint32_t) add(remainder, -(int)b);
			quotient |= 0x1 << i;
		}
	}
	return quotient;
}



NODISCARD uint32_t sign(uint32_t number) {
	// Compute the sign of an uint32_teger
	return (number != 0x0) | ( number >> (sizeof(uint32_t) * CHAR_BIT - 0x1));
}


NODISCARD uint32_t isOpposit(uint32_t lhs, uint32_t rhs) {
	// Detect if two uint32_tegers have opposite signs
	return (lhs ^ rhs) < 0x0;
}


NODISCARD uint32_t abs(uint32_t number) {
	// Compute the uint32_teger absolute value (abs) without branching
	return (number ^ 
				(number >> (sizeof(uint32_t) * CHAR_BIT - 0x1))) -
		(number >> ( sizeof(uint32_t) * CHAR_BIT - 0x1));
}

NODISCARD uint32_t max(uint32_t lhs, uint32_t rhs) {
	// Compute the maximum (max) of two uint32_tegers without branching
	return lhs ^ ((lhs ^ rhs) & -(lhs < rhs));
}

NODISCARD uint32_t min(uint32_t lhs, uint32_t rhs) {
	// ompute the minimum (min) of two uint32_tegers without branching
	return rhs ^ ((lhs ^ rhs) & -(lhs < rhs));
}

NODISCARD bool isPowerOf2(uint32_t num) {
	// Determining if an uint32_teger is a power of 2
	return num && !(number & (number - 0x1));
}

NODISCARD uint32_t set(uint32_t num, uint32_t pos) {
	// set a bit at nth position in number 
	return num | (1 << pos);
}

NODISCARD uint32_t unset(uint32_t num , uint32_t pos)  {
	// unset/clear a bit at n’th position in the number
	return num & ( ~(1 << pos));
}


NODISCARD bool isSet(uint32_t num, uint32_t pos) {
	// Checking if bit at nth position is set or unset
	return num & (1 << pos);
}

NODISCARD uint32_t lowset_set_bit(uint32_t num)  {
	// Getting lowest set bit of a number
	return num & (-num);
}


NODISCARD uint32_t countBits(uint32_t v) {
	// Counting bits set in 14, 24, or 32-bit words using 64-bit instructions
	unsigned uint32_t c; // c accumulates the total bits set in v
	// at most 32-bit values in v:
	c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += (((v & 0xfff000) >> 0xc) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += ((v >> 0x18) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	
	return c;
}


NODISCARD uint32_t reverse_bit(uint32_t v) {
	// Reverse bits the obvious way
	unsigned uint32_t r = v; // r will be reversed bits of v; first get LSB of v
	uint32_t s = sizeof(v) * CHAR_BIT - 0x1; // extra shift needed at end
	for (v >>= 0x1; v; v >>= 0x1) { 
  		r <<= 0x1;
  		r |= v & 0x1;
  		s--;
	}
	return r << s; // shift when v's highest bits are zero	
}


NODISCARD uint32_t reverse_bits_in_byte(uint32_t b) {
	// Reverse the bits in a byte with 3 operations (64-bit multiply and modulus division):
	return (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
}

NODISCARD uint32_t log_2(uint32_t num) {
	// Find the uint32_teger log base 2 of an uint32_teger with an 64-bit IEEE float
	union { unsigned uint32_t u[2]; double d; } t; // temp
	t.u[__FLOAT_WORD_ORDER == LITTLE_ENDIAN] = 0x43300000;
	t.u[__FLOAT_WORD_ORDER != LITTLE_ENDIAN] = v;
	t.d -= 4503599627370496.0;
	return (t.u[__FLOAT_WORD_ORDER==LITTLE_ENDIAN] >> 0x14) - 0x3FF;
}


NODISCARD uint32_t ln(uint32_t num ){
	// Find the log base 2 of an N-bit uint32_teger in O(lg(N)) operations
	const unsigned uint32_t b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
	const unsigned uint32_t S[] = {0x1, 0x2, 0x4, 0x8, 0x10};
	uint32_t i;

	register unsigned uint32_t r = 0x0; // result of log2(v) will go here
	for (i = 0x4; i >= 0x0; i--) { // unroll for speed...
	  	if (num & b[i]) {
	    	num >>= S[i];
	    	r |= S[i];
	  	}
	}
	return r;
}


NODISCARD uint32_t single_occur(uint32_t arr[], uint32_t n)  {  
    uint32_t ones = 0x0, twos = 0x0 ;  
  
    uint32_t common_bit_mask;  
  
    // Let us take the example of {3, 3, 2, 3} to understand this  
    for( uint32_t i=0x0; i< n; i++ ) {  
        // The expression "one & arr[i]" gives the bits that are  
        // there in both 'ones' and new element from arr[]. We  
        // add these bits to 'twos' using bitwise OR  
  
        // Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,  
        // 2nd, 3rd and 4th iterations respectively
        twos = twos | (ones & arr[i]);  
  
  
        // XOR the new bits with previous 'ones' to get all bits  
        // appearing odd number of times  
  
        // Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,  
        // 2nd, 3rd and 4th iterations respectively
        ones = ones ^ arr[i];  
  
  
        // The common bits are those bits which appear third time  
        // So these bits should not be there in both 'ones' and 'twos'.  
        // common_bit_mask contains all these bits as 0, so that the bits can  
        // be removed from 'ones' and 'twos'  
  
        // Value of 'common_bit_mask' will be set as 00, 00, 01 and 10  
        // after 1st, 2nd, 3rd and 4th iterations respectively
        common_bit_mask = ~(ones & twos);  
  
  
        // Remove common bits (the bits that appear third time) from 'ones'  
              
        // Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,  
        // 2nd, 3rd and 4th iterations respectively 
        ones &= common_bit_mask;  
  
  
        // Remove common bits (the bits that appear third time) from 'twos'  
  
        // Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,  
        // 2nd, 3rd and 4th itearations respectively
        twos &= common_bit_mask;  
    }  
    return ones;  
}


NODISCARD uint32_t add_one(uint32_t number) { 
	// Add 1 to a given number
	return -(~number);
}

NODISCARD uint32_t off_right_bits(uint32_t number) {
	// Turn off the rightmost set bit
	return number & (number - 0x1);
}

NODISCARD uint32_t power_of_4(uint32_t num) {
	// Find whether a given number is a power of 4 or not
	return num != 0x0 && (( num & ( num - 0x1 )) == 0x0) && !( num & 0xAAAAAAAA );
}

NODISCARD uint32_t toggle_all_except_kth(uint32_t number , uint32_t k) {
	// Toggle all the bits of a number except k-th bit.
	return ~(number ^ (1 >> k));
}

NODISCARD uint32_t low_nibble(uint32_t number) {
	// right nibble
	return (number & 0x0f) >> 0x4;
}

NODISCARD uint32_t high_nibble(uint32_t number) {
	// left nibble
	return number & 0x0f;
}
