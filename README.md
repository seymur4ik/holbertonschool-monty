
# Holberton School Monty Project

  

## About the Project

Project is a simple stack machine executor written in the Monty language. The Monty language contains specific syntax for performing stack operations.

  

## File Structure

We organized the project files as follows:

  

-  **bytecodes:** This folder contains compiled bytecode files of programs written in the Monty language.

-  **errors.c:** Contains functions for error handling.

-  **f_push.c:** Contains the function to implement the `push` command.

-  **helpers.c:** Includes helper functions.

-  **main.c:** The main program file.

-  **monty.h:** Header file containing structures and function prototypes.

-  **stack_funcs.c:** Contains other functions operating on the stack.

  

## How to Use

Follow these steps to use the project:

  

1. Compile the project files.

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
2. Run the program
```bash
./monty bytecodes/00.m
```  

## Contributors

Dadash Huseynzade
Seymur Huseynzade