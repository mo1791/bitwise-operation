#include <stdint.h>
#include <stdbool.h>

typedef enum { False = 0, True = 1 } Bool;

// Compute the sign of an int32_teger
int32_t sign(int32_t);

// Detect if two int32_tegers have opposite signs
bool isOpposit(int32_t, int32_t);

// Compute the int32_teger absolute value (abs) without branching
int32_t abs(int32_t);

// Compute the maximum (max) of two int32_tegers without branching
int32_t max(int32_t, int32_t);

// ompute the minimum (min) of two int32_tegers without branching
int32_t min(int32_t, int32_t);

// Determining if an int32_teger is a power of 2
Bool isPowerOf2(int32_t);

// set a bit at nth position in number
int32_t set(int32_t, int32_t);

// unset/clear a bit at n’th position in the number
int32_t unset(int32_t, int32_t);

// Checking if bit at nth position is set or unset
Bool isSet(int32_t, int32_t);

// Getting lowest set bit of a number
int32_t lowset_set_bit(int32_t);

// Counting bits set in 14, 24, or 32-bit words using 64-bit instructions
int32_t countBits(int32_t);

// Reverse bits the obvious way
int32_t reverse_bit(int32_t);

// Reverse the bits in a byte with 3 operations (64-bit multiply and modulus
// division):
int32_t reverse_bits_in_byte(int32_t);

// Find the int32_teger log base 2 of an int32_teger with an 64-bit IEEE float
int32_t log_2(int32_t);

// Find the log base 2 of an N-bit int32_teger in O(lg(N)) operations
int32_t ln(int32_t);

int32_t single_occur(int32_t[], int32_t);

// Add 1 to a given number
int32_t add_one(int32_t);

// Sub 1 to a given number
int32_t sub_one(int32_t);

// Turn off the rightmost set bit
int32_t off_right_bits(int32_t);

// Find whether a given number is a power of 4 or not
int32_t power_of_4(int32_t);

// Toggle all the bits of a number except k-th bit.
int32_t toggle_all_except_kth(int32_t, int32_t);

// right nibble
int32_t low_nibble(int32_t);

// left nibble
int32_t high_nibble(int32_t);

// toggle bit
int32_t toggle(int32_t /* number */, int32_t /* position */);

// add tow number using bitwise op
int32_t add(int32_t, int32_t);

// multiply tow number using bitwise op
int32_t multiply(int32_t, int32_t);

// devide tow number using bitwise op
int32_t divide(int32_t, int32_t);