#include <stdio.h>
#define BUFSIZE 100

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