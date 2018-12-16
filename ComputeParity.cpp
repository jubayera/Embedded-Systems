//Computing Parity
#include <stdio.h>

typedef unsigned long int uint64_t;

int main()
{
    uint64_t x = 14;

    printf("Value of X: %lld\n", (long long)x);

    //combine all bits at the LSB
    x ^= x >> 32; //XOR's first 32 bits with last 32 bits, stores in x
    x ^= x >> 16; //similarly
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    //now take the last bit
    x = x & 1;

    printf("Parity of X: %lld\n", (long long)x);

    return 0;
}
/*
Value of X: 14
Parity of X: 1
*/
