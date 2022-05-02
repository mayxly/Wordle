// This program allows you to play the Wordle game interactively in the console

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle.c"
#include "wordlist.c"

int main(void)
{
    char guess1[100] = "";
    char guess2[100] = "";
    char guess3[100] = "";
    char guess4[100] = "";
    char guess5[100] = "";
    char guess6[100] = "";
    char result1[100] = "";
    char result2[100] = "";
    char result3[100] = "";
    char result4[100] = "";
    char result5[100] = "";
    char result6[100] = "";
    char *guesses[6] = {guess1, guess2, guess3, guess4, guess5, guess6};
    char *results[6] = {result1, result2, result3, result4, result5, result6};
    char alphabet[27] = "";

    // User chooses a mystery 5 letter word from the wordle wordlist
    int word_idx = -1;
    printf("Please enter a valid word number between 0 and %d\n",
           wordle_word_list_len - 1);
    int result = scanf("%d", &word_idx);
    if (result != 1 || word_idx < 0 || word_idx >= wordle_word_list_len)
    {
        printf("INVALID WORD NUMBER\n");
        exit(1);
    }
    char *secret_word = wordle_word_list[word_idx];

    // User chooses a difficulty (easy/normal)
    int difficulty = 0;
    printf("Please enter a difficulty level (0 = easy, 1 = normal)\n");
    result = scanf("%d", &difficulty);
    if (result != 1 || difficulty < 0 || difficulty > 1)
    {
        printf("INVALID DIFFICULTY\n");
        exit(1);
    }

    int num_guesses = 0;
    while (1)
    {

        // User enters a guess
        char *cur_word = guesses[num_guesses];
        printf("----------------------------------------------------\n");
        for (int i = 0; i < num_guesses; ++i)
        {
            printf("  [%d] %s => %s\n", i + 1, guesses[i], results[i]);
        }
        available_letters(guesses, results, num_guesses, alphabet);
        printf("  %s\n", alphabet);
        printf("Enter your guess #%d:\n", num_guesses + 1);
        result = scanf("%s", cur_word);

        // User inputs an invalid guess
        if (result == EOF)
        {
            printf("Exiting (EOF detected)\n");
            exit(1);
        }

        // User inputs a word with the wrond number of letters
        if (strlen(cur_word) != 5)
        {
            printf("WRONG NUMBER OF LETTERS\n");
            continue;
        }

        // User is in normal mode and inputs a word that does not exist
        if (difficulty == 1)
        {
            if (find_in_list(cur_word, wordle_word_list, wordle_word_list_len) == -1)
            {
                printf("WORD NOT IN DICTIONARY\n");
                continue;
            }
        }

        // User guesses the secret word
        if (evaluate_guess(secret_word, cur_word, results[num_guesses]))
        {
            printf("YOU WIN! The word was: %s\n", secret_word);
            exit(0);
        }
        ++num_guesses;

        // User uses all 6 guesses and does not guess the word
        if (num_guesses == 6)
        {
            printf("YOU LOSE! The word was: %s\n", secret_word);
            exit(0);
        }
    }
}
