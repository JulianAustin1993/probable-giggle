#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line size.*/
#define MINLENGTH 70

int my_getline(char line[], int maxline);

/* print line if length is greater than 80.*/
int main(void)
{
    int len;            /* Current line length.*/
    char line[MAXLINE]; /* Current input line.*/
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > MINLENGTH + 1)
        {
            printf("%d - ", len - 1);
            printf("%s\n", line);
        }
    return 0;
}

/* getline: read a line insto s, return length. Using equivalent loop */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1; ++i)
    {
        if ((c = getchar()) != EOF)
            if (c != '\n')
                s[i] = c;
            else
                break;
        else
            break;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
