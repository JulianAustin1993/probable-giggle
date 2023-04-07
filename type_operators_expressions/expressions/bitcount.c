#include <stdio.h>

int bitcount(unsigned x);

/*Count number of 1's in a byte.*/
int main(void)
{
    int x = 1111; // 0000 0100 0101 0111 - bitcount 6
    printf("The bit count of %d is %d\n", x, bitcount(x));
}

/*Count number of 1's in a byte.*/
int bitcount(unsigned x)
{
    int b = 0;
    while (x != 0)
    {
        x &= (x - 1);
        b++;
    }
    return b;
}