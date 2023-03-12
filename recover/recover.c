#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open forensic image
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Initialize variables
    unsigned char buffer[512];
    int count = 0;
    FILE *img = NULL;

    // Read file block by block
    while (fread(buffer, 512, 1, file))
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous image file
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new image file
            char filename[8];
            sprintf(filename, "%03d.jpg", count);
            img = fopen(filename, "w");
            count++;
        }

        // Write block to image file
        if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // Close last image file
    if (img != NULL)
    {
        fclose(img);
    }

    // Close file
    fclose(file);

    // Success
    return 0;
}