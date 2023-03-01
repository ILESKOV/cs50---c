#include <stdio.h>
// for uint type
#include <stdint.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper usage\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exist
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    // Create buffer for storing first 4 bytes of file. For each pdf first 4 bytes the same: 37 80 68 70
    uint8_t buffer[4];
    fread(buffer, 1, 4, file);

    uint8_t pdfFirstFourBytes[4] = {37, 80, 68, 70};

    // Print the contents of the buffer
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // Iterate throw the buffer
    for (int i = 0; i < 4; i++)
    {
        if(pdfFirstFourBytes[i] != buffer[i])
        {
            printf("It is not a pdf file\n");
            fclose(file);
            return 0;
        }
    }
    printf("It is pdf file!\n");
    fclose(file);
    return 0;
}