#include <stdio.h>
#include <cs50.h>

void printSpace(int n);
void printHash(int n);

int main(void)
{
    // Prompt user for pyramids height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while ((height > 8) || (height < 1));

    // Print pyramids using user's entered height
    for (int i = 1; i <= height; i++)
    {
        printSpace(height - i);
        printHash(i);
        printf("  ");
        printHash(i);
        printf("\n");
    }
}

// Functions to print spaces
void printSpace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

// Functions to print hashes
void printHash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}
