/*
Description:

Takes a word as a command line argument, and checks whether the word is
present on a list of known English words. Prints "YES" if the word is an
English word or "NO" if the word is not English.

Author: David Englund
Specification: pset2, page 4
*/

#include <stdio.h>
#include "cs50.h"
#include <string.h>

// Dictionary filename
string filename = "linux.words";

// Reads dictionary and look for word. Quits as soon as the word is found.
// Returns 0 if not found, 1 if found
int isInDictionary(string word);

int main(int argc, char *argv[]) {

    // Needs exactly one argument
    if (argc != 2) {
        printf("No word provided. Usage: `dictionary.exe WORD`\n");
        return 1;
    }
    
    // Store the word
    string word = argv[1];
    
    // Test word and indicate result
    if (1 == isInDictionary(word)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}

int isInDictionary(string word) {

    // Open the dictionary
    FILE* filestream = fopen(filename, "r");
    
    int wordFound = 0;
    
    // Read the dictionary until either the word is found, or the end of the
    // dictionary is reached
    char line[128];
    int i;
    int wordLength = strlen(word);
    int diffFound;
    while (0 == wordFound && fgets(line, sizeof(line), filestream) != NULL) {
    
        // If the words are of different lengths, then they are not the same
        // word, so check the next word. The line does have a newline on the
        // end, so the dictionary word is 1 character longer than the stored word
        if (wordLength != strlen(line) - 1) {
            continue;
        }

        // Loop through the characters of the word to see if there are any 
        // differences with the word in the dictionary.
        diffFound = 0;
        for (i = 0; i < wordLength; i++ ) {
            if (word[i] != line[i]) {
                diffFound = 1;
                break;
            }
        }
        
        // If we looped through each of the characters with no differences,
        // then the word is the same as the word in the dictionary.
        wordFound = !diffFound;
    }
    
    // Close the dictionary
    fclose(filestream);

    // Return the appropriate result
    return wordFound;
}
