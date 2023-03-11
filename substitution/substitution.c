#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool validate_key(string key);

int main(int argc, string argv[])
{
    // Validate command-line arguments
    if (argc != 2) // check if there is exactly one command-line argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1]; // assign the first command-line argument to the key variable
    if (!validate_key(key)) // check if the key is valid
    {
        printf("Key must contain 26 characters, with each letter appearing exactly once.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt plaintext using substitution cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++) // iterate over each character in the plaintext
    {
        if (isalpha(plaintext[i])) // check if the character is an alphabetic letter
        {
            int index = toupper(plaintext[i]) - 'A'; // compute the index of the corresponding letter in the key
            if (islower(plaintext[i])) // check if the character is lowercase
            {
                printf("%c", tolower(key[index])); // print the corresponding lowercase letter in the key
            }
            else
            {
                printf("%c", toupper(key[index])); // print the corresponding uppercase letter in the key
            }
        }
        else // the character is not an alphabetic letter
        {
            printf("%c", plaintext[i]); // print the character as is
        }
    }
    printf("\n"); // print a newline at the end of the ciphertext

    return 0;
}

bool validate_key(string key)
{
    if (strlen(key) != 26) // check if the key has exactly 26 characters
    {
        return false;
    }
    int count[26] = {0}; // initialize an array of counts for each letter to 0
    for (int i = 0; i < 26; i++) // iterate over each character in the key
    {
        if (!isalpha(key[i])) // check if the character is not an alphabetic letter
        {
            return false;
        }
        int index = toupper(key[i]) - 'A'; // compute the index of the corresponding letter in the count array
        count[index]++; // increment the count for the corresponding letter
        if (count[index] > 1) // check if the count for the corresponding letter is greater than 1
        {
            return false; // the key is not valid if a letter appears more than once
        }
    }
    return true; // the key is valid if it has exactly 26 characters and each letter appears exactly once
}
