// // Program to demonstrate insertion sort in C
// Explanation:
/*
    Insertion sort is a sorting algorithm that works by splitting the list into two parts, the sorted part and the unsorted part.
    The algorithm works by iterating through the unsorted part and selecting the element to be inserted into the sorted part. Then it looks for the correct position to insert the element.
    The algorithm is repeated until the list is sorted.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library for malloc() and free()

// Insertion sort function
void insertionSort(int arr[], int SIZE) {
    int i, j, box;

    // Sorting the array
    for (i = 1; i < SIZE; i++) {
        // Store the value to be inserted in a box for later use.
        box = arr[i];

        // Iterate through the sorted part of the array in reverse order
        j = i - 1; // j is the index of the last element in the sorted part of the array

        // Compare the box with the element in the sorted part of the array
        while (j >= 0 && arr[j] > box) {
            // Push any element greater than the box's content to the right
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insert the item in the box into the sorted part of the array
        arr[j + 1] = box;
    }

    // Printing the sorted array with [ , , ]
    printf("Sorted array: [");
    for (i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
        if (i < SIZE - 1) {
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
    printf("Enter %d elements : ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Calling the insertion sort function
    insertionSort(arr, SIZE);

    // Freeing the memory
    free(arr);

    return 0;
}