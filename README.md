# Wordle

This program allows users to play the New York Times Wordle game in easy and normal mode. Here is how it works:

All guesses must be lowercase.
To win, you have to guess the Wordle in six goes or less.
Every word you enter must be in the word list. 2,309 (at the time of writing) are answers to a specific puzzle.
A correct letter guesses in the right place returns an UPPERCASE letter.
A correct letter in the wrong place returns a lowercase letter.
An incorrect letter return a period (.).
Letters can be used more than once.
Answers are never plurals.

Easy mode: Word does not need to exist in the wordle dictionary.
Normal mode: Word must exist in the wordle dictionary.

EXAMPLE:
secret word: storm

guess #1: spare     output: S..R.
guess #2: smirk     output: Sm.R.
guess #3: story     output: STOR.
guess #4: storm     output: "YOU WIN! The word was: storm"

Have fun!


