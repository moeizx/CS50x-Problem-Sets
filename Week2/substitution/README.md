# Substitution Cipher

## Overview
This program implements a **substitution cipher** in C, which encrypts messages by replacing each letter with another letter according to a **key**. The key is provided as a **command-line argument**, and the program outputs the encrypted message (ciphertext).

---

## Problem
In a substitution cipher:

- Each letter of the alphabet is mapped to a corresponding letter in the key.  
- Encryption is reversible if the key is known.  
- Example key: `NQXPOMAFTRHLZGECYJIUWSKDVB`  
  - A → N  
  - B → Q  
  - C → X  
  - …and so on  

Example:

- Plaintext: `HELLO`  
- Key: `FOLLE...`  
- Ciphertext: `FOLLE`  
