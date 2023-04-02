#include <stdio.h>

#define LOWER 0   /* lower limiit of temperature table. */
#define UPPER 300 /* Upper limit of temperature table. */
#define STEP 20   /* Step size*/

float fahr_to_cels(float f);

/* prints Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version.
Using function for conversion.*/
int main(void)
{
    float fahr, celsius;

    printf("%3s|%7s\n", "F", "C");
    printf("===========\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3.0f|%6.1f\n", fahr, fahr_to_cels(fahr));
}

/* fahr_to_cels: Convert Fahrenheit to Celcius*/
float fahr_to_cels(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
