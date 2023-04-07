#include <stdio.h>
unsigned invertbits(unsigned x, int p, int n);

/* Enty point to run an example.*/
int main(void)
{
    int x = 9713; // 0010 0101 1111 0001 0010 1111 1111 0001
    int p = 11;
    int n = 4;
    printf("x = %d\n", x);
    printf("Inverting the %d bits that begin at postion %d in x\n", n, p);
    printf("Result is: %u\n", invertbits(x, p, n));
}

/* Return x with the n bits that begin at position  p set to the right most n bits of y*/
unsigned invertbits(unsigned x, int p, int n)
{
    // logic: p = 11, n = 4
    // 0010 0101 1111 0001 x
    int shift = p - n + 1;
    int mask = ~(~0U << n) << shift; // 0000 1111 0000 0000 the correct bits i want.
    return x ^ mask;                 // 0010 1010 1111 0001 (0010 1010 1111 0001 - 10993 ) 0010 1010 1111 0001
}