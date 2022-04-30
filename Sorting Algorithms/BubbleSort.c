// Program to demonstrate bubble sort in C
// Explanation:
/*
    Bubble sort is a sorting algorithm that works by iterating through the list of elements and finding the largest element in the list and then swapping it continuously until it reaches the end of the list.
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

// Bubble sort function
void bubbleSort(int arr[], int size) {
    int i, j;

    // Sorting the array
    // Iterating through the array upto size-1 as the
    // final element is already sorted if all others are sorted
    for (i = 0; i < size - 1; i++) {
        // Iterating through the array from 0 to size-1-i
        // as we don't want to sort the already sorted elements
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    // Printing the sorted array with [ , , ]
    printf("Sorted array: [");
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
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
    printf("Enter %d elements: ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Calling the bubble sort function
    bubbleSort(arr, SIZE);

    // Freeing the memory
    free(arr);

    return 0;
}