# Functional Object Points Generator

This project is a C++ program that generates a sequence of points based on a starting point and a set of base points using a functional object approach.

The program reads a starting point and a list of base points from an input file, then generates a specified number of points using the `FunctionalObject` class. The generated points are written to an output file. The generation process is handled by the `FunctionalObject` class, which is called repeatedly to produce the next point in the sequence.

## Input Format

The input file (`input.txt`) should have the following structure:

1. First line: integer `n` — the number of points to generate (must be > 0)  
2. Second line: `x0 y0` — coordinates of the starting point  
3. Following lines: `x y` — coordinates of the base points (at least one required)  

**Example:**
3
0.0 0.0
1.0 1.0
2.0 2.0

- `n` = 3 (generate 3 points)  
- `(0.0, 0.0)` = starting point  
- `(1.0, 1.0)` and `(2.0, 2.0)` = base points  

## Output Format

The output file (`output.txt`) contains `n` points. The first line is always the starting point, followed by the generated points, each on a new line:

x0 y0
x1 y1
x2 y2
...

## Requirements

- C++ compiler (e.g., `g++`)  
- `FunctionalObject.h` and its corresponding implementation file (must define a callable object for generating points)  
- Input file `input.txt` in the same directory  
