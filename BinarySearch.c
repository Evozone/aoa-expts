// Program to demonstrate binary search in C
// Explanation:
/*
    Binary search is a search algorithm that works by comparing the middle element of the list with the target element.
    - If the target element is greater than the middle element, the search continues in the right half of the list.
    - If the target element is less than the middle element, the search continues in the left half of the list. - - If the target element is found, the search is over.
    - If the target element is not found, the search continues in the next iteration.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library

// Binary Search Function
int binarySearch(int *array, int low, int high, int target) {
    // If the low index is greater than the high index, the target element is not found
    if (low > high) {
        return -1;
    }

    // Calculate the middle index without causing overflow
    int mid = low + ((high - low) / 2);

    // If the target element is found, return the index
    if (array[mid] == target) {
        return mid;
    } else if (array[mid] > target) {
        // If the target element is less than the middle element, the search continues in the left half of the list
        return binarySearch(array, low, mid - 1, target);
    } else {
        // If the target element is greater than the middle element, the search continues in the right half of the list
        return binarySearch(array, mid + 1, high, target);
    }

    // If the target element is not found, then return -1
    return -1;
}

// Main Function
int main() {
    // Input for array size
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Dynamically allocate array
    int *array = (int *)malloc(sizeof(int) * size);

    // Input for array elements
    printf("Enter elements of array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Input for target element
    int target;
    printf("Enter target element: ");
    scanf("%d", &target);

    // Call binary search function
    int index = binarySearch(array, 0, size - 1, target);

    // Print index
    if (index == -1) {
        printf("Target element not found\n");
    } else {
        printf("Target element found at index %d\n", index);
    }
    return 0;
}