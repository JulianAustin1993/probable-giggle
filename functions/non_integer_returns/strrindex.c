#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line. */

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);
int reverse(char from[], char to[]);

char pattern[] = "ould"; /* Pattern to search for is ould. */

/*Find all lines matching pattern*/
int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int i;

    while (my_getline(line, MAXLINE))
        if ((i = strrindex(line, pattern)) >= 0)
        {
            printf("%d: %s", i, line);
            found++;
        }
    return found;
}

/* getline: get line into s, return length*/
int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && ((c = getchar()) != EOF) && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none*/
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strrindex: return right most index of t in s, -1 if none*/
int strrindex(char s[], char t[])
{
    char rev_s[MAXLINE];
    char rev_t[MAXLINE];
    int length = reverse(s, rev_s);
    int pattern_length = reverse(t, rev_t);
    int i = strindex(rev_s, rev_t);
    return i > 0 ? length - i - pattern_length : -1;
}

/*Reverse a character array.*/
int reverse(char s[], char t[])
{
    int length = 0;
    while (s[length] != '\0')
        length++;

    for (int j = length - 1; j >= 0; j--)
        t[length - 1 - j] = s[j];
    t[length] = '\0';
    return length;
}