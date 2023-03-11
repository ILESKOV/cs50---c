#include <stdio.h>  // Include standard input/output library
#include <ctype.h>  // Include character handling functions
#include <string.h> // Include string handling functions
#include <math.h>   // Include math functions
#include <cs50.h>   // Include functions for Harvard CS50 course

// Declare functions for counting letters, words, and sentences
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// Main function
int main(void)
{
    // Get input text from user
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // Calculate Coleman-Liau index
    float L = ((float) letter_count / (float) word_count) * 100;
    float S = ((float) sentence_count / (float) word_count) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// Count the number of letters in a string
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))  // If the character is a letter, increase count
        {
            count++;
        }
    }
    return count;
}

// Count the number of words in a string
int count_words(string text)
{
    int count = 1;  // Start count at 1 to account for first word
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))  // If the character is a space, increase count
        {
            count++;
        }
    }
    return count;
}

// Count the number of sentences in a string
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')  // If the character is a sentence-ending punctuation, increase count
        {
            count++;
        }
    }
    return count;
}
