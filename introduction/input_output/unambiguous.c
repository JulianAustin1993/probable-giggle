#include <stdio.h>

/* Copy the input to output, replacing each tab by \t.*/
int main(void)
{
    int c;
    printf("Type and Press Enter. CTRL-D for EOF:\n");
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
            continue;
        }
        putchar(c);
    }
}