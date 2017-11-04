/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include "ListFunctions.h"

typedef node stack;

stack* createStack(){

 return createList();
}

stack* push(stack* head, int Y, int X){

 return addFront(head, Y, X);
}

stack* pop(stack* head){

 return removeFront(head);
}

stack* peek(stack* head){

 return getFrontVal(head);
}

void destroyStack(stack* head){

 destroyList(head);
}
