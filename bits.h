#pragma once

#if defined _GNUC_
	#define NODISCARD __attribute__((warn_unused_result))
	#define ALWAYS_INLINE __attribute__((always_inline)) inline
	#define MAYBE_UNUSED __attribute__((unused))
#else
	#define NODISCARD
	#define ALWAYS_INLINE inline
	#define MAYBE_UNUSED
#endif

NODISCARD uint32_t toggle(uint32_t, uint32_t);

NODISCARD uint32_t add(uint32_t, uint32_t);

uint32_t multiply(uint32_t, uint32_t);

uint32_t divide(uint32_t, uint32_t);

// Compute the sign of an uint32_teger
NODISCARD uint32_t sign(uint32_t);

// Detect if two uint32_tegers have opposite signs
NODISCARD uint32_t isOpposit(uint32_t, uint32_t);

// Compute the uint32_teger absolute value (abs) without branching
NODISCARD uint32_t abs(uint32_t);

// Compute the maximum (max) of two uint32_tegers without branching
NODISCARD uint32_t max(uint32_t, uint32_t);

// ompute the minimum (min) of two uint32_tegers without branching
NODISCARD uint32_t min(uint32_t, uint32_t);

// Determining if an uint32_teger is a power of 2
NODISCARD bool isPowerOf2(uint32_t)

// set a bit at nth position in number 
NODISCARD uint32_t set(uint32_t, uint32_t);

// unset/clear a bit at n’th position in the number
NODISCARD uint32_t unset(uint32_t , uint32_t);


// Checking if bit at nth position is set or unset
NODISCARD bool isSet(uint32_t, uint32_t);

// Getting lowest set bit of a number
NODISCARD uint32_t lowset_set_bit(uint32_t);


// Counting bits set in 14, 24, or 32-bit words using 64-bit instructions
NODISCARD uint32_t countBits(uint32_t);


// Reverse bits the obvious way
NODISCARD uint32_t reverse_bit(uint32_t);

// Reverse the bits in a byte with 3 operations (64-bit multiply and modulus division):
NODISCARD uint32_t reverse_bits_in_byte(uint32_t);

// Find the uint32_teger log base 2 of an uint32_teger with an 64-bit IEEE float
NODISCARD uint32_t log_2(uint32_t);


// Find the log base 2 of an N-bit uint32_teger in O(lg(N)) operations
NODISCARD uint32_t ln(uint32_t);


NODISCARD uint32_t single_occur(uint32_t[], uint32_t);

// Add 1 to a given number
NODISCARD uint32_t add_one(uint32_t);

// Turn off the rightmost set bit
NODISCARD uint32_t off_right_bits(uint32_t);

// Find whether a given number is a power of 4 or not
NODISCARD uint32_t power_of_4(uint32_t);

// Toggle all the bits of a number except k-th bit.
NODISCARD uint32_t toggle_all_except_kth(uint32_t , uint32_t);

// right nibble
NODISCARD uint32_t low_nibble(uint32_t);

// left nibble
NODISCARD uint32_t high_nibble(uint32_t);

NODISCARD uint32_t concate(uint32_t, uint32_t);