#include <stdio.h>

#define LOWER 0   /* lower limiit of temperature table. */
#define UPPER 300 /* Upper limit of temperature table. */
#define STEP 20   /* Step size*/

/* prints Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version.*/
int main(void)
{
    float fahr, celsius;

    printf("%3s|%7s\n", "F", "C");
    printf("===========\n");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%3.0f|%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}