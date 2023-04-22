#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /*Maximum depth of cal stack.*/

int sp = 0;         /*Next value from stack position.*/
double val[MAXVAL]; /*value stack*/

/*push: Push f onto value stack.*/
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g.\n", f);
}

/*pop: Pop last value from value stack.*/
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty.\n");
        return 0.0;
    }
}
