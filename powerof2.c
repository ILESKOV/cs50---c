#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Provide the size of array: ");
    }
    while ( n < 1);

    int powerof2[n];
    powerof2[0] = 1;

    for( int i = 1; i <= n; i++)
    {
        powerof2[i] = 2 * powerof2[i - 1];
        printf("%i\n",powerof2[i]);
    }
}

