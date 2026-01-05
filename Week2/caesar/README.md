# Caesar Cipher (caesar)

This directory contains a solution for the **Caesar cipher** problem from CS50 Week 2.

## Problem Overview

The Caesar cipher is a simple encryption technique in which each letter of a message (plaintext) is "rotated" by a fixed number of positions down the alphabet. For example, with a key of 1, `A` becomes `B`, `B` becomes `C`, and so on, wrapping around from `Z` to `A`.

The program in this directory implements a command-line tool to encrypt messages using this cipher.

## Usage

1. Compile the program:

```bash
gcc -o caesar caesar.c
```

2. Run the program with a **single command-line argument** representing the key:

```bash
./caesar 3
```

3. Enter the plaintext when prompted. The program will output the corresponding ciphertext.

### Example

```bash
$ ./caesar 3
plaintext:  HELLO
ciphertext: KHOOR
```

## Requirements

* Accept a **single command-line argument**, a non-negative integer key.
* Print an error and exit if:

  * No command-line argument is provided.
  * More than one argument is provided.
  * The argument is not a non-negative integer.
* Prompt the user for plaintext input using `get_string`.
* Output the ciphertext after applying the Caesar cipher:

  * Preserve case (uppercase/lowercase letters).
  * Non-alphabetical characters remain unchanged.

