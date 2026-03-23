# DNA

## Overview

This program identifies a person based on their DNA sequence by comparing Short Tandem Repeats (STRs) against a database. It is a solution to **CS50x Problem Set 6: DNA**.

The program reads a CSV database of individuals and their STR counts, analyzes a DNA sequence, and determines if there is a matching profile.

## Usage

```
python dna.py database.csv sequence.txt
```

* `database.csv` — CSV file containing names and STR counts
* `sequence.txt` — text file containing a DNA sequence

## Example

```
python dna.py small.csv sequence.txt
```

Output:

```
Bob
```

Or if no match is found:

```
No match
```

## Implementation Details

### Reading the Database

* The CSV file is read using `csv.DictReader`.
* Each row represents a person and their STR counts.
* STR names are extracted from the header (excluding the `name` field).

### Reading the DNA Sequence

* The DNA sequence is read as a single string from the input file.

### STR Matching

* For each STR, the program calculates the **longest consecutive run** in the DNA sequence.
* Results are stored in a dictionary mapping STR → count.

### Matching Profiles

* Each person in the database is checked against computed STR counts.
* If all STR counts match exactly, the person's name is printed.
* If no match is found, the program outputs `No match`.

### Longest Match Algorithm

* Iterates through each position in the DNA sequence.
* Checks how many times the STR repeats consecutively starting from that position.
* Tracks and returns the maximum number of consecutive repeats found.

## Code Logic Summary

1. Validate command-line arguments
2. Read database and extract STRs
3. Read DNA sequence
4. Compute longest STR matches
5. Compare results with database
6. Output matching name or `No match`

## Notes

* STR counts must match **exactly** for identification.
* The algorithm ensures correct detection of consecutive repeats.
* Works for both small and large databases provided in the problem set.

## Requirements

* Python 3
