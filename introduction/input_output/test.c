#include <stdio.h>

/* Check whether a character compared to EOF is and then print the value of EOF. */
int main(void)
{
    printf("getchar() != EOF is:\t%d\n", getchar() != EOF);
    printf("EOF value is:\t%d\n", EOF);
}