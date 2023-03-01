#include <stdio.h>
#include <stdlib.h> //manage memory (malloc, free etc.)

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // some complecated code

    //at some point I want to get more memory
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // now my list with value of 3 bytes pointer should point to 4 bytes
    list = tmp;

    list[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
}

// it is much better designed than list.c because realloc handle copying
// of values and in case if next required bytes are garbage vules it is not copying and just allocate new bytes