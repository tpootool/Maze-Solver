/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  stack* hi; 
  stack* removed;
  hi = createStack();

  push(hi,8,2);
  printf("\nPushed 8 for y coordinate and 2 for x coordinate.");
  push(hi,5,3);
  printf("\nPushed 5 for y coordinate and 3 for x coordinate.");
  printf("\n\nStack after pushes:");
  printList(hi);
/*
   The above code will print the contents of the stack.
   This tests createStack() push().
   Also tests printList(), but that is not a requirement for the ADT.
*/

removed = pop(hi);

printf("\nPopped stack.\n\nRemoved items: %d, %d\n",removed->yPosition,removed->xPosition);

printf("\nList after pop:");
printList(hi);
/*
   The above code tests pop().
   This will print the int stored in the removed item.
*/

destroyStack(hi);
/*
   Frees stack from memory.
*/

return 0;
}
