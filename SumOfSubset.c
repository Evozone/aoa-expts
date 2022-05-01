// Program to find the sum of subset of a given array and print the sum of all subsets of a given array that add up to a given number
// Explanation:
/*
    The problem is to find the sum of all subsets of a given array that add up to a given number.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library

// Print subsets found
void printSubset(int *subset, int size) {
    // Use {}
    printf("\n{");
    for (int i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

// subsetSum function (recursive)
// Syntax : subsetSum(given Array, size of array, sum to be found, current partial sum, current subset, current subset size, pointer to an element of given Array)
void subsetSum(int *arr, int *tup, int size, int tupSize, int nodePtr, int partialSum, int const targetSum) {
    // If the current partial sum is equal to the sum, print the subset
    if (partialSum == targetSum) {
        // We have found a subset
        printSubset(tup, tupSize);

        // constraint check
        // nodePtr is the last element of the subset
        // Check if removing it and adding the next element will not violate the constraint
        if (nodePtr + 1 < size && partialSum - arr[nodePtr] + arr[nodePtr + 1] <= targetSum) {
            // Exclude last element and consider next candidate
            subsetSum(arr, tup, size, tupSize, nodePtr + 1, partialSum - arr[nodePtr], targetSum);
            // Here
            // arr is the array to be considered
            // size is the size of the array
            // targetSum is the sum to be found
            // partialSum is updated to remove the last element
            // subset is the purse which contains the subset
            // subsetSize is updated to remove the last element
            // nodePtr is the pointer to the last element of the subset, it is updated to point to the next element
        }
        return;
    } else {
        // If the current partial sum is not equal to the sum, consider adding the next element
        // If the current partial sum + the next element is less than the sum, add the next element
        if (partialSum + arr[nodePtr] <= targetSum && nodePtr < size) {
            // Generate nodes along the breadth

            // Using for loop to generate nodes from node ptr to the end of the array
            for (int i = nodePtr; i < size; i++) {
                // Put the current element in the subset
                tup[tupSize] = arr[i];

                // If still the sum is not equal to the target sum, consider adding the next element
                if (partialSum + arr[i] <= targetSum) {
                    // Recursive call
                    subsetSum(arr, tup, size, tupSize + 1, i + 1, partialSum + arr[i], targetSum);
                    // Here
                    // arr is the array to be considered
                    // size is the size of the array
                    // targetSum is the sum to be found
                    // partialSum is the sum after adding current node
                    // subset is the purse which contains the subset
                    // subsetSize is the size of the subset
                    // nodePtr is updated to point to the next element
                }
            }
        }
    }
}

// Wrapper function to compute all the subsets
void subsetsEqualToSum(int *arr, int size, int targetSum) {
    // A purse to keep track of which elements form a subset
    int *tupletVector = (int *)malloc(size * sizeof(int));

    // Calculate the total sum of the array
    int totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += arr[i];
    }

    // Sort the array (optional)
    // Selection sort
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // If the targetSum is more than the smallest element and lower than the total sum,
    if (targetSum >= arr[0] && targetSum <= totalSum) {
        // Call function on the first element node
        subsetSum(arr, tupletVector, size, 0, 0, 0, targetSum);
    }

    // Free the memory
    free(tupletVector);
}

// Main function
int main() {

    // Take input for the number of elements
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Take input for the elements
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Take input for the sum
    int targetSum;
    printf("Enter the sum: ");
    scanf("%d", &targetSum);

    // Call the function
    subsetsEqualToSum(arr, size, targetSum);

    // Free the memory
    free(arr);

    return 0;
}