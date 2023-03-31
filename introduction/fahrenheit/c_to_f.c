#include <stdio.h>

/* prints Celsius - Fahrenheit table for celsius = 0, 20, ..., 300; floating-point version.*/
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limiit of temperature table. */
    upper = 300; /* Upper limit of temperature table. */
    step = 20;   /* Step size. */

    printf("%3s|%7s\n", "C", "F");
    printf("===========\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (celsius + 32.0) * (9.0 / 5.0);
        printf("%3.0f|%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}