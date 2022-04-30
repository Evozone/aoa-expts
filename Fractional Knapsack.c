// Program to demonstrate Fractional Knapsack in C
// Explanation:
/*
    The fractional knapsack problem states that given a set of items, each with a weight and a value,
    and a maximum weight capacity, find the maximum value you can obtain by fitting the items in your knapsack.
    The problem is to fill the knapsack with items, so that the total weight is less than or equal to the
    maximum capacity.

    The maximum capacity is traditionally denoted by W.

    Since this is a fractional knapsack problem, we can use fractions of the items to fill the knapsack.
    The fractional knapsack problem is solved using greedy algorithm.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library

// Float swapper
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum value of the fractional knapsack
float fracKnapSack(float *prices, float *weights, int size, float W) {
    // Sort list of items by price/weight ratio (Bubble Sort)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // If the price/weight ratio of the current item is less than the price/weight ratio of the next item, swap them
            if (prices[j] / weights[j] < prices[j + 1] / weights[j + 1]) {
                swap(&prices[j], &prices[j + 1]);
                swap(&weights[j], &weights[j + 1]);
            }
        }
    }

    // Sum of prices in knapsack
    float sum = 0;

    // For each item in list, if it fits, add it to the knapsack
    // If it doesn't fit, add the fraction of the item to the knapsack
    for (int i = 0; i < size; i++) {
        // If the current item fits in the knapsack
        if (weights[i] <= W) {
            sum += prices[i];
            W -= weights[i];
        } else {
            // If the current item doesn't fit in the knapsack, add the fraction of the item to the knapsack
            sum += prices[i] / weights[i] * W;
            W = 0;
        }
    }

    return sum;
}

// Main function
int main() {

    // Input Number of items
    int size;
    printf("Enter the number of items: ");
    scanf("%d", &size);

    // Input the weights and prices of the items
    float *prices = (float *)malloc(sizeof(float) * size);
    float *weights = (float *)malloc(sizeof(float) * size);

    for (int i = 0; i < size; i++) {
        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &prices[i]);
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%f", &weights[i]);
    }

    // Input the maximum capacity of the knapsack
    float W;
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%f", &W);

    // Print the maximum value of the fractional knapsack
    printf("The maximum value of the fractional knapsack is %0.2f\n", fracKnapSack(prices, weights, size, W));

    // Free memory
    free(prices);
    free(weights);

    return 0;
}
