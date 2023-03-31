#include <stdio.h>

/* prints Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version.*/
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limiit of temperature table. */
    upper = 300; /* Upper limit of temperature table. */
    step = 20;   /* Step size. */

    printf("%3s|%7s\n", "F", "C");
    printf("===========\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f|%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}