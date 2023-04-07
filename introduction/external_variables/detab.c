#include <stdio.h>

#define TAB '\t'
#define SPACE ' '
#define TABSIZE 4

void detab(int n);
int calculate_spaces(int offset, int tabsize);

/*Print input with '\t' replaced by spaces.     Doe .*/
int main(void)
{
    int c;
    int pos;
    int n_spaces;

    pos = 0;
    while ((c = getchar()) != EOF)
    {
        ++pos;
        if (c == '\n')
            pos = 0;
        if (c == TAB)
        {
            n_spaces = calculate_spaces(pos, TABSIZE);
            detab(n_spaces);
        }
        else
            putchar(c);
    }
}

int calculate_spaces(int offset, int tabsize)
{
    return tabsize - (offset % tabsize);
}

void detab(int spaces)
{
    int i;
    for (i = 0; i < spaces; ++i)
        putchar(SPACE);
}
