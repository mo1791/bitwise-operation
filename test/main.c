#include <bits.h>
#include <stdio.h>

int main() {
    puts("----------");
    // of numbers
    printf("sign of (52) ->  %d\xasign of (-2) -> %d\xa", sign(52), sign(-2));
    puts("----------");
    // detecte if to num have opposit sit
    printf(
        "is (32) and (-48) have opposit sign -> %s\xais (55) and (89) have "
        "opposit sign  -> %s\xa",
        isOpposit(32, -48) ? "True" : "False",
        isOpposit(55, 86) ? "True" : "False");
    puts("----------");
    // absolute value
    printf("absolute value of |21|  -> %d\nabsolute value of |-47| -> %d\xa",
           abs(21), abs(-47));
    puts("----------");
    // max of two int32 without branching
    printf("max btw (874) and (968) -> %d\xa", max(874, 968));
    puts("----------");
    // min of two int32 without branching
    printf("min btw (874) and (968) -> %d\xa", min(874, 968));
    puts("----------");
    // detect if int32 is power of 2
    printf("is (8) power of 2 -> %s\xais (9) power of 2 -> %s\xa",
           isPowerOf2(8) ? "True" : "False", isPowerOf2(9) ? "True" : "False");
    puts("----------");
    // set bit at nth pos
    printf("0b1010  (10) -> 0b1110  (%d)\xa", set(0b1010, 2));
    printf("0b11001 (25) -> 0b11001 (%d) // 3rd bit of 25 is already set \xa",
           set(0b11001, 3));
    puts("----------");
    // unset bit at nth pos
    printf("0b1110  (14) -> 0b1010  (%d)\xa", unset(0b1110, 2));
    printf(
        "0b11001 (25) -> 0b11001 (%d) // second bit of 25 is already set \xa",
        unset(0b11001, 2));
    puts("----------");
    // CHECK IF BIT AT NTH IS SET OR UNSET
    printf("0b1010  (10) ->  %s\xa", isSet(0b1010, 2) ? "True" : "False");
    printf("0b11001 (25) ->  %s\xa", isSet(0b11001, 3) ? "True" : "False");
    puts("----------");
    // count bit set in int32
    printf("bits set in 0b1101101 (109) -> %d\xa", countBits(0b1101101));
    puts("----------");
}