// Program to demonstrate Naive String Matching in C
// Explanation:
/*
    Naive String Matching is a string matching algorithm that uses brute force to find the first occurrence of a pattern in a text.
    It's complexity is O(n*m) where n is the length of the text and m is the length of the pattern.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library
#include <string.h> // String Library

// Defines
#define BUFFER_SIZE 1024

// Naive String Matching function
// Syntax : naiveStringMatching(text, pattern, textSize, patternSize)
void naiveStringMatching(char *text, char *pattern, int textSize, int patternSize) {
    // Loop through the text
    for (int i = 0; i < textSize - patternSize + 1; i++) {
        // Loop through the pattern
        for (int j = 0; j < patternSize; j++) {
            // Condition for no match found
            if (i == textSize - patternSize && text[i+j] != pattern[j]) {
                printf("Match not found.");
                break;
            }
            // If the current character in the text is not equal to the current character in the pattern, break
            if (text[i + j] != pattern[j]) {
                break;
            }
            // If the current character in the text is equal to the current character in the pattern, check if it is the last character
            if (j == patternSize - 1) {
                // If it is the last character, print the index
                printf("Match found at index %d\n", i);
            }
        }
    }
}

// Main function
int main() {
    // Take input from user for the text and pattern
    char text[BUFFER_SIZE];
    char pattern[BUFFER_SIZE];

    // Take input from user for the text using scanf with spaces
    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);

    // Take input from user for the pattern using scanf
    printf("Enter the pattern: ");
    scanf("%[^\n]%*c", pattern);

    // Get the size of the text and pattern
    int textSize = strlen(text);
    int patternSize = strlen(pattern);

    // Call the naive string matching function
    naiveStringMatching(text, pattern, textSize, patternSize);

    return 0;
}
