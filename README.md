AUTHORING: Elliot Gobbert; UMBC; CMSC 313; 4/16/2025

PURPOSE OF SOFTWARE: This program provides a basic implementation of matrix operations in both C and C++, including initialization, element insertion, addition, scalar operations, and dot-product-based matrix multiplication. It demonstrates how similar functionality can be achieved in procedural C and object-oriented C++.

FILES: 
matrix.c
- C version of the program, includes main() and matrix operations using structs and functions.

matrix.cpp
- C++ version of the program, includes main() and matrix operations using a Matrix class.

matrix.h (only in C++ version)
- Contains function and struct declarations for organizing the C matrix logic.

Makefile
- Automates building, running, and cleaning both C and C++ versions.

  BUILD INSTRUCTIONS:
  Open a terminal in the project directory.

  Build everything with:
  
  make
  
  Run the C version:
  
  make run-c
  
  Run the C++ version:
  
  make run-cpp
  
  Clean binaries:
  
  make clean

TESTING METHODOLOGY:
Each version includes hardcoded test matrices in main().

Operations tested:

    Initialization

    Insertion from arrays

    Addition (matrix + matrix, matrix + scalar)

    Multiplication (matrix * matrix, matrix * scalar)

Results are printed to the console to visually confirm correctness.
  

 ADDITIONAL INFORMATION:
 
 Matrix multiplication follows standard dot product rules (rows × columns).
 
 Only integer matrices are supported.
 
 Invalid operations (e.g., size mismatches) are gracefully handled with error messages.

  
![{024FE5C1-D717-4229-9481-F53CCD71A15B}](https://github.com/user-attachments/assets/ba781c32-b065-43a1-ab82-67d93054d4ec)
