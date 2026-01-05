# Scrabble

## Overview
This program simulates a **short Scrabble-like game** in C. It calculates the score of words based on **letter point values** and determines the winner between two players.

---

## Problem
In Scrabble, each letter has a point value:

| Letter | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|--------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Points | 1 | 3 | 3 | 2 | 1 | 4 | 2 | 4 | 1 | 8 | 5 | 1 | 3 | 1 | 1 | 3 | 10 | 1 | 1 | 1 | 1 | 4 | 4 | 8 | 4 | 10 |

For example:  

- Word: `"CODE"`  
- C → 3, O → 1, D → 2, E → 1  
- Total score = 3 + 1 + 2 + 1 = **7 points**

---

## Program Requirements
1. Prompt for input **twice**:
   - `"Player 1"` enters a word  
   - `"Player 2"` enters a word  
2. Compute each word’s score using the letter values table.  
3. Determine the winner:
   - `"Player 1 wins!"`  
   - `"Player 2 wins!"`  
   - `"Tie!"` if scores are equal  

---

## Demo

$ ./scrabble

Player 1: CODE

Player 2: QUIZ

Player 2 wins!
