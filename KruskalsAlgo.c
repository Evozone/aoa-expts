// Program to demonstrate Kruskal's Algorithm in C
// Explanation:
/*
    Kruskal's Algorithm is used to find the minimum spanning tree of a connected, undirected and weighted graph.
    The algorithm works by choosing the smallest edge and adding it to the tree.
    The algorithm is guaranteed to find a spanning tree if the graph is connected.
    The algorithm is also guaranteed to find a spanning tree if the graph is connected and has no negative edges.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library

// Utility Function to find the subset of an element i
int find(int parent[], int i) {
    // While the parent of i is not -1
    while (parent[i] != -1) {
        // Set i to the parent of i
        i = parent[i];
    }
    // Return i
    return i;
}

// Utility Function to do union of two subsets (Returns whether union was successful)
int Union(int parent[], int x, int y) {
    // If the vertices are not the same, then set the parent of y to x
    if (x != y) {
        parent[y] = x;
        return 1;
    }
    // Otherwise, return 0
    return 0;
}

// Main function
int main() {
    // Take input for number of vertices
    int vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Dynamically allocate memory for adjacency matrix
    int **adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Take input for adjacency matrix
    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
            // If the value is 0, then set the edge to infinity
            if (adjMatrix[i][j] == 0) {
                adjMatrix[i][j] = INT_MAX;
            }
            // Mirror the adjacency matrix
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }

    // Array to hold the subset of vertices
    int *parent = (int *)malloc(vertices * sizeof(int));

    // Initialize the parent array to -1
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
    }

    // Miscellaneous variables
    int minEdge = INT_MAX, // Minimum edge
        minEdgeWeight = 0, // Minimum edge weight
        v1 = 0,            // First vertex
        v2 = 0,            // Second vertex
        a, b,              // Temporary variables
        numVisited = 0;    // Number of visited vertices

    // Kruskal's Algorithm

    // While there are still unvisited vertices
    while (numVisited < vertices) {
        // Take the minimum edge
        minEdge = INT_MAX;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                // If the edge is smaller than the minimum edge
                if (adjMatrix[i][j] < minEdge) {
                    // Set the minimum edge to the edge
                    minEdge = adjMatrix[i][j];
                    // Set the vertices to the vertices
                    a = v1 = i;
                    b = v2 = j;
                }
            }
        }
        v1 = find(parent, v1);
        v2 = find(parent, v2);
        // If the union is successful
        if (Union(parent, v1, v2)) {
            // Increment the number of visited vertices
            numVisited++;
            // Add the edge to the minimum spanning tree
            printf("Edge %d-%d is added to the MST\n", v1, v2);
            // Add the edge weight to the minimum spanning tree weight
            minEdgeWeight += minEdge;
        }
        // Set the edge to infinity
        adjMatrix[a][b] = adjMatrix[b][a] = INT_MAX;
    }

    // Print the minimum spanning tree weight
    printf("The minimum spanning tree weight is: %d\n", minEdgeWeight);

    // Free the memory
    free(parent);
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}