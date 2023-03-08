#include <stdio.h>

int main()
{
    int height;
    // Prompt the height of grid
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    // build grids
    for (int i = 1; i <= height; i++)
    {
        // Build empty space for each line
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        // Build grid on left side
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        // Build grid on right side
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
