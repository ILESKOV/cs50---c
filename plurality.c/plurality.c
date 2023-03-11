#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximum number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // assign candidate name from command line argument
        candidates[i].votes = 0; // initialize the candidate votes to zero
    }

    int voter_count = get_int("Number of voters: "); // ask for number of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // ask for the name of the candidate

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner(s) of election
    print_winner(); // print the candidate(s) with the highest number of votes
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Look for candidate with given name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0) // check if the entered name matches with a candidate name
        {
            candidates[i].votes++; // increment the vote count for that candidate
            return true; // return true to indicate that the vote is valid
        }
    }

    // If candidate not found, return false
    return false; // return false to indicate that the vote is invalid
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Find the highest number of votes
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes) // find the maximum number of votes
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print the name(s) of the candidate(s) with the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes) // print the names of the candidate(s) with the maximum number of votes
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
