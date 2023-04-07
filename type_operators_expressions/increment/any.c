#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "hello";
    char s2[] = "world";
    printf("Position of first matching character: %d\n", any(s1, s2));
}

int any(char s1[], char s2[])
{
    int i, j;
    int pos = -1;
    for (i = 0; pos == -1 && s1[i] != '\0'; i++)
        for (j = 0; pos == -1 && s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                pos = i;
    return pos;
}
