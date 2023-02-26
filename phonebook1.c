// Saves name and number to CSV file

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // C variable
    FILE *file = fopen("phonebook1.csv", "a");

    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}