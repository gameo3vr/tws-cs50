/*
Description:

Finds the fewest number of coins required to make change.

Author: David Englund
Specification: pset1, page 12
*/

#include <stdio.h>

int fewestCoins(int cents);

int main(void) {

    // Get a number between 2 and 10
    float dollars;
    do {
        printf("O hai! How much change is owed? ");
        scanf("%f", &dollars);
    }
    while (dollars > 10 || dollars <= 0);
    
    // convert dollars to cents
    float cents = dollars * 100;
    
    printf("The fewest coins needed: %i\n", fewestCoins(cents));
    
    return 0;
}

int fewestCoins(int cents) {

    // value to return
    int numberOfCoins = 0;

    // denominations in cents
    int denominations[5] = { 100, 25, 10, 5, 1 };
    
    int i;
    for (i = 0; i < 5; i++) {
        if (denominations[i] <= cents) {
            numberOfCoins += cents / denominations[i];
            cents = cents % denominations[i];
        }
    }
    
    return numberOfCoins;
}
