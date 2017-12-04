## Introduction

This repository describes my work on the sudoku solver project at the ENSEM.


## Description of the project :
The project was developed over 3 versions :

• Basic version: Solves a 3x3 sudoku grid either by using a brute force method or backtracking one depending on each sudoku grid.

• Multi-threaded version: Takes as input multiple sudoku grids and solves each one using a thread

• Server-Client version: The client program reads one or multiple files containing sudoku grids and sends the grids to the server program that resolves them.  The server program then sends back the results to the client that writes the results into a file.

## Running instructions:

After compiling the code:

• ./sudoku -standalone : For the basic version

• ./sudoku -multithread : For the multi-threaded version

• ./sudoku -server : For the Server-Client version


