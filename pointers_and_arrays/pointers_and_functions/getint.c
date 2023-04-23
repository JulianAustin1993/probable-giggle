#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *);

char buf[BUFSIZE]; /*Buffer for ungetch.*/
int bufp = 0;      /*Next free position in buf.*/

/*getch: Get a (possible pushed back) character. */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*ungetch: Push a character back on input.*/
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error ungetch too many characters.\n");
    else
        buf[bufp++] = c;
}

/*getint: get next integer from input in *pm.*/
int getint(int *pm)
{
    int c, sign;
    while (isspace(c = getch())) /*skip whitespace.*/
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c))
        {
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    for (*pm = 0; isdigit(c); c = getch())
        *pm = 10 * *pm + (c - '0');
    *pm *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/*main entry point*/
int main(void)
{
    int max = 10;
    int i, num[max];
    int val;

    for (i = 0; i < max && (val = getint(&num[i])) != EOF; i++)
        printf("num[%d] = %d, \tvalue returned: %d (%s)\n", i, num[i],
               val, val != 0 ? "number" : "not a number");

    return 0;
}