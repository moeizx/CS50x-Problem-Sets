# 🗳️ CS50x Week 3 — Plurality Voting

This project is part of **Harvard CS50x Week 3 Problem Set — Plurality**.  
The main program structure and starter code were provided by CS50. My task was to implement the required logic functions for vote counting and winner detection.

---

## 📌 Problem Overview

In a **plurality election**, each voter selects one candidate.  
The candidate with the highest number of votes wins. If multiple candidates have the same highest number of votes, all tied candidates are declared winners.

The election process:

1. Candidates are provided as command-line arguments.
2. Each voter casts one vote.
3. Votes are counted and stored.
4. The candidate(s) with the maximum votes are printed as winner(s).

---

## ⚙️ What I Implemented

The following functions were implemented by me:

- ✅ **vote()** — Validates the candidate name and increments the vote count.
- ✅ **print_winner()** — Finds the highest vote count and prints all candidates who received that number of votes.

The rest of the program framework (input handling, data structures, and setup) was provided by CS50.

---

## 🧠 Concepts Practiced

- C programming fundamentals
- Structs and arrays
- String comparison using `strcmp`
- Loops and conditional logic
- Basic algorithm design
