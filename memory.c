#include <stdio.h>
#include <stdlib.h> //manage meory (malloc, free etc.)

// everything seems good, there are no errors messages. But better use valgrind to identify memory bugs 'valgrind ./memory'
int main(void)
{
    int *x = malloc(3 * sizeof(int)); // the same as 'int x[3]'
    // if(x == NULL)
    // {
    //     return 1;
    // }
    x[1] = 72;   // x[0] = 72;
    x[2] = 73;   // x[1] = 73;
    x[3] = 33;   // x[2] = 33;

    // free(x);

    // return 0;
}