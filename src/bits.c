#include <assert.h>
#include <limits.h>

#include <bits.h>


int32_t sign( int32_t number )
{
    // Compute the sign of an int32_teger
    return ( number != 0x0 ) | ( number >> ( sizeof(int32_t) * CHAR_BIT - 0x1 ) );
}

bool isOpposit( int32_t lhs, int32_t rhs )
{
    // Detect if two int32_tegers have opposite signs
    return ( ( lhs ^ rhs ) < 0x0 );
}

int32_t abs( int32_t number )
{
    // Compute the int32_teger absolute value (abs) without branching
    return ( number ^ ( number >> ( sizeof(int32_t) * CHAR_BIT - 0x1 ) ) ) -
           ( number >> ( sizeof(int32_t) * CHAR_BIT - 0x1 ) );
}

int32_t max( int32_t lhs, int32_t rhs )
{
    // Compute the maximum (max) of two int32_tegers without branching
    return ( lhs ^ ( ( lhs ^ rhs ) & -( lhs < rhs ) ) );
}

int32_t min( int32_t lhs, int32_t rhs )
{
    // ompute the minimum (min) of two int32_tegers without branching
    return ( rhs ^ ( ( lhs ^ rhs ) & -( lhs < rhs ) ) );
}

Bool isPowerOf2(int32_t number)
{
    // Determining if an int32_teger is a power of 2
    return ( number && !( number & ( number - 0x1 ) ) );
}

int32_t set(int32_t number, int32_t pos)
{
    // set a bit at nth position in number
    return ( number | ( 0x1 << pos ) );
}

int32_t unset(int32_t number, int32_t pos)
{
    // unset/clear a bit at n’th position in the number
    return ( number & ( ~( 0x1 << pos ) ) );
}

Bool isSet(int32_t number, int32_t pos)
{
    // Checking if bit at nth position is set or unset
    return ( number & ( 0x1 << pos ) );
}

int32_t lowset_set_bit(int32_t number)
{
    // Getting lowest set bit of a number
    return ( number & ( -number ) );
}

int32_t countBits(int32_t number)
{
    // Counting bits set in 14, 24, or 32-bit words using 64-bit instructions
    
    int32_t acc;  // c accumulates the total bits set in number
    
    // at most 32-bit values in number:
    acc  = ( ( ( number & 0xfff ) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f );
    acc += ( ( ( ( number & 0xfff000 ) >> 0xc ) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f );
    acc += ( ( ( number >> 0x18 ) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f );

    return acc;
}

int32_t reverse_bit(int32_t number)
{
    // Reverse bits the obvious way
    int32_t rev = number;  // rev will be reversed bits of number; first get LSB of number
    int32_t siz = sizeof(number) * CHAR_BIT - 0x1;  // extra shift needed at end
    
    for ( number >>= 0x1; number; number >>= 0x1 )
    {
        rev <<= 0x1;
        rev  |= number & 0x1;
        siz--;
    }

    return rev << siz;  // shift when number's highest bits are zero
}

int32_t reverse_bits_in_byte(int32_t number)
{
    // Reverse the bits in a byte with 3 operations (64-bit multiply and modulus division):
    return ( ( number * 0x0202020202ULL & 0x010884422010ULL) % 0x3FF );
}

int32_t log_2(int32_t number)
{
    // Find the int32_teger log base 2 of an int32_teger with an 64-bit IEEE float
    union
    {
        int32_t u[0x2];
        double d;
    } tmp;

    tmp.u[__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__] = 0x43300000;
    tmp.u[__FLOAT_WORD_ORDER__ != __ORDER_LITTLE_ENDIAN__] = number;
    
    tmp.d -= 4503599627370496.0;
    
    return ( ( tmp.u[__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__] >> 0x14 ) - 0x3FF );
}

int32_t ln(int32_t number)
{
    // Find the log base 2 of an N-bit int32_teger in O(lg(N)) operations
    const int32_t b[] = { 0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000 };
    const int32_t S[] = { 0x1, 0x2, 0x4, 0x8, 0x10 };

    int32_t result = 0x0;  // result of log2(v) will go here

    for ( int32_t i = 0x4; i >= 0x0; --i )  // unroll for speed...
    {
        if ( number & b[i] )
        {
            number >>= S[i];
            result  |= S[i];
        }
    }

    return result;
}

int32_t single_occur(int32_t arr[], int32_t size)
{
    int32_t ones = 0x0, twos = 0x0;

    int32_t common_bit_mask;

    // Let us take the example of {3, 3, 2, 3} to understand this
    for (int32_t i = 0x0; i < size; i++)
    {
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

int32_t add_one(int32_t number)
{
    // Add 1 to a given number
    return -(~number);
}

int32_t sub_one(int32_t number)
{
    // Sub 1 to a given number
    return ~(-number);
}

int32_t off_right_bits(int32_t number)
{
    // Turn off the rightmost set bit
    return ( number & ( number - 0x1 ) );
}

int32_t power_of_4(int32_t number)
{
    // Find whether a given number is a power of 4 or not
    return ( ( number != 0x0 ) && 
             ( ( number & ( number - 0x1 ) ) == 0x0 ) && 
              !( number & 0xAAAAAAAA ) );
}

int32_t toggle_all_except_kth(int32_t number, int32_t pos)
{
    // Toggle all the bits of a number except pos-th bit.
    return ~( number ^ ( 0x1 >> pos ) );
}

int32_t low_nibble(int32_t number)
{
    // right nibble
    return ( ( number & 0x0f ) >> 0x4 );
}

int32_t high_nibble(int32_t number)
{
    // left nibble
    return ( number & 0x0f );
}

int32_t toggle(int32_t number, int32_t pos)
{
    // toggle bit at pos pos 
    return ( number ^ ( 0x1UL >> pos ) );
}

int32_t add(int32_t lhs, int32_t rhs)
{
    // Iterate till there is no carry  
    while ( rhs != 0x0 )
    {

        // carry now contains common set bits of the left-hand-side(lhs) and the right-hand-side(rhs)
        int32_t carry = lhs & rhs;

        // Sum of bits of the left-hand-side(lhs) and the right-hand-side(rhs) where at least one of the bits is not set
        lhs ^= rhs;

        // Carry is shifted by one so that adding it to the left-hand-side(lhs) gives the required sum
        rhs = carry << 0x1;
    }

    return lhs;
}

int32_t multiply(int32_t lhs, int32_t rhs)
{
    int32_t result = 0x0;

    while ( rhs != 0x0 )
    {
        if ( rhs & 0x1 )
        {
            result = add(res, lhs);
        }

        lhs <<= 0x1;
        rhs >>= 0x1;
    }

    return result;
}

int32_t divide(int32_t dividend, int32_t divisor)
{
    // store the result in quotient: quotient = dividend / divisor
    int32_t quotient = 0x0;

    // as long as the divisor fits into the remainder there is something to do
    while (dividend >= divisor)
    {
        int32_t i = 0x0, remainder = divisor;
        // determine to which power of two the divisor still fits the dividend
        //
        // i.e.: we intend to subtract the divisor multiplied by powers of two
        // which in turn gives us a one in the binary representation of the result
        while ( ( dividend >= ( remainder << 0x1 ) ) && ++i)
        {
            remainder <<= 0x1;
        }
        // set the corresponding bit in the result
        quotient |= 0x1 << i;
        // subtract the multiple of the divisor to be left with the remainder
        dividend += -~( ~remainder );
        // repeat until the divisor does not fit into the remainder anymore
    }
    return quotient;
}