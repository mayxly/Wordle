// this module provides functions that can be used to play Wordle

#include <stdbool.h>

// all "secret" chars are only lowercase letters (a...z)
// all "guess" chars are only lowercase letters (a...z)
// all "result" chars are either:
//   lowercase letter: letter exists in secret, but not in correct position
//   UPPERCASE letter: letter in correct position
//   . (period): letter does not exist in secret word
// for each pair of guesses/results arrays:
//   they contain the same number of strings of the same length

// evaluate_guess(secret, guess, result) returns whether or not secret is equal
//   to guess and modifies result chars (of comparison) as described above
// note: for this function, repeating letters in guess are each handled as
//   described above even if secret contains just one such letter (see example)
// example:
//   char result[6];
//   evaluate_guess("apple", "paper", result) => false; result => "paPe."
//   evaluate_guess("place", "paper", result) => false; result => "Pape."
// requires: result is sufficiently large [not asserted]
//           secret and guess have the same length
// effects: result will be modified
// time: O(n)
bool evaluate_guess(const char *secret, const char *guess, char *result);

// find_in_list(guess, word_list, num_words) finds the index of the string
//    matching guess in word_list, or -1 if no match is found
// example:
//   char *words[3] = { "goodbye", "hello", "hurray" };
//   find_in_list("goodbye", words, 3) => 0
// requires: word_list is sorted lexicographically in ascending order
//           [not asserted]
// time: O(m * log(num_words)), where m is the length of guess
int find_in_list(const char *guess, char *word_list[], int num_words);

// available_letters(guesses, results, num_guesses, alphabet) determines the
//   status of each alphabet letter a...z in the secret word, based on results
//   of existing guesses; the result is stored in alphabet as an "alphabet
//   string" (null terminated), where each of a..z is:
//     . (period), if the letter does not exist in secret word
//     lowercase letter, if the status of the letter is unknown
//     UPPERCASE letter, if the letter exists in secret word
// example: char alphabet[27]
//          char *guesses[2] = { "apple", "touch" };
//          char *results[2] = { ".pp..", ".OUCH" };
//          available_letters(guesses, results, 2, alphabet);
//          alphabet => ".bCd.fgHijk.mnOPqrs.Uvwxyz"
// requires: first "num_guesses" elements in guesses and results are valid
//           strings of the same length
//           alphabet is sufficiently large [not asserted]
//           num_guesses >= 0
// effects: alphabet is modified
// time: O(num_guesses * m) where m is the length of each guess
void available_letters(char *guesses[], char *results[], int num_guesses,
                       char *alphabet);
