#include <stdio.h>

#define IN 1       /* Inside a word.*/
#define OUT 0      /* Outside a word.*/
#define MAXWORD 10 /*Maximum word size.*/

/* Count length of words and print horizontal histogram of them.*/
int main(void)
{
    int c, i, j, wl, state;
    int nlength[MAXWORD];
    state = OUT;
    wl = 0;

    for (i = 0; i < MAXWORD; ++i)
        nlength[i] = 0;
    printf("Type and Press Enter. CTRL-D for EOF:\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (wl > 0 && wl < MAXWORD)
                ++nlength[wl - 1];
            else if (wl >= MAXWORD)
                ++nlength[MAXWORD - 1];
            wl = 0;
        }
        else if (state == OUT)
        {
            state = IN;
        }

        if (state == IN)
            ++wl;
    }

    /*Print histogram to console.*/
    printf("Word lengths histogram:\n");
    for (i = 0; i < MAXWORD; i++)
    {
        if (i + 1 != MAXWORD)
            printf("%d\t", i + 1);
        else
            printf(">=%d\t", i + 1);
        for (j = 0; j <= nlength[i]; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
}
