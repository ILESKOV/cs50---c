#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALLELE 3
#define NUM_ALLELES 2

typedef struct person
{
    struct person *parents[NUM_ALLELES]; // An array of pointers to the parents of this person
    char alleles[NUM_ALLELES]; // An array of two characters representing the person's alleles
} person;

char random_allele(void)
{
    // Returns a random allele ('A', 'B', or 'O')
    int r = rand() % MAX_ALLELE;
    switch (r)
    {
        case 0:
            return 'A';
        case 1:
            return 'B';
        default:
            return 'O';
    }
}

person *create_family(int generations)
{
    person *p = malloc(sizeof(person));

    // Base case: no more generations to allocate
    if (generations == 1)
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
        return p;
    }

    // Recursive case: allocate parents and assign alleles
    p->parents[0] = create_family(generations - 1); // Recursively allocate the first parent
    p->parents[1] = create_family(generations - 1); // Recursively allocate the second parent
    p->alleles[0] = p->parents[0]->alleles[rand() % NUM_ALLELES]; // Inherit one allele from the first parent
    p->alleles[1] = p->parents[1]->alleles[rand() % NUM_ALLELES]; // Inherit one allele from the second parent
    return p;
}

void free_family(person *p)
{
    // Base case: person is NULL, nothing to free
    if (!p)
    {
        return;
    }

    // Recursive case: free parents first, then the current person
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    free(p);
}

void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    printf("Generation %d, Alleles %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // Recursively print the parents of the current person
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./inheritance generations\n");
        return 0;
    }

    int generations = atoi(argv[1]);

    srand(time(NULL)); // Seed the random number generator

    person *p = create_family(generations); // Create a family tree with the specified number of generations
    print_family(p, 0); // Print the family tree starting from the first generation
    free_family(p); // Free the dynamically allocated memory used by the family tree

    return 0;
}
