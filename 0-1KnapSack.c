// Program to demonstrate 0-1 knapsack problem in C
// Explanation:
/*
    This program is to demonstrate the 0-1 knapsack problem in C.
    The program takes the following inputs:
    1. The number of items
    2. The weight of each item
    3. The value of each item
    4. The weight of the knapsack

    The program outputs the following:
    1. The maximum value that can be obtained
    2. The items that can be obtained

    The 0-1 knapsack problem is similar to the fractional knapsack problem, but the knapsack is not allowed to contain more than one item of the same type. The problem is to find the maximum value that can be obtained by selecting items from the given set of items, while keeping the total weight of the knapsack below or equal to the given weight.

    This problem can be solved using Dynamic Programming.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library

// Defines
#define max(a, b) ((a) > (b) ? (a) : (b))

// 0-1 Knapsack Function, it returns the maximum value of knapsack
int knapsack(int capacity, int *weights, int *profits, int num) {
    // If the number of items is 0 or the capacity is 0, return 0
    if (num == 0 || capacity == 0) {
        return 0;
    }

    // If the weight of the last item is greater than the capacity, then this item cannot be included
    if (weights[num - 1] > capacity) {
        // Since the last item cannot be included, recursively call the function with one less
        return knapsack(capacity, weights, profits, num - 1);
    } else {
        // If the weight of the last item is less than or equal to the capacity, then this item can be included

        // Is it worth including the last item?
        // Basically, does including the last item give us a better value than not including it?
        return max(profits[num - 1] + knapsack(capacity - weights[num - 1], weights, profits, num - 1), knapsack(capacity, weights, profits, num - 1));
    }
}

// Main Function
int main() {
    // Declare variables
    int capacity, num, i;

    // Read the number of items
    printf("Enter the number of items: ");
    scanf("%d", &num);

    // Dynamically allocate memory for the weights and profits
    int *weights = (int *)malloc(num * sizeof(int));
    int *profits = (int *)malloc(num * sizeof(int));

    // Read the weights and profits
    printf("Enter the weights of the items:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the profits of the items:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &profits[i]);
    }

    // Read the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Print the maximum value that can be obtained
    printf("The maximum value that can be obtained is %d\n", knapsack(capacity, weights, profits, num));

    // Free the memory
    free(weights);
    free(profits);

    return 0;
}
