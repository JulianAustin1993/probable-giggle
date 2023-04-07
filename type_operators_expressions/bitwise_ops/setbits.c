#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

/* Enty point to run an example.*/
int main(void)
{
    int x = 9713; // 0010 0101 1111 0001
    int y = 3500; // 0000 1101 1010 1100
    int p = 11;
    int n = 4;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("Setting the %d bits that begin at postion %d in x\n", n, p);
    printf("to the right most %d bits of y:\n\n", n);
    printf("Result is: %u\n", setbits(x, p, n, y));
}

/* Return x with the n bits that begin at position  p set to the right most n bits of y*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // logic: p = 11, n = 4
    // 0010 0101 1111 0001 x
    // 0000 1101 1010 1100 y
    int shift = p - n + 1;
    int mask = ~(~0 << n) << shift; // 0000 1111 0000 0000
    x &= ~mask;                     // 0010 0000 1111 0001
    y = getbits(y, n - 1, n);       // 0000 0000 0000 1100 n right most of y
    y <<= shift;                    // 0000 1100 0000 0000
    return x | y;                   // 0010 1100 1111 0001 (0010 1100 1111 0001 - 11505)
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    // logic: p = 11, n = 4
    // 0 is right most position.
    // 0000 1101 1010 1100 x
    unsigned shift_right = (x >> (p + 1 - n)); // 0000 0000 0000 1101
    unsigned left_bits = ~(~0 << n);           // 0000 0000 0000 1111
    return shift_right & left_bits;            // 0000 0000 0000 1101
}