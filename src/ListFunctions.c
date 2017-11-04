/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>

struct listNode{
  int xPosition;
  int yPosition;
  int length;
  int right,up,down,left;
  struct listNode * next;
};

typedef struct listNode node;

node* createList(){ /* Creates a list with a dummy head. */

  node* toBeMade;

  toBeMade = malloc(sizeof(node)*1);
  toBeMade->next = NULL;
  toBeMade->length = 0;
  toBeMade->xPosition = 0;
  toBeMade->yPosition = 0;

  return (toBeMade);
}

node* initNode(int Y, int X){ /* Initializes a node to be added to a list. */

  node* newElement;

  newElement = malloc(sizeof(node)*1);
  newElement->xPosition = X;
  newElement->yPosition = Y;
  newElement->next = NULL;

 return newElement;
}

node* addFront(node* head, int Y, int X){ /* Creates and adds a node to the front of a list. */

  node* temp;

  temp = initNode(Y, X);

  if (head->next != NULL){
   temp->next = head->next;
   }

  head->next = temp;
  head->length ++ ;

  return (head);
}

void printList(node* head){ /* Prints the contents of a list */

  node* currentPosition;

  currentPosition = head->next;
  printf("\n");
  while(currentPosition->next != NULL){
   printf("x:%d y:%d\n",currentPosition->xPosition, currentPosition->yPosition);
   currentPosition = currentPosition->next;
  }
  printf("x:%d y:%d\n",currentPosition->xPosition, currentPosition->yPosition);
}

node* getFrontVal(node* head){ /* Retrieves the value stored by the first data containing node in the list. */

  return (head->next);
}

node* removeFront(node* head){ /* Removes the first data containing node in the list. */

  node* temp;

  temp = head->next;
  if (head->next->next != NULL){
   head->next = head->next->next;
  }
  else{
   head->next = NULL;
  }

  head->length -- ;

  return (temp);
}

int listLength(node* head){ /* Returns the number of items in a list. */

  return (head->length);
}

void destroyNode(node* doomed){ /* Frees a node */

  free(doomed);
}

void destroyList(node* doomedList){ /* Frees the contents of a list */

  node* nextPosition;

  nextPosition = doomedList->next;

  while(nextPosition->next != NULL){
   destroyNode(doomedList);
   
   doomedList = nextPosition;
   nextPosition = nextPosition->next;
  }
  free(doomedList); 
}
