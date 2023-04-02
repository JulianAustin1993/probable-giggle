#include <stdio.h>

/*Print input one word per line. */
int main(void)
{
    int c;
    printf("Type and Press Enter. CTRL-D for EOF:\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
            putchar('\n');
        else
            putchar(c);
    }
}