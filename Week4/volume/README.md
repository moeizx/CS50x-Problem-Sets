# Volume

## Overview

This program modifies the volume of a WAV audio file by scaling each audio sample by a given factor. It is a solution to **CS50x Problem Set 4: Volume**.

The program reads an input `.wav` file, copies its header unchanged, then multiplies every audio sample by a user-provided factor to increase or decrease the volume. The modified audio is written to a new output file.

## Usage

```
./volume input.wav output.wav factor
```

* `input.wav` — original WAV audio file
* `output.wav` — new WAV file with adjusted volume
* `factor` — floating-point value to scale the volume

  * `1.0` leaves the volume unchanged
  * Greater than `1.0` increases volume
  * Between `0.0` and `1.0` decreases volume

## Example

```
./volume song.wav louder.wav 2.0
```

Doubles the volume of `song.wav` and saves it as `louder.wav`.

## Implementation Details

* The first **44 bytes** of the WAV file (the header) are copied directly from the input file to the output file.
* Audio samples are stored as **16-bit signed integers (`int16_t`)**.
* Each sample is read, multiplied by the scaling factor, and written to the output file.
* The program processes samples until the end of the input file is reached.

## Code Logic Summary

1. Validate command-line arguments
2. Open input and output files
3. Read and copy the WAV header
4. Read each audio sample, scale it, and write it to the output file
5. Close all files

## Compilation

Compile the program using:

```
clang -o volume volume.c
```

## Notes

* This program assumes a valid WAV file with 16-bit samples.
* No clipping protection is implemented; very large scaling factors may cause distortion.
