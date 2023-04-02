#include <stdio.h>

/* Count lines, tabs, and blanks in input.*/
int main(void)
{
    int c, nl, nb, nt;
    nl = 0;
    nb = 0;
    nt = 0;
    printf("Type and Press Enter. CTRL-D for EOF:\n");
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
    }

    printf("Num of new lines: %d\n", nl);
    printf("Num of tabs: %d\n", nl);
    printf("Num of blanks: %d\n", nb);
}