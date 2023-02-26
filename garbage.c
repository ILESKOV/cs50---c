#include <stdio.h>
#include <stdlib.h> //manage meory (malloc, free etc.)

// everything seems good, there are no errors messages. But better use valgrind to identify memory bugs 'valgrind ./memory'
int main(void)
{
    // did not initialized any variable. I will see 'garbage' values in that case from computer memory
    // random positive and negatives values from memory, because just requestiong 1024 of memory;
    int scores[1024];
    for(int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}