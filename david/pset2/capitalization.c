/*
Description:

Prompts the user for a message, then outputs the message with the
first letter capitalized, and all other letters in alternating case.
Leaves non-alphabetical characters in place.

Author: David Englund
Specification: pset2, page 3
*/

#include <stdio.h>
#include "cs50.h"
#include <string.h>

string myspaceify(string cents);

int main(void) {

    // Get an input string
    printf(
        "Hey myspacer! What myspacey message would you like to myspaceify?\n"
    );
    printf("Da message:\t\t");
    string message = GetString();
    
    // Convert and display new string
    printf("Da myspaced message:\t%s\n", myspaceify(message));
    
    return 0;
}

string myspaceify(string message) {

    // For each character, change even indexed characters to upper-case, 
    // and odd indexes to lower-case
    int i;
    for (i = 0; i < strlen(message); i++ ) {
        message[i] = (i % 2 == 0) ? toupper(message[i]) : tolower(message[i]);
    }

    return message;
}
