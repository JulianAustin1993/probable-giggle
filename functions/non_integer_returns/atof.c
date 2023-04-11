#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void)
{
    char s[] = "123.45e-6";
    printf("The number to place as a double is: %s\n", s);
    printf("The number as a double is: %.9f\n", atof(s));
}

double atof(char s[])
{
    double val, power, exp_power, exp_val;
    int i, sign, exp_sign;

    for (i = 0; isspace(s[i]); i++) /*Skip white space*/
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e')
        i++;
    exp_sign = (s[i] == '-') ? 0 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exp_val = 0.0; isdigit(s[i]); i++)
    {
        printf("%d;", s[i] - '0');
        exp_val = 10 * exp_val + (s[i] - '0');
    }
    printf("Exp val; %f", exp_val);
    exp_power = 1.0;
    while (exp_val > 0)
    {
        exp_power *= 10;
        exp_val--;
    }

    if (exp_sign)
    {
        power /= exp_power;
    }
    else
        power *= exp_power;
    printf("%d;", sign);
    printf("%f;", val);
    printf("%f\n", power);
    return sign * val / power;
}