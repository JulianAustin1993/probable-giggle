#include <stdio.h>

int binsearch(int x, int v[], int n);

#define MAX_ELEMENT 20000

/*test*/
int main(void)
{
    int v[MAX_ELEMENT], i;

    for (i = 0; i < MAX_ELEMENT; i++)
        v[i] = i;

    int x = 15021;
    int occurance = binsearch(x, v, MAX_ELEMENT);
    occurance > 0 ? printf("%d occurs in the array at position %d\n", x, occurance) : printf("%d doesn't occur in the array!\n", x);
}

/*  Performs a binary search for element x
        in array v[], which has n elements      */

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    return (x == v[mid] ? mid : -1);
}