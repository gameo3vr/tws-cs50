/*
Description:

Takes a hashed password as a command line argument, and attempts to determine
the clear text password associated with that hash.

Author: David Englund
Specification: pset2, page 5
*/

#include <stdio.h>
#include "cs50.h"
#include <string.h>


// Dictionary filename
string filename = "linux.words";

const int MAX_PASSWORD_LENGTH = 7;

static const char characters[] = {
    'a', 'b', 'c', '1', '2', '3'
};
#define NUMBER_OF_CHARACTERS (sizeof characters / sizeof characters[0])

int main(int argc, char *argv[]) {


    // printf("%c\n", characters[0]);
    // printf("%c\n", characters[1]);
    // printf("%c\n", characters[2]);
    // printf("%c\n", characters[3]);
    // return 1;


    // Needs exactly one argument
    if (argc != 2) {
        printf("No hash provided. Usage: `crack.exe HASH`\n");
        return 1;
    }
    
    // Store the hash
    string hash = argv[1];
    
    // "passwd" with "key" salt --> kemQPjuDipCXk
    
    // Go through each password
    int length;
    int character;
    string c_hash;
    char c_pass[MAX_PASSWORD_LENGTH];
    int i, j, k, l, m, n, o, x;
    
    // Assume: MAX_PASSWORD_LENGTH < number of characters possible
    // create all passwords for all password lengths
    for (length = 7; length <= MAX_PASSWORD_LENGTH; length++) {
    
        for (i = 0; i < NUMBER_OF_CHARACTERS; i++) {
            printf("i=%i\n", i);
        for (j = 0; j < NUMBER_OF_CHARACTERS; j++) {
            printf("j=%i\n", j);
        for (k = 0; k < NUMBER_OF_CHARACTERS; k++) {
        for (l = 0; l < NUMBER_OF_CHARACTERS; l++) {
        for (m = 0; m < NUMBER_OF_CHARACTERS; m++) {
        for (n = 0; n < NUMBER_OF_CHARACTERS; n++) {
        for (o = 0; o < NUMBER_OF_CHARACTERS; o++) {
                        
            c_pass[0] = characters[i];
            c_pass[1] = characters[j];
            c_pass[2] = characters[k];
            c_pass[3] = characters[l];
            c_pass[4] = characters[m];
            c_pass[5] = characters[n];
            c_pass[6] = characters[o];
            
            // check
            // printf("password=");
            // for (x = 0; x < length; x++) {
                // printf("%c", c_pass[x]);
            // }
            // printf("\thash=%s", crypt(c_pass, "key"));
            // printf("\n");
            crypt(c_pass, "key");
        }
        }
        }
        }
        }
        }
        }
    }
/*        
        // check for success with this password
        if (crypt(c_pass, "key") == hash) {
            printf("success with %s\n", c_pass);
        }
        else {
            printf("no success with %s\n", c_pass);
        }
*/        
    
    
    printf("%s\n", crypt("passwd", "key"));
    printf("%s\n", crypt("abc123", "key"));
    
    return 0;
}
