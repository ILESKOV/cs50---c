#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    // pointer to integer c is a pointer to a;
    int *c = &a;

    // go to the c value and assign it to 14. Point to the same value as a, so a will be changed also;
    *c = 14;
    // value of c pointer should be changed from a to b pointer '0x8fd7...'
    c = &b;
    // go to the c value and assign it to 14. c value now points to b, so b is changed to 25;
    *c = 25
}
