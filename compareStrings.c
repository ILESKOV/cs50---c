#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    string x = get_string("x: ");
    string y = get_string("y: ");

    if (*x == *y && *(x+1) == *(y+1) && *(x+2) == *(y+2))
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    string o = get_string("o: ");
    string e = get_string("e: ");

    printf("%p\n", o);
    printf("%p\n", e);
}