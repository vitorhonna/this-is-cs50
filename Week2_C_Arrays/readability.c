#include <stdio.h>
#include <cs50.h>
#include <string.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    // Count number of letters, words and sentences
    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // Calculate the Coleman-Liau index
    float L = (float) letters / words * 100.0;      // #letters per 100 words
    float S = (float) sentences / words * 100.0;    // #sentences per 100 words
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Approximate the index to the nearest integer
    float decimals = index - (int) index;

    if (decimals >= 0.5)
    {
        index = (int) index + 1;
    }
    else
    {
        index = (int) index;
    }

    // Check if it's out of the grading range and print results
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) index);
    }

    return 0;
}


// Count the number of letters
int countLetters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letters++;
        }
    }
    return letters;
}

int countWords(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int countSentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
