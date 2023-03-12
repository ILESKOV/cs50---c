#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Total number of words in dictionary
unsigned int total_words = 0;

// Represents whether the dictionary has been loaded or not
bool is_loaded = false;

// Number of words loaded in dictionary
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to get index
    unsigned int index = hash(word);

    // Traverse linked list at index
    for (node *n = table[index]; n != NULL; n = n->next)
    {
        // Compare word to current node's word
        if (strcasecmp(word, n->word) == 0)
        {
            // Word found
            return true;
        }
    }

    // Word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Use first letter of word as hash value
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer for word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for the word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        // Insert node into hash table
        unsigned int index = hash(word);
        if (table[index] == NULL)
        {
            // First node at this index
            table[index] = n;
        }
        else
        {
            // Append node to linked list
            n->next = table[index];
            table[index] = n;
        }

        // Increment total word count
        total_words++;
        word_count++;
    }

    // Close dictionary file
    fclose(file);

    // Dictionary loaded successfully
    is_loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (!is_loaded)  // check if dictionary is not loaded
    {
        return 0;
    }

    return word_count;  // return number of words loaded
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // Iterate over all buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to the first node in the bucket
        node *cursor = table[i];

        // Free all nodes in the bucket
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    // Return true to indicate success
    return true;
}
