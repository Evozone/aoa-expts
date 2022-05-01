// Program to find the Longest Common Subsequence of two strings
// Explanation:
/*
    The Longest Common Subsequence problem is to find a subsequence of one string that is a subsequence of another string. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, "abc" is a subsequence of "abcdef", but not a subsequence of "abxdef".
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library
#include <string.h> // String Library

// Defines
#define max(a, b) ((a) > (b) ? (a) : (b))
#define BUFFER_SIZE 10000

// Longest Common Subsequence Function (returns the length of the LCS)
int lcs(char *X, char *Y, int lenX, int lenY) {
    // Iterators
    int i, j;
    // Dynamically Allocate Memory for the LCS Matrix
    int **lcs = (int **)malloc(sizeof(int *) * (lenX + 1));
    for (i = 0; i <= lenX; i++) {
        lcs[i] = (int *)malloc(sizeof(int) * (lenY + 1));
    }

    // Fill the Matrix
    for (i = 0; i <= lenX; i++) {
        for (j = 0; j <= lenY; j++) {
            // Make the first row and column 0
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                // If the characters are equal, add 1 to the top-left diagonal element
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                // If the characters are not equal, take the max of the top and left elements
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    // Store the length of the LCS in a variable
    int result = lcs[lenX][lenY];

    // Free the dynamically allocated memory
    for (i = 0; i <= lenX; i++) {
        free(lcs[i]);
    }
    free(lcs);

    // Return the length of the LCS
    return result;
}

// Main Function
int main() {
    // Create static strings for the two strings
    char X[BUFFER_SIZE];
    char Y[BUFFER_SIZE];

    // Read the strings from the standard input
    scanf("%s", X);
    scanf("%s", Y);

    // Find the length each string
    int lenX = strlen(X);
    int lenY = strlen(Y);

    // Print the length of the LCS
    printf("The length of the LCS is %d\n", lcs(X, Y, lenX, lenY));

    return 0;
}