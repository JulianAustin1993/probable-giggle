#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line size.*/

void escape(char s[], char t[]);

/*Copys s to t and replace escaped characters to be visible.*/
void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    char c;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '\t':
            t[j++] = '\\';
            t[j] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j] = 'n';
            break;
        default:
            t[j] = s[i];
        }
        j++;
        i++;
    }
    t[j] = '\0';
}

/*test the function*/
int main(void)
{
    char s[] = "Hello\nWorld.\tIts me!";
    char t[MAXLINE];
    escape(s, t);
    printf("Initial line:\n%s\n", s);
    printf("Transformed:\n%s\n", t);
}