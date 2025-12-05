#include <stdio.h>

// Function: Linear Search
// Purpose: Searches for a target value 'n' in an integer array 'arr' of size 'len'
// Returns: The index of the first occurrence of 'n' if found; otherwise, returns -1
int linear_search(int *arr, int len, int n) {  
    int i; // Declare loop counter variable
    for (i = 0; i < len; i++) { // Iterate trough each element of array from index 0 to len-1
        if (arr[i] == n) { // Check if the current element equals the target value 'n'
            return i; // If found, immediately return the current index
        }
    }
    return -1; // If the loop completes without finding 'n', return -1 (not found)
}