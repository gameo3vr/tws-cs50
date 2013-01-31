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

int success = 0;

const int HASH_LENGTH = 13;
const int MAX_PASSWORD_LENGTH = 8;

static const char characters[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 
    'g', 'h', 'i', 'j', 'k', 'l', 
    'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};
#define NUMBER_OF_CHARACTERS (sizeof characters / sizeof characters[0])

// Hashes current password and sets "success" variable if the hash is right.
int isSuccess(const char* hash, const char* c_pass);

int main(int argc, char *argv[]) {

    // "passwd" with "key" salt --> kemQPjuDipCXk
    // "baxl" with "key" salt --> keZ65gKAD4WBQ
    // "z" with "key" salt --> keh5AlYTCEIAA
    // "zal" with "key" salt --> keNHbPt353EuQ
    // "passw" with "key" salt --> kejXjhKbHIstE
    
    // printf("%s\n", crypt("passw", "key"));
    
    // Needs exactly one argument
    if (argc != 2) {
        printf("No hash provided. Usage: `crack.exe HASH`\n");
        return 1;
    }
    
    // Store the hash
    string hash = argv[1];
    
    // Go through each password
    int length;
    int character;
    string c_hash;
    //char c_pass[MAX_PASSWORD_LENGTH];
    char c_pass[] = {
        NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL
    };
    char* p_c_pass = c_pass;
    int i, j, k, l, m, n, o, p, x;
    
    // Assume: MAX_PASSWORD_LENGTH < number of characters possible
    // create all passwords for all password lengths
    
    // each password length
    for (length = 1; length <= MAX_PASSWORD_LENGTH; length++) {
        
        // first letter
        for (i = 0; i < NUMBER_OF_CHARACTERS; i++) {
            c_pass[0] = characters[i];
            if (1 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
            
        // second letter
        for (j = 0; j < NUMBER_OF_CHARACTERS; j++) {
            c_pass[1] = characters[j];
            if (2 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
            
        // third letter
        for (k = 0; k < NUMBER_OF_CHARACTERS; k++) {
            c_pass[2] = characters[k];
            if (3 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
            
        // fourth letter
        for (l = 0; l < NUMBER_OF_CHARACTERS; l++) {
            c_pass[3] = characters[l];
            if (4 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
        
        // fifth letter
        for (m = 0; m < NUMBER_OF_CHARACTERS; m++) {
            c_pass[4] = characters[m];
            if (5 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
        
        // sixth letter
        for (n = 0; n < NUMBER_OF_CHARACTERS; n++) {
            c_pass[5] = characters[n];
            if (6 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
        
        // seventh letter
        for (o = 0; o < NUMBER_OF_CHARACTERS; o++) {
            c_pass[6] = characters[o];
            if (7 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
        
        // eighth letter
        for (p = 0; p < NUMBER_OF_CHARACTERS; p++) {
            c_pass[7] = characters[p];
            if (8 == length) { if (isSuccess(hash, p_c_pass) == 1) { return 0; } else { continue; } }
        }
        }
        }
        }
        }
        }
        }
        }
        
    }
    
    printf("couldn't figure out password\n");
    return 0;
}

int letter;
char* c_pass_hash;
int isSuccess(const char* hash, const char* c_pass) {
    
    // Construct hash from c_pass
    c_pass_hash = crypt(c_pass, "key");
    
    // check for success with this password
    for (letter = 0; letter < HASH_LENGTH; letter++) {
    
        if (c_pass_hash[letter] != hash[letter]) {
            // printf("no success with %s", c_pass);
            // printf(" and hash %s\n", c_pass_hash);
            return 0;
        }
    }
    
    // If we made it through and found no differences, then this is the right password.
    printf("success with %s\n", c_pass);
    return 1;
}
