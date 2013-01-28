/*
Description:

Swaps the value of two variables, stored globally

Author: David Englund
Specification: pset2, page 4
*/

#include <stdio.h>
#include "cs50.h"
#include <string.h>

// The gloabally-stored variables to be swapped
int x;
int y;

// The function to swap the two variables
void swapXY();

int main(void) {

    // Prompt for two numbers
    printf("This program swaps the value of two variables.\n");
    printf("Enter the first number:  ");
    x = GetInt();
    printf("Enter the second number: ");
    y = GetInt();

    printf("x=%i\n", x);
    printf("y=%i\n", y);

    swapXY();

    printf("x=%i\n", x);
    printf("y=%i\n", y);

    return 0;
}

void swapXY() {
    int temp = x;
    x = y;
    y = temp;
}
