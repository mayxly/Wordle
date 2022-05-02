#include "wordle.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// See wordle.h for documentation.
bool evaluate_guess(const char *secret, const char *guess, char *result)
{
    assert(secret);
    assert(guess);
    assert(result);
    assert(strlen(guess) == strlen(secret));
    bool found = false;
    int i = 0;
    for (i = 0; guess[i] != '\0'; ++i)
    {
        found = false;
        for (int x = 0; secret[x] != '\0'; ++x)
        {
            if (guess[i] == secret[x] && i == x)
            {
                result[i] = guess[i] - 32;
                found = true;
                break;
            }
            if (guess[i] == secret[x])
            {
                result[i] = guess[i];
                found = true;
            }
        }
        if (!found)
        {
            result[i] = '.';
        }
    }
    if (strcmp(secret, guess) == 0)
    {
        return true;
    }
    return false;
}

// See wordle.h for documentation.
int find_in_list(const char *guess, char *word_list[], int num_words)
{
    assert(guess);
    assert(word_list);
    int low = 0;
    int high = 2309;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (strcmp(word_list[mid], guess) == 0)
        {
            return mid;
        }
        else if (strcmp(guess, word_list[mid]) > 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// See wordle.h for documentation.
void available_letters(char *guesses[], char *results[], int num_guesses,
                       char *alphabet)
{
    int len = strlen(guesses[0]);
    assert(num_guesses >= 0);
    assert(guesses);
    assert(results);
    for (int i = 0; i < 26; ++i)
    {
        alphabet[i] = i + 'a';
    }
    for (int i = 0; i < num_guesses; ++i)
    {
        for (int x = 0; (guesses[i])[x] != '\0'; ++x)
        {
            assert(len == strlen(results[i]));
            if (results[i][x] == '.')
            {
                alphabet[(guesses[i])[x] - 97] = '.';
            }
            else if (((results[i])[x] >= 'A' && (results[i])[x] <= 'Z') ||
                     ((results[i])[x] >= 'a' && (results[i])[x] <= 'z'))
            {
                alphabet[(guesses[i])[x] - 97] = (guesses[i])[x] - 32;
            }
        }
    }
}
