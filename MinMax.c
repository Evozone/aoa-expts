// Program to find the Minimum and Maximum values in an array using recursion in C
// Explanation:
/*
    The minimum and maximum values in an array can be found by finding the minimum and maximum values in the left and right sub-arrays.
    The minimum and maximum values in the left and right sub-arrays can be found recursively.
    The minimum and maximum values in the left and right sub-arrays can be found recursively.

    This is the algorithm:
    MaxMin(Array, Low, High) {
        if (Low == High) then
            Set Max = Min = Array[Low]
        else if (Low == High - 1) then
            if (Array[Low] < Array[High]) then
                Set Max = Array[High]
                Set Min = Array[Low]
            else
                Set Max = Array[Low]
                Set Min = Array[High]
        else
            Set Mid = (Low + High) / 2
            Set sub1 = MaxMin(Array,Low, Mid)
            Set sub2 = MaxMin(Array, Mid + 1, High)

            Set Max = max(sub1.max, sub2.max)
            Set Min = min(sub2.min, sub2.min)

        return Max, Min
    }
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library for malloc() and free()

// Defines
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

// Structure to hold the min and max of a given sub-array
typedef struct arrInfo {
    int min;
    int max;
} ArrI;

// Function that returns a structure containing the min and max of a given sub-array
ArrI *MaxMin(int *arr, int low, int high) {
    // Create a structure to hold the min and max of the sub-array
    ArrI *arrInfo = (ArrI *)malloc(sizeof(ArrI));

    // If the low and high are equal, then the sub-array has only one element
    if (low == high) {
        // Set the min and max of the sub-array to the value of the element
        arrInfo->min = arrInfo->max = arr[low];
    } // If there are only two elements in the sub-array
    else if (low == high - 1) {
        // Using ternary operator to set the min and max of the sub-array
        arrInfo->min = min(arr[low], arr[high]);
        arrInfo->max = max(arr[low], arr[high]);
    } // If there are more than two elements in the sub-array
    else {
        // Find the midpoint of the sub-array without causing overflow
        int mid = low + ((high - low) / 2);

        // Break into sub-arrays

        // Find the min and max of the left sub-array
        ArrI *sub1 = MaxMin(arr, low, mid);
        // Find the min and max of the right sub-array
        ArrI *sub2 = MaxMin(arr, mid + 1, high);

        // Set the min and max of the sub-array to the min and max of the left and right sub-arrays
        // subarray 1 vs sub array 2 in a tournament.
        // First round the min fighters fight, lowest one wins
        // Second round the max fighters fight, highest one wins
        arrInfo->min = min(sub1->min, sub2->min);
        arrInfo->max = max(sub1->max, sub2->max);

        // Free the memory allocated to the left and right sub-arrays
        free(sub1);
        free(sub2);
    }

    // Return the structure containing the min and max of the sub-array
    return arrInfo;
}

// Main function
int main() {

    // Input size of array
    int SIZE;
    printf("Enter the size of the array: ");
    scanf("%d", &SIZE);

    // Input the array
    int *arr = (int *)malloc(SIZE * sizeof(int));
    printf("Enter the array: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the min and max of the array
    ArrI *arrInfo = MaxMin(arr, 0, SIZE - 1);

    // Print the min and max of the array
    printf("The min of the array is %d\n", arrInfo->min);
    printf("The max of the array is %d\n", arrInfo->max);

    // Free the memory allocated to the array
    free(arr);

    return 0;
}