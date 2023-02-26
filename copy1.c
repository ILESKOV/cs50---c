#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> //manage meory (malloc, free etc.)
#include <ctype.h>

int main(void)
{
    // the same memory allocation for each string
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n < strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}