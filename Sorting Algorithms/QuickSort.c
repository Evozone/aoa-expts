// Program to demonstrate Quick Sort in C
// Explanation:
/*
    Quick sort is a sorting algorithm that works by selecting a pivot element and then splitting the list into two parts, a greater part and a smaller part.
    The algorithm works by selecting the pivot element and then separating the array into two parts, the left and right part.
    The left part is smaller than the pivot element and the right part is greater than the pivot element.
    Then the pivot is placed in the correct position.
    The left and right sub-arrays are then sorted recursively.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library for malloc() and free()

// Do NOT use XOR swap or you will lose the data (XOR with self = 0)
// The compiler is smart enough to optimize it for you.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// The partition function (partitioning the array into greater than and smaller than parts)
// Returns the index of the pivot element
int partition(int *arr, int low, int high) {
    // Pivot element
    int pivot = arr[high];

    // Index of scanner (starts at the left)
    int i = (low - 1);

    // Iterating through the array
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment the index of the scanner
            i++;
            // Swap the current element with the element at the index of the scanner
            swap(&arr[i], &arr[j]);
        }
        // Don't do anything if the current element is greater than the pivot
    }
    // Put the pivot in between the smaller and greater parts
    swap(&arr[i + 1], &arr[high]);
    // Return the location of the pivot
    return (i + 1);
}

// Quick sort function
void quickSort(int *arr, int low, int high) {
    // If the array has more than one element
    if (low < high) {
        // Get the pivot index
        int pi = partition(arr, low, high);
        // pi shows where the array is to be broken

        // Sort the left part
        quickSort(arr, low, pi - 1);
        // Sort the right part
        quickSort(arr, pi + 1, high);
    }
}

// Main function
int main() {
    // Array size input
    int SIZE;
    printf("Enter number of Elements in Array : ");
    scanf("%d", &SIZE);

    // Dynamic array creation
    int *arr = (int *)malloc(SIZE * sizeof(int));

    // Array input
    printf("Enter Array : \n");
    for (short k = 0; k < SIZE; k++) {
        scanf("%d", &arr[k]);
    }

    // Calling the quick sort function
    quickSort(arr, 0, SIZE - 1);

    // Printing the sorted array with [ , , ]
    printf("Sorted array: [");
    for (short k = 0; k < SIZE; k++) {
        printf("%d", arr[k]);
        if (k < SIZE - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Freeing the memory
    free(arr);

    return 0;
}