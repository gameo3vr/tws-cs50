#include <stdio.h>
#include <stdlib.h>

// Simply print the contents of an array
void printArray(int array[], int size) {

    printf("{ ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%i, ", array[i]);
    }
    printf("}\n");
}

int* getSubArray(int arr[], int start, int end) {

    // Allocate return array
    int subSize = end - start;
    int* sub = malloc(subSize * sizeof(int));
    
    // Go through the first half of the elements
    int s = 0;
    int a = start;
    while (a < end) {
        sub[s] = arr[a];
        s++;
        a++;
    }
    
    // Return the new array
    return sub;
}

// sort using merge sort algorithm
void sort(int array[], int size) {
    
    if (size < 2) {
        return;
    }
    else {
    
        // sort left half
        int* leftHalf = getSubArray(array, 0, size/2);
        sort (leftHalf, size/2);
    
        // sort right half
        int* rightHalf = getSubArray(array, size/2, size);
        sort (rightHalf, size/2);
        
        // merge halves
        int i;
        int l = 0;
        int r = 0;
        for (i = 0; i < size; i++) {
            if (r != size/2 && rightHalf[r] < leftHalf[l]) {
                array[i] = rightHalf[r];
                r++;
            }
            else if (l != size/2 && leftHalf[l] < rightHalf[r]) {
                array[i] = leftHalf[l];
                l++;
            }
        }
        
        // clean up
        free(rightHalf);
        free(leftHalf);
        
        return;
    }
}

int main(void) {

    // starting list
    int size = 8;
    int numbers[] = { 80, 15, 16, 50, 10, 23, 42, 99 };

    // sorted list
    printArray(numbers, size);
    sort(numbers, size);
    printArray(numbers, size);
    
    return 0;
}
