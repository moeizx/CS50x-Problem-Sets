# 🗳️ CS50x Week 3 — Runoff (Ranked Choice Voting)

This project is part of **Harvard CS50x Week 3 Problem Set — Runoff**.  
The main program structure and starter code were provided by CS50. My task was to implement the core logic functions that power the ranked-choice voting system.

---

## 📌 Problem Overview

In a **runoff (ranked-choice) election**, voters rank candidates in order of preference instead of voting for only one candidate.

The election process works as follows:

1. Each voter ranks all candidates.
2. Votes are initially counted for each voter's first preference.
3. If a candidate receives more than 50% of the votes, they win.
4. If no candidate has a majority:
   - The candidate(s) with the fewest votes are eliminated.
   - Votes for eliminated candidates are redistributed to the next preferred candidate.
5. This process repeats until a winner is found or a tie occurs.

---

## ⚙️ What I Implemented

The following functions were implemented by me:

- ✅ **vote()** — Validates candidate names and stores voter preferences.
- ✅ **tabulate()** — Counts votes for the highest-ranked non-eliminated candidate.
- ✅ **print_winner()** — Detects when a candidate has more than 50% of the votes.
- ✅ **find_min()** — Finds the minimum vote count among remaining candidates.
- ✅ **is_tie()** — Checks whether all remaining candidates are tied.
- ✅ **eliminate()** — Eliminates candidate(s) with the minimum vote count.

The rest of the program (input handling, structure, and framework) was provided by CS50.

---

## 🧠 Concepts Practiced

- C programming fundamentals
- Arrays and 2D arrays
- Structs and memory handling
- String comparison (`strcmp`)
- Control flow and loops
- Algorithmic thinking and edge case handling
