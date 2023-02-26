#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> //manage meory (malloc, free etc.)
#include <ctype.h>

int main(void)
{
    // the same memory allocation for each string
    char *s = get_string("s: ");
    // in case something went wrong with wasting memory
    if(s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    // in case something went wrong with wasting memory
    if(t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // free memory you requested earlier
    free(t);

    return 0;
}