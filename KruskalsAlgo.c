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

// Structure to store the edges
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// Compare function to sort the edges
int compare(const void *a, const void *b) {
    return ((*(Edge *)a).weight - (*(Edge *)b).weight);
}

// Utility Function to find the subset of an element i
int find(int parent[], int i) {
    // While the parent of i is not -1
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Utility Function to do union of two subsets (Returns whether union was successful)
int Union(int parent[], int x, int y) {
    // Find the subsets of x and y
    parent[x] = y;
}

// Kruskal's Algorithm
int kruskalMST(int **graph, int V, int E) {

    // Dynamic array to store the edges
    Edge *edges = (Edge *)malloc(E * sizeof(Edge));

    int edgeCounter = 0;

    // Update the edges array with the edges from the graph. Consider only upper triangular matrix
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INT_MAX) {
                edges[edgeCounter].src = i;
                edges[edgeCounter].dest = j;
                edges[edgeCounter].weight = graph[i][j];
                edgeCounter++;
            }
        }
    }

    // Sort the edges in ascending order of their weights
    qsort(edges, E, sizeof(Edge), compare);

    // Initialize the parent array
    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    // Initialize the MST
    int MST_weight = 0;

    // Iterate over the edges
    for (int i = 0; i < E; i++) {
        int x, y;
        x = find(parent, edges[i].src);
        y = find(parent, edges[i].dest);

        // If the two vertices are not in the same subset
        if (x != y) {
            // Add the edge to the MST
            MST_weight += edges[i].weight;

            // Show which edge is added to the MST
            printf("Edge %d-%d with weight %d is added to the MST\n", edges[i].src, edges[i].dest, edges[i].weight);

            // Union the two subsets
            Union(parent, x, y);
        }
    }

    // Return the MST weight
    return MST_weight;
}

// Main function
int main() {
    // Take input for number of vertices
    int vertices, edges = 0;
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
            } else {
                // Else, increment the number of edges
                edges++;
            }
            // Mirror the adjacency matrix
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }

    // Divide the edges by 2
    edges /= 2;

    // Print newline
    printf("\n");

    // Call Kruskal's Algorithm
    int minEdgeWeight = kruskalMST(adjMatrix, vertices, edges);

    // Print the minimum spanning tree weight
    printf("\nThe minimum spanning tree weight is: %d\n", minEdgeWeight);

    return 0;
}