/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "stack.h"
#include "solverFunctions.h"

int main(int argc, char* argv[]){

 stack* sol;
 struct theMaze* first;

 pathCheck(argv[1]); /* Checks the command line argument. */

 first = mazePrinter(argv[1]); /* Stores the 2D maze array into a struct. */

 sol = solver(first); /* Finds the solution to the maze, stores all coordinates in a stack. */

 free(first);

 first = solutionWriter(sol, argv[1]); /* Writes the maze with solution to the struct */

 finalPrint(first); /* Prints the maze with solution to the terminal */

 free(first);

return 0;
}
