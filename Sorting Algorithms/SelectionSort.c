// Program to demonstrate selection sort in C
// Explanation:
/*
    Selection sort is a sorting algorithm that works by iterating through the list of elements and finding the smallest element in the list and then swapping it with the first element in the list.
    The algorithm is repeated until the list is sorted.
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

// Selection sort function
void selectionSort(int arr[], int size) {
    int i, j, min_index;

    // Sorting the array
    for (i = 0; i < size - 1; i++) {
        // Initializing the minimum index with
        // the first element of the unsorted array
        min_index = i;
        // Finding the index of the minimum element
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swapping the minimum element with the first element of the unsorted array
        swap(&arr[i], &arr[min_index]);
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
    printf("Enter Array : \n");
    for (short k = 0; k < SIZE; k++) {
        scanf("%d", &arr[k]);
    }

    // The actual function that is called
    selectionSort(arr, SIZE);

    // Freeing the memory
    free(arr);

    return 0;
}