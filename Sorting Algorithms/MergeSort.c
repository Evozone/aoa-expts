// Program to demonstrate Merge Sort in C
// Explanation:
/*
    Merge sort is a sorting algorithm that by recursively splitting the list into two parts, the sorted part and the unsorted part, and then merging the two parts.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library for malloc() and free()

// The merge function
void merge(int *arr, int l, int m, int h) {
    // Calculate the size of the left and right sub-arrays
    int n1 = m - l + 1;
    int n2 = h - m;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to the temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays
    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        // Tournament mode.
        // Left array vs Right array
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}

// Merge sort function
void mergeSort(int arr[], int low, int high) {
    // If the low index is greater than the high index, the list is sorted
    if (low < high) {
        // Calculate the middle index
        int mid = (low + high) / 2;

        // Recursively sort the left half of the list
        mergeSort(arr, low, mid);

        // Recursively sort the right half of the list
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
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
    printf("Enter %d elements : ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Calling the merge sort function
    mergeSort(arr, 0, SIZE - 1);

    // Printing the sorted array with [ , , ]
    printf("Sorted array: [");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", arr[i]);
        if (i < SIZE - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Freeing the memory
    free(arr);

    return 0;
}