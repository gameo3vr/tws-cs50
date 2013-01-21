/*
Description:

Divides numerator/denominator and produces the result as
a percentage. If the user inputs invalid numerator or
denominator, the program continues to prompt the user until
a valid value is supplied.

Author: David Englund
Specification: pset1, page 9
*/

#include <stdio.h>

// Continue prompting the user until a valid value is supplied
float promptForNumber(const char* message, float minValue);

int main(void) {
    
    // Prompt for numerator
    float numerator = promptForNumber("non-negative numerator: ", 0.0);
    
    // Prompt for denominator
    float denominator = promptForNumber("positive denominator: ", 1.0);
    
    // Calculate numerator/denominator as percent
    float percent = numerator / denominator * 100.0;
    
    // Display the converted result
    printf("Percent: %4.1f\n", percent);
    
    return 0;
}

float promptForNumber(const char* message, float minValue) {
    
    float input;
    do {
        // Prompt user using the given message
        printf("%s", message);
        
         // Get user input
        scanf("%f", &input);
    }
    while (input < minValue);
    
    return input;
    
}
