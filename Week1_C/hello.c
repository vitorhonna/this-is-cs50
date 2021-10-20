#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user name
    string userName = get_string("What is your name? ");

    // Say hello to user
    printf("hello, %s\n", userName);
}
