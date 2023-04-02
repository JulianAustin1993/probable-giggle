#include <stdio.h>

/* Copy the input to output, replacing each string of one or more blanks .*/
int main(void)
{
    int c;
    printf("Type and Press Enter. CTRL-D for EOF:\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            while ((c = getchar()) == ' ')
                ;
            putchar(' ');
            if (c == EOF)
                break;
        }
        putchar(c);
    }
}