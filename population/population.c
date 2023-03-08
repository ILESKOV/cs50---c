#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);


    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    int years = 0;
    int compounder = start_size;

    if (start_size != end_size)
    {
        // TODO: Calculate number of years until we reach threshold
        do
        {
            compounder = compounder + (compounder / 3) - (compounder / 4);
            years++;
        }
        while (compounder < end_size);
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
