# Cash – Week 1 Problem Set

This folder contains the solution to the **Cash** problem set from **CS50x: Introduction to Computer Science**.

The program calculates the **minimum number of coins** needed to give a user change.

---

## Problem Description

When giving change, the goal is to minimize the number of coins dispensed.  

- The program prompts the user for the **amount of change owed** (in cents).  
- The user must enter a **positive integer**.  
- The program calculates the minimum number of coins using common U.S. denominations:

  - Quarters (25¢)  
  - Dimes (10¢)  
  - Nickels (5¢)  
  - Pennies (1¢)  

- The user is **re-prompted** if the input is not numeric or less than 0.

---

## Usage Example

```bash
$ ./cash
Change owed: 25
1

$ ./cash
Change owed: 70
4
