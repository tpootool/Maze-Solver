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

void pathCheck(char* mazePath){ /* Checks to see if a file path was entered. */

 if (mazePath == NULL){
  printf("\nNo file path entered.\nExiting Program.\n");
  exit(1);
  }
 else if (fopen(mazePath,"r") == NULL){
  printf("\nInvalid file path entered.\nExiting Program.\n");
  exit(1);
  }
}


struct theMaze* mazePrinter(char* mazePath){ /* Returns the 2D array of the maze and length of the maze in a struct. */

 int i, maxLength;
 char mazeHolder[100][100];
 char* mazeLine;
 FILE* maze;
 struct theMaze* returnValue;

 returnValue = malloc(sizeof(struct theMaze)*1);
 mazeLine = malloc(sizeof(char)*100);

 maze = fopen(mazePath,"r");
 fgets(mazeLine,100,maze);

 i = 0;
 maxLength = 0;

 do {

  strcpy(mazeHolder[i],mazeLine); 

  fgets(mazeLine,100,maze);

  i++;
  maxLength++;

  } while (strcmp(mazeLine,mazeHolder[i-1]) != 0);

 fclose(maze);

 for (i=0;i<=maxLength;i++){

  strcpy(returnValue->printout[i],mazeHolder[i]);
  }

 returnValue->Length = maxLength;

 return returnValue;
}

stack* solver(struct theMaze* first){ /* Finds the solution to the maze and returns the stack containing the coordinates. */

 int i,j;
 char mazeHolder[100][100];
 stack* sol;

 for (i=0;i<=first->Length;i++){
  for (j=0;j<=strlen(first->printout[0]);j++){
    mazeHolder[i][j] = first->printout[i][j];
  }
 }

 i = 0;
 j = 0;

 while (mazeHolder[i][j] != 'S'){ /* Sets the starting coordinates. */

  i++;
  if(i == strlen(first->printout[0])){
   j++;
   i = 0;
   }
 }

 sol = createStack();

 sol = push(sol,i,j); /* Stores starting coordinates in the stack */

 while ( (mazeHolder[i+1][j] != 'F') || (mazeHolder[i-1][j] != 'F') || (mazeHolder[i][j+1] != 'F') || (mazeHolder[i][j-1] != 'F') ){

  if(mazeHolder[i][j+1] == ' '){ /* Check right. */
    j++;
    mazeHolder[i][j] = '-';
    sol = push(sol,i,j);
    }

  else if(mazeHolder[i+1][j] == ' '){ /* Check down. */
    i++;
    mazeHolder[i][j] = '-';
    sol = push(sol,i,j);
    }

  else if(mazeHolder[i][j-1] == ' '){ /* Check left. */
    j--;
    mazeHolder[i][j] = '-';
    sol = push(sol,i,j);
    }

  else if(mazeHolder[i-1][j] == ' '){ /* Check up. */
    i--;
    mazeHolder[i][j] = '-';
    sol = push(sol,i,j);
    }

  else { /* Removes failed path. */
    pop(sol);
    }

 i = sol->next->yPosition;
 j = sol->next->xPosition;

  if ( (mazeHolder[i+1][j] == 'F') || (mazeHolder[i-1][j] == 'F') || (mazeHolder[i][j+1] == 'F') || (mazeHolder[i][j-1] == 'F') ){
   break;
   }

 if (mazeHolder[i][j] == 'S'){ /* If no solution is available, inform user and exit program. */
   printf("\nNo solution from starting position possible.\nExiting Program.\n");
   exit(1);
   }

  }

 return sol;
}

struct theMaze* solutionWriter(stack* solution, char* mazePath){ /* Prints the path with '.' in the 2D maze array */

 int i,j;
 struct theMaze* route;
 i = 0;
 j = 0;

 route = mazePrinter(mazePath);
 while (solution->next->next != NULL){

 i = solution->next->yPosition;
 j = solution->next->xPosition;

  route->printout[i][j] = '.';

  pop(solution);

 }

 destroyStack(solution);
 return route;
}

void finalPrint(struct theMaze* solution){ /* Prints the maze with solution */

 int i;

 for(i=0;i<=solution->Length;i++){

  printf("%s",solution->printout[i]);
  }
}

