/*
Description:

Takes an integer as a the height of Mario pyramid and prints the pyramid
to standard output.

Author: David Englund
Specification: pset1, page 10
*/

#include <stdio.h>

void drawPyramid(int height);

int main(void) {

    // Get a number between 2 and 10
    int input;
    do {
        printf("Height: ");
        scanf("%i", &input);
    }
    while (input > 10 || input < 2);
    
    drawPyramid(input);
        
    return 0;
}

void drawPyramid(int height) {

    int i;
    int j;
    for (i = 1; i < height + 1; i++) {
    
        // print blanks
        for (j = 0; j < height - i; j++) {
            printf(" ");
        }
    
        // print blocks
        for (j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}
