# Credit – Week 1 Problem Set

This folder contains my solution to the **Credit** problem set from **CS50x: Introduction to Computer Science**.

The program validates credit card numbers based on **Luhn’s Algorithm** and identifies the card type.

---

## Problem Description

Credit cards have structured numbers:

- **American Express**: 15 digits, starts with 34 or 37  
- **MasterCard**: 16 digits, starts with 51–55  
- **Visa**: 13 or 16 digits, starts with 4  

Credit card numbers also include a **checksum**, allowing programs to detect invalid numbers or typos.

---

## Implementation

The program:

1. Prompts the user for a numeric credit card number using `get_long()`.  
2. Uses **Luhn’s Algorithm** to check validity:  
   - Multiply every other digit by 2, starting from the second-to-last digit.  
   - Sum the digits of these products.  
   - Add this sum to the sum of digits that weren’t multiplied.  
   - If the total modulo 10 is 0, the number is valid.  
3. Determines the card type (AMEX, MasterCard, or Visa) based on number length and starting digits.  
4. Prints exactly one of the following as output:  
   - `AMEX`  
   - `MASTERCARD`  
   - `VISA`  
   - `INVALID`

The program also **re-prompts** the user if the input is not numeric.

---

## Usage Example

```bash
$ ./credit
Number: 4003600000000014
VISA
