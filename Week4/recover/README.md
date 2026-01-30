# Recover

## Overview

This program recovers JPEG images from a raw forensic memory card image. It is a solution to **CS50x Problem Set 4: Recover**.

The program scans a raw data file block by block, detects the beginning of JPEG files using their signature bytes, and writes each recovered image to a separate `.jpg` file.

## Usage

```
./recover card.raw
```

* `card.raw` — raw memory card image containing JPEG data

The program will output recovered images named:

```
000.jpg, 001.jpg, 002.jpg, ...
```

## Implementation Details

### Block-Based Reading

* The file is read in chunks of **512 bytes**, which corresponds to the typical block size used by FAT file systems.
* A buffer of size 512 bytes is used to store each block as it is read.

### JPEG Detection

A new JPEG file is identified by checking the first four bytes of a block:

* `0xff 0xd8 0xff`
* The fourth byte has its high nibble equal to `0xe` (`0xe0`–`0xef`)

When this pattern is found, a new image file is started.

### File Writing Logic

* If a JPEG header is found and a previous image file is open, the previous file is closed.
* A new filename is generated using a three-digit counter (e.g., `003.jpg`).
* All subsequent 512-byte blocks are written to the current image file until a new JPEG header is found.

## Code Logic Summary

1. Validate command-line arguments
2. Open the raw input file
3. Read the file in 512-byte blocks
4. Detect JPEG headers
5. Create and write to new image files as needed
6. Close all open files

## Compilation

Compile the program using:

```
clang -o recover recover.c
```

## Notes

* This program assumes the input file uses a FAT-based block structure.
* Only JPEG files are recovered.
* Proper file handling ensures no data is written before the first JPEG header is found.
