Student Name: Travis Pootoolal
Student ID: 0753981

The Makefile compiles two programs:
-Maze solving program
-Stack testing program

Notes on compiling:
>To compile both files type 'make' into the command line while in the root of the assignment folder 
 (the one with the Makefile present).

>To compile only the maze solving program type 'make program' in the root of the assignment folder.
 This compiles the executable file into the bin folder. 

>To compile only the stack testing program type 'make test' in the root of the assignment folder. 
 This compiles the executable file into the bin folder.

Notes on running:
>To run the maze solving program there must be a maze file in a .txt format in the root of the 
 assignment folder. Type 'bin/runme xxxx.txt' (where xxxx is the name of your maze file) into the
 command line while in the root of the assignment folder.

>To run the stack testing program type 'bin/testme' into the command line while in the root of the
 assignment folder.

>Both programs should just print to the screen without requiring any user input.

Miscellaneous notes:
>The maze solving program has few essential parts to the code so I've taken the liberty to turn
 those essential parts into functions, stored them in a separate .c file and call them in the main
 function.
