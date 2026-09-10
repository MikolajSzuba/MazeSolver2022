# Maze Solver

> My first programming project — a simple maze solver written in C.

The program reads a maze stored as a **PGM image**, searches for a path from a specified starting point to the edge of the maze, and saves the discovered route to a new file. I created this project to learn about data structures, dynamic memory allocation, recursion, and binary file handling.

## How does it work?

The solver moves through the available cells of the maze and stores their coordinates using a custom stack implementation. When it reaches a dead end, it backtracks to the most recent position from which another path can be explored.

In the output image:

- black pixels represent walls,
- white pixels represent open paths,
- gray pixels mark the discovered route.

## Key features

- reading and writing binary PGM (`P5`) files,
- maze traversal with backtracking,
- custom stack implementation,
- dynamic memory management,
- saving the solution as an image.

## Getting started

You will need a C compiler, such as **GCC**.

```bash
cd labirynt
gcc main.c -o maze-solver
```

Run the program:

```bash
./maze-solver
```

On Windows:

```powershell
.\maze-solver.exe
```

By default, the program:

1. reads the `lab.pgm` file,
2. starts searching at coordinates `{0, 1}`,
3. prints the coordinates of the discovered route,
4. saves the result as `nowylab.pgm`.

The file names and starting point can be changed in [`labirynt/main.c`](labirynt/main.c).

## Project structure

```text
MazeSolver2022/
├── labirynt/
│   ├── main.c          # program entry point
│   ├── labirynt.c      # maze solver and PGM file handling
│   ├── labirynt.h      # data structures and function declarations
│   ├── stos.c          # stack implementation
│   └── *.pgm           # sample mazes and output files
└── mergesort/
    ├── main.c
    ├── mergesort.c     # Merge Sort for a singly linked list
    └── mergesort.h
```

The `mergesort` directory contains an additional exercise implementing Merge Sort for a singly linked list.

## What did I learn?

As my first programming project, it gave me hands-on experience with the fundamentals of C and helped me better understand how algorithms work. Most importantly, I learned about pointers, structures, dynamic memory, recursion, and image data representation.

## Author

**Mikołaj Szuba**  
My first programming project, created while learning the C language.
