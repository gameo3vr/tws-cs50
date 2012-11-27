/*
Description:

Converts user-inputed temperature in degrees Celsius to
degrees Farenheit and displays the result with only one
digit after the decimal.

Author: David Englund
Specification: pset1, page 8
*/

#include <stdio.h>

float convertCelciusToF(float);

int main(void) {
    
    // Prompt for temperature in celcius to convert
    printf("C: ");
    
    // Get user input
    float tempInCelcius;
    scanf("%f", &tempInCelcius);
    
    // Convert from Celcius to F.
    float tempInF = convertCelciusToF(tempInCelcius);
    
    // Display the converted result
    printf("F: %4.1f\n", tempInF);
    
    return 0;
}

float convertCelciusToF(float celcius) {
    return celcius * 1.8 + 32.0;
}
