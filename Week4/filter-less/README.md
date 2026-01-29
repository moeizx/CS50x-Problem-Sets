# Filter (Less)

## Overview

This program applies basic image filters to **24-bit uncompressed BMP files**. It is a solution to **CS50x Problem Set 4: Filter (Less)**.

The program reads a BMP image, applies a selected filter to every pixel, and writes the modified image to a new file. Supported filters include **grayscale**, **sepia**, **reflection**, and **blur**.

## Files

* `filter.c` — Handles command-line arguments, file I/O, and dispatches the selected filter
* `helpers.c` — Implements the image filter algorithms
* `helpers.h` — Function prototypes for image filters
* `bmp.h` — BMP file format structures
* `Makefile` — Builds the `filter` executable

## Usage

```
./filter [flag] infile outfile
```

### Available Filters

* `-g` — Grayscale
* `-s` — Sepia
* `-r` — Reflect horizontally
* `-b` — Blur

### Example

```
./filter -g image.bmp gray.bmp
```

Converts `image.bmp` to grayscale and saves the result as `gray.bmp`.

## Implementation Details

### Grayscale

Each pixel’s red, green, and blue values are averaged and rounded to the nearest integer. All three color channels are then set to this average, producing a grayscale effect.

### Sepia

Each pixel is recolored using the sepia formula:

* `sepiaRed = 0.393R + 0.769G + 0.189B`
* `sepiaGreen = 0.349R + 0.686G + 0.168B`
* `sepiaBlue = 0.272R + 0.534G + 0.131B`

Values are capped at **255** to prevent overflow.

### Reflection

Each row of the image is mirrored horizontally by swapping pixels symmetrically from left to right.

### Blur

A box blur is applied by averaging each pixel’s color values with those of its neighboring pixels (up to a 3×3 grid). A copy of the original image is used to ensure calculations are not affected by already-modified pixels.

## Compilation

Compile the program using:

```
make filter
```

Or manually:

```
clang -o filter filter.c helpers.c
```

## Notes

* Only **24-bit uncompressed BMP 4.0** files are supported.
* Rounding is handled using `+ 0.5` before casting to `int`.
* Edge pixels in the blur filter are handled by averaging only valid neighboring pixels.
