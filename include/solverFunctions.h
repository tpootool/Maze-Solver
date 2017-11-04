/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

struct theMaze{ /* A struct that stores a 2D array (in this case a maze) and the number of rows (Length) of the maze */
 char printout[100][100];
 int Length;
};

void pathCheck(char* mazePath);
/*
   Precondition(s):
   -A char* is passed in as a parameter.

   Postcondition(s):
   -Checks if anything was entered as an argv argument in the command line.
   -Checks if parameter is a valid file path.
   -If either of the above conditions are false, program informs the user accordingly and exits program.
   -Returns nothing.
*/

struct theMaze* mazePrinter(char* mazePath);
/*
   Precondition(s):
   -A char* that is a file path is passed in as a parameter.
   -The char* has been initialized.

   Postcondition(s):
   -Stores a 2D array (maze) from the file location into a struct of type.
   -Returns the struct holding the 2D array (maze).
*/

stack* solver(struct theMaze* mazeHolder);
/*
   Precondition(s):
   -A struct of the correct type is passed as a parameter.
   -The struct passed in has been initialized.

   Postcondition(s):
   -Reads the 2D array and performs an algorithm designed to solve a maze.
   -Returns a stack with the coordinates of the correct path.
*/

struct theMaze* solutionWriter(stack* solution, char* mazePath);
/*
   Precondition(s):
   -An initialized stack* has been passed in as a parameter.
   -A char* that is a file path is passed in as a parameter.

   Postcondition(s):
   -Stores a 2D array (maze) from the file location into a struct of type.
   -Edits the 2D array by writing in the path from start to finish.
   -Returns the struct containing the maze.
*/

void finalPrint(struct theMaze* solution);
/*
   Precondition(s):
   -An initialized struct with a 2D array is passed in as a parameter.

   Postcondition(s):
   -The 2D array (maze) is printed with the path from start to finish.
   -Returns Nothing.
*/
