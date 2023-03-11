#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    float factor = atof(argv[3]);
    if (factor < 0.0)
    {
        printf("Factor must be non-negative.\n");
        return 1;
    }

    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        printf("Could not open %s.\n", input_filename);
        return 1;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL)
    {
        fclose(input_file);
        printf("Could not create %s.\n", output_filename);
        return 1;
    }

    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input_file);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output_file);

    // Read samples from input file and write updated data to output file
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input_file))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);
}
