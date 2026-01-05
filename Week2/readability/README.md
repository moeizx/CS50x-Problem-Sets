# Readability 

## Overview
This program estimates the **U.S. grade level** needed to comprehend a text using the **Coleman-Liau index**. It calculates a grade based on letters, words, and sentences in the text.

---

## Problem
- *Charlotte's Web* → 2nd–4th grade  
- *The Giver* → 8th–12th grade  

Your program should:

- Output `"Grade X"` (rounded index)  
- `"Grade 16+"` if 16 or higher  
- `"Before Grade 1"` if less than 1  

File: `readability.c`  

---

## Coleman-Liau Index

index = 0.0588 * L - 0.296 * S - 15.8


Where:

- `L` = average letters per 100 words  
- `S` = average sentences per 100 words  

---

## Implementation Steps

1. Prompt user for text.  
2. Count letters, words, and sentences.  
3. Compute `L` and `S`.  
4. Calculate index, round to nearest integer.  
5. Print grade output.  

---

## Demo

$ ./readability

Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!

Grade 3
