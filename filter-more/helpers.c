#include "helpers.h" // Include the header file for function prototypes
#include <math.h> // Include the math library for round() and sqrt()

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop through each row
    {
        for (int j = 0; j < width; j++) // Loop through each column
        {
            // Calculate the grayscale value by taking the average of the red, green, and blue values
            BYTE gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = gray; // Assign the grayscale value to the red channel
            image[i][j].rgbtGreen = gray; // Assign the grayscale value to the green channel
            image[i][j].rgbtBlue = gray; // Assign the grayscale value to the blue channel
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // Loop through each row
    {
        for (int j = 0; j < width / 2; j++) // Loop through the first half of each row
        {
            RGBTRIPLE temp = image[i][j]; // Store the current pixel in a temporary variable
            image[i][j] = image[i][width - j - 1]; // Assign the pixel on the opposite side of the row
            image[i][width - j - 1] = temp; // Assign the temporary pixel to the opposite side of the row
        }
    }
}

// Function to blur the image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporary array to store modified image
    RGBTRIPLE temp[height][width];

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize variables for calculating the average color of surrounding pixels
            int count = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            // Loop through the surrounding pixels
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Check if the surrounding pixel is outside the image bounds
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // If the surrounding pixel is inside the image bounds, add its color values to the sums
                    sumRed += image[i + k][j + l].rgbtRed;
                    sumGreen += image[i + k][j + l].rgbtGreen;
                    sumBlue += image[i + k][j + l].rgbtBlue;
                    count++;
                }
            }
            // Calculate the average color of the surrounding pixels and set the pixel color in the temporary array
            temp[i][j].rgbtRed = round((float) sumRed / count);
            temp[i][j].rgbtGreen = round((float) sumGreen / count);
            temp[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }
    // Update the original image with the modified image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}


// Detect edges using the Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary array to store the edge detection result
    RGBTRIPLE temp[height][width];
    // Define the Sobel operator kernels for x and y directions
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize variables to store the convolution results in x and y directions
            int sum_redx = 0, sum_greenx = 0, sum_bluex = 0;
            int sum_redy = 0, sum_greeny = 0, sum_bluey = 0;

            // Convolve the Sobel operator with the pixels in a 3x3 neighborhood around the current pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Check if the pixel is within the bounds of the image
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width)
                    {
                        continue; // If the pixel is outside of the image bounds, skip it.
                    }

                    // Compute the convolution in x and y directions for each color channel
                    sum_redx += image[i + k][j + l].rgbtRed * gx[k + 1][l + 1];
                    sum_greenx += image[i + k][j + l].rgbtGreen * gx[k + 1][l + 1];
                    sum_bluex += image[i + k][j + l].rgbtBlue * gx[k + 1][l + 1];

                    // Cap the values of the color channels to 255 if they exceed that value
                    sum_redy += image[i + k][j + l].rgbtRed * gy[k + 1][l + 1];
                    sum_greeny += image[i + k][j + l].rgbtGreen * gy[k + 1][l + 1];
                    sum_bluey += image[i + k][j + l].rgbtBlue * gy[k + 1][l + 1];
                }
            }

            // Calculate the magnitude of the gradient using the convolution results
            int red = round(sqrt(pow(sum_redx, 2) + pow(sum_redy, 2)));
            int green = round(sqrt(pow(sum_greenx, 2) + pow(sum_greeny, 2)));
            int blue = round(sqrt(pow(sum_bluex, 2) + pow(sum_bluey, 2)));

            // Cap the values of the color channels to 255 if they exceed that value
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    // Update the image with the edge detection result
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
