// Program to demonstrate Prim's Algorithm in C
// Explanation:
/*
    Prim's algorithm is a greedy algorithm that finds a minimum spanning tree (MST) in a connected, undirected and weighted graph.

    The MST is a subset of the edges of the graph that forms a tree with a total weight less than or equal to the total weight of all the other edges in the graph.

    Prim's algorithm maintains two sets, one set of vertices that are in the MST and the other set of vertices that are not in the MST.

    Imagine a classroom where people plan to go to a club. Initially, there are none who are invited.
    Pick one who is invited.
    Consider all friends of club members who are not invited.
    The closest friend is the one who is now invited and joins the club.
    Repeat this process until all the people are invited.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard library

// Main function
int main() {
    // Take input for number of vertices
    int num;
    printf("Enter the number of vertices: ");
    scanf("%d", &num);

    // Dynamically allocate memory for the graph
    int **adjMatrix = (int **)malloc(num * sizeof(int *));
    for (int i = 0; i < num; i++) {
        adjMatrix[i] = (int *)malloc(num * sizeof(int));
    }

    // Insert weights into the graph
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &adjMatrix[i][j]);
            // If the weight is 0, then set it to infinity
            if (adjMatrix[i][j] == 0) {
                adjMatrix[i][j] = INT_MAX;
            }
            // Also add to mirror edge
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }

    // Create a visited array and set all vertices to unvisited
    int *visited = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        visited[i] = 0;
    }

    // Variables
    int min = INT_MAX;   // A variable to get the minimum weight edge. Initialize it to infinity
    int v1, v2;          // Two vertices of the edge
    int numVisited = 0;  // Number of vertices visited
    int totalWeight = 0; // Total weight of the MST

    // Visit the first vertex, vertex 0
    visited[0] = 1;
    numVisited++;

    // While there are unvisited vertices and the number of vertices visited is less than the number of vertices
    while (numVisited < num) {
        // Find the minimum weight edge (Iterate through the adjacency matrix)
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                // If the first vertex is in MST and the second vertex is not in MST
                // (the edge is across the border)
                if (adjMatrix[i][j] < min && visited[i] != 0 && visited[j] == 0) {
                    // Update the minimum weight edge
                    min = adjMatrix[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }

        // Add the edge to the MST
        printf("Edge %d-%d is added to the MST\n", v1, v2);
        totalWeight += min;

        // Mark the vertices as visited
        visited[v1] = 1;
        visited[v2] = 1;

        // Reset the minimum weight
        min = INT_MAX;
        numVisited++;
    }

    // Print the total weight of the MST
    printf("Total weight of the MST is %d\n", totalWeight);

    // Free the memory
    for (int i = 0; i < num; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(visited);

    return 0;
}