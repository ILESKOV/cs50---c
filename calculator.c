#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    printf("%li\n", x+y);

    float z = (float) x / (float) y;
    printf("%f\n", z);

    // float imprecision
    printf("%.20f\n", z);

    // more precision but still not ideal
    double b = (double) x / (double) y;
    printf("%.20f\n", b);
}

