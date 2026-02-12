# Inheritance

## Overview

This program simulates genetic inheritance of blood types across multiple generations. It is a solution to **CS50x Problem Set 5: Inheritance**.

The program recursively generates a family tree where each person has two parents and two alleles. It randomly assigns alleles to individuals while inheriting alleles from parents for non-founder generations. The family tree is then printed and memory is freed appropriately.

## Usage

```
./inheritance
```

The program outputs the blood type of each individual in the family tree, with indentation representing generations:

```
Child (Generation 0): blood type AO
Parent (Generation 1): blood type AA
Great-Grandparent (Generation 3): blood type BO
```

## Implementation Details

### Struct Definition

```c
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;
```

* Each person has pointers to two parents.
* Each person has two alleles representing their blood type.

### Family Creation

* `create_family(int generations)` recursively creates a family tree.
* If `generations > 1`, the function:

  * Creates two parents by recursively calling itself.
  * Assigns the child’s alleles by randomly selecting one allele from each parent.
* If `generations == 1`, the person is a founder with no parents and random alleles are assigned.

### Printing the Family

* `print_family(person *p, int generation)` prints each person’s alleles.
* Indentation represents generations.
* Generation 0 is the child, 1 is the parent, and 2+ are grandparents with appropriate "Great-" prefixes.

### Memory Management

* `free_family(person *p)` recursively frees all ancestors of a person and finally frees the person itself.
* Ensures no memory leaks in the program.

### Random Allele Generation

* `random_allele()` randomly returns `'A'`, `'B'`, or `'O'` with equal probability.

## Compilation

Compile the program using:

```
clang -o inheritance inheritance.c
```

## Notes

* The family tree depth can be modified by changing `GENERATIONS`.
* Randomness is seeded with `time(0)` to produce different outputs on each run.
* The program demonstrates **recursion**, **structs**, **pointers**, and **dynamic memory management**.
