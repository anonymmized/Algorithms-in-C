#include <stdio.h>

int binary_search(int *arr, int len, int n) {
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == n) {
            return mid;
        } else if (n > arr[mid]) {
            left = mid + 1;
        } else if (n < arr[mid]) {
            right = mid - 1;
        }
    }
    return -1;
}