## C Bitwise-operation

> A curated list of awesome bitwise operations and tricks

## Purpose
Manipulating data at the bit level.

## Test

Dectect the sign of number
```c
//  ...
#include <bits.h>

int main()
{
    printf(" sign of (52) ->  %d\xa sign of (-2) -> %d\xa", sign(52), sign(-2));
    //  sign of (52) ->  1
    //  sign of (-2) -> -1
}
```

detecte if to num have opposit sit
```c
// ...
#include <bits.h>

int main()
{
    printf(" is (32) and (-48) have opposit sign -> %s\xa", isOpposit(32, -48) ? "True" : "False");
    //  is (32) and (-48) have opposit sign -> True
    printf(" is (55) and ( 89) have opposit sign -> %s\xa", isOpposit(55, 86) ? "True" : "False");
    //  is (55) and (89) have  opposit sign  -> False
}
```

absolute value of number
```c
//  ...
#include <bits.h>
int main()
{
    printf(" absolute value of |21|  -> %d\xa", abs(21));
    //  absolute value of |21|  -> 21
    printf(" absolute value of |-47| -> %d\xa", abs(-47));
    //  absolute value of |-47| -> 47
}
```

calculate max/min of two integer without branching
```c
//  ...
#include <bits.h>

int main()
{
    printf(" max btw (874) and (968) -> %d\xa", max(874, 968));
    //  max btw (874) and (968) -> 968
    printf(" max btw (874) and (968) -> %d\xa", min(874, 968));
    //  min btw (874) and (968) -> 874
}
```

detect if an integer is power of 2
```c
//  ...
#include <bits.h>

int main()
{
    printf(" is (8) power of 2 -> %s\xa", isPowerOf2(8) ? "True" : "False");
    //  is (8) power of 2 -> True
    printf(" is (9) power of 2 -> %s\xa", isPowerOf2(9) ? "True" : "False");
    //  is (9) power of 2 -> False
}
```


set bit at nth pos
```c
//  ...
#include <bits.h>

int main()
{
    printf(" 0b1010  (10) -> 0b1110  (%d)\xa", set(0b1010, 2));
    //  0b1010  (10) -> 0b1110  (14)
    printf(" 0b11001 (25) -> 0b11001 (%d)\xa", set(0b11001, 3));
    //  0b11001 (25) -> 0b11001 (25)
}
```


unset bit at nth pos
```c
//  ...
#include <bits.h>

int main()
{
    printf(" 0b1110  (14) -> 0b1010  (%d)\xa", unset(0b1110, 2));
    //  0b1110  (14) -> 0b1010  (10)
    printf(" 0b11001 (25) -> 0b11001 (%d)\xa", unset(0b11001, 2));
    //  0b11001 (25) -> 0b11001 (25)
}
```

detecte if bit at nth pos is set / unset
```c
//  ...
#include <bits.h>

int main()
{
    printf(" 0b1010  (10) ->  %s\xa", isSet(0b1010, 2) ? "True" : "False");
    //  0b1010  (10) ->  False
    printf(" 0b11001 (25) ->  %s\xa", isSet(0b11001, 3) ? "True" : "False");
    //  0b11001 (25) ->  True
}
```


count bit set of an integer
```c
//  ...
#include <bits.h>

int main()
{
    printf(" bits set in 0b1101101 (109) -> %d\xa", countBits(0b1101101));
    //  bits set in 0b1101101 (109) -> 5
}
```


perform addition, multiplication and division using bits operator
```c
// ...
#include <bits.h>

int main()
{
    printf(" 155 + 376 = %d\n", add(155, 376));
    //  155 + 376 = 531
    printf(" 58 * 96 = %d\n", multiply(158, 976));
    //  58 * 96 = 154208
    printf(" 89 / 3 = %d\n", divide(89, 3));
    //  89 / 3 = 29
}
```
