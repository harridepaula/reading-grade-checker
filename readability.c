#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function declarations
int count_letters(string text, int length);
int count_words(string text, int length);
int count_sentences(string text, int length);
int calculate_index(int numLetters, int numWords, int numSentences);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    // Calculate the length of the text
    int length = strlen(text);
    // Count the number of letters, words, and sentences in the text
    int numLetters = count_letters(text, length);
    int numWords = count_words(text, length);
    int numSentences = count_sentences(text, length);

    // Calculate the reading level index
    int index = calculate_index(numLetters, numWords, numSentences);

    // Determine and print the grade level based on the index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

// Function to count the number of letters in the text
int count_letters(string text, int length)
{
    int count = 0;

    // Iterate over each character in the text
    for (int i = 0; i < length; i++)
    {
        // Check if the character is a letter
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

// Function to count the number of words in the text
int count_words(string text, int length)
{
    int count = 1; // Initialize count to 1 for the first word

    // Iterate over each character in the text
    for (int i = 0; i < length; i++)
    {
        // Check if the character is a space and the next character is not a space
        if (isspace(text[i]) && !isspace(text[i + 1]))
        {
            count++;
        }
    }

    return count;
}

// Function to count the number of sentences in the text
int count_sentences(string text, int length)
{
    int count = 0;

    // Iterate over each character in the text
    for (int i = 0; i < length; i++)
    {
        // Check if the character is a period, exclamation mark, or question mark
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

// Function to calculate the reading level index
int calculate_index(int numLetters, int numWords, int numSentences)
{
    // Calculate the average number of letters per 100 words (L)
    float L = (float)numLetters / numWords * 100;

    // Calculate the average number of sentences per 100 words (S)
    float S = (float)numSentences / numWords * 100;

    // Calculate the index using the given formula and round it to the nearest integer
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}