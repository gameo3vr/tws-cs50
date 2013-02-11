#include "cs50.h"
#include <stdio.h>
#define SIZE 8

bool search(int needle, int haystack[], int size) {
    // return true if needle is in haystack, using binary search
    int i;
    for (i = 0; i < SIZE; i++) {
        
        // Check to see if this element in the haystack is the needle.
        if (haystack[i] == needle) {
            return true;
        }
    }
    
    // If we looped through all elements but did not find the needle,
    // return false, indicating that the needle is not in the haystack.
    return false;
}

int main(void) {
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("Enter the integer to search for: ");
    int n = GetInt();
    if (search(n, numbers, SIZE)) {
        printf("That number was found.\n");
    }
    else {
        printf("That number was not found.\n");
    }
    return 0;
}
