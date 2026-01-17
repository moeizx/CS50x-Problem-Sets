# 🗳️ CS50x Week 3 — Tideman (Ranked Pairs Voting)

This project is part of **Harvard CS50x Week 3 Problem Set — Tideman**.  
CS50 provided the **main program structure and starter code**, and my task was to implement the **core logic functions** that power the Tideman ranked-pairs voting system.

---

## 📌 Problem Overview

In a **Tideman (ranked-pairs) election**, voters rank candidates in order of preference instead of voting for just one candidate.  

The election process works as follows:

1. Each voter ranks all candidates.  
2. Preferences are recorded in a **matrix** showing how many voters prefer candidate A over candidate B.  
3. Candidate **pairs** are created where one candidate is preferred over another.  
4. Pairs are **sorted by strength of victory** (largest preference margin first).  
5. Pairs are **locked into a directed graph**, avoiding cycles.  
6. The winner is the candidate with **no arrows pointing to them** in the locked graph.  

---

## ⚙️ What I Implemented

I implemented the following **core functions**:

✅ `vote()` — Validates candidate names and updates each voter’s ranked preferences.  
✅ `record_preferences()` — Updates the global preferences matrix based on voter rankings.  
✅ `add_pairs()` — Creates all candidate pairs where one is preferred over the other.  
✅ `sort_pairs()` — Sorts candidate pairs by the strength of victory.  
✅ `lock_pairs()` — Locks pairs into the graph while **preventing cycles**.  
✅ `print_winner()` — Determines the winner by checking for a candidate with no incoming edges.  
✅ `cycle()` — Recursive function to detect cycles when locking pairs.  

> The rest of the program (input handling, candidate array, and framework) was provided by CS50.  

---

## 🧠 Concepts Practiced

- C programming fundamentals  
- Arrays and 2D arrays  
- Structs and memory handling  
- String comparison (`strcmp`)  
- Recursion and cycle detection in graphs  
- Algorithmic thinking and edge case handling  
