// Program to find the All pair shortest path in a graph using Floyd Warshall Algorithm
// Explanation:
/*
    The All pair shortest path problem is to find shortest distances between all pairs of vertices in a given graph. The Floyd Warshall algorithm is an algorithm for finding shortest distances between all pairs of vertices in a given graph.

    It is a dynamic programming algorithm. It uses a matrix to store the intermediate results. The algorithm runs in O(V^3) time.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library

// Defines
#define min(a, b) ((a) < (b) ? (a) : (b))

// allPairShortestPath Function (prints the shortest distance between all pairs of vertices)
// Syntax: allPairShortestPath(adjacencyMatrix, numberOfVertices)
void allPairShortestPath(int **Graph, int V) {
    // Set A0 Matrix
    int **previous = Graph;

    // ALlocating memory for Ak Matrix
    int **next = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        next[i] = (int *)malloc(V * sizeof(int));
    }

    // For each vertex, calculate an Ak matrix
    for (int k = 0; k < V; k++) {
        // Traversing the matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // The actual Floyd Warshall Formula
                next[i][j] = min(previous[i][j], previous[i][k] + previous[k][j]);
            }
        }
        // Update the A<k-1> matrix
        previous = next;
    }

    // Print the matrix
    printf("\nThe shortest distance between all pairs of vertices is:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", next[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < V; i++) {
        free(next[i]);
    }
    free(next);
}

// Main function
int main() {
    // Take input for number of vertices
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Dynamically allocate memory for adjacency matrix
    int **Graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        Graph[i] = (int *)malloc(V * sizeof(int));
    }

    // Take input for adjacency matrix
    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &Graph[i][j]);
        }
    }

    // Call the allPairShortestPath function
    allPairShortestPath(Graph, V);

    // Free the memory
    for (int i = 0; i < V; i++) {
        free(Graph[i]);
    }
    free(Graph);

    return 0;
}