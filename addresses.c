#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // pointers to int
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

    // C does not know string keyword
    char *s = "HI!";
    printf("%p\n", s);
    printf("%s\n", s);
    printf("%c\n", *s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}