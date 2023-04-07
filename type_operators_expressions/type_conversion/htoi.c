#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);
int islowerhex(char c);

int main(void)
{
    char s[] = "0xA2";
    printf("%s:\t%d\n", s, htoi(s));
}

/*Conver string hexadeicmal to integer.*/
int htoi(char s[])
{
    int i, n;
    char c;
    n = 0;
    i = 0;
    if (s[0] == '0' && (tolower(s[1])) == 'x')
    {
        i = i + 2;
    }
    while (s[i] != '\0')
    {
        c = tolower(s[i]);
        if (!(islowerhex(c)))
        {
            n = 0;
            break;
        }
        else if (isdigit(c))
            n = n * 16 + c - '0';
        else
            n = n * 16 + 10 + c - 'a';
        ++i;
    }
    return n;
}

int islowerhex(char x)
{
    return (isdigit(x) || x >= 'a' && x <= 'f');
}