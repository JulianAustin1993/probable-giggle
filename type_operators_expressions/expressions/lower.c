#include <stdio.h>

char lower(char c);

char lower(char c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

/*test lower*/
int main(void)
{
    char c = 'B';
    printf("The character %c to lower is: %c\n", c, lower(c));
    c = 'x';
    printf("The character %c to lower is: %c\n", c, lower(c));
}