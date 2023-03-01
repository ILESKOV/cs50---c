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
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    free(list);
    // now my list with value of 3 bytes pointer should point to 4 bytes
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // not the same as in line 32
    free(list);
    // free(tmp) will work as well but bad designed
}

