// Program to find the single source shortest path in a graph using Dijkstra's Algorithm
// Explanation:
/*
    The Single Source Shortest Path problem is to find the shortest path between a given source vertex and all other vertices in a given graph. The Dijkstra's algorithm is an algorithm for finding the shortest path between a given source vertex and all other vertices in a given graph.

    It is a greedy algorithm. It uses a priority queue to store the intermediate results. The algorithm runs in O(V^2) time.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library

// Defines
#define min(a, b) ((a) < (b) ? (a) : (b))

// A utility function to find the closest vertex not in sptSet
int minDistance(int dist[], int sptSet[], int V) {
    // Initialize min value
    int min = INT_MAX,
        min_index;

    // Loop through all vertices
    for (int v = 0; v < V; v++) {
        // If vertex not in sptSet and distance is smaller than min
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's Algorithm Function (prints the shortest distance between a given source vertex and all other vertices in a given graph)
// Syntax: dijkstra(adjacencyMatrix, numberOfVertices, sourceVertex)
void dijkstra(int **Graph, int V, int sourceVertex) {
    // Initialize the distance array with INT_MAX
    int *distance = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX; // infinity
    }
    // Initialize the sptSet array with false
    int *sptSet = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        sptSet[i] = 0; // 0 means false
    }

    // Distance of source vertex from itself is 0
    distance[sourceVertex] = 0;

    // Loop through all vertices except itself
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex with minimum distance from the set of vertices not yet processed
        int u = minDistance(distance, sptSet, V);

        // Mark the picked vertex as club member of sptSet
        sptSet[u] = 1;

        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // If vertex is not in sptSet and distance of vertex is not infinity and distance of vertex is smaller than distance of picked vertex, then update the distance of vertex
            // This is the only difference between Dijkstra's Algorithm and Bellman-Ford's Algorithm

            if (sptSet[v] == 0 && Graph[u][v] && distance[u] != INT_MAX && distance[u] + Graph[u][v] < distance[v]) {
                distance[v] = distance[u] + Graph[u][v];
            }

            // Above, sptSet[v] == 0 means that vertex is not in sptSet
            // Graph[u][v] being true means that there is an edge between u and v
            // distance[u] != INT_MAX means that u is not the source vertex
            // distance[u] + Graph[u][v] < distance[v] means that the distance of v is greater than the distance of u plus the weight of the edge between u and v
        }
    }
    // Print the shortest distance between a given source vertex and all other vertices in a given graph
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("Distance of\t%d\tfrom\t%d\tis\t%d\n", i, sourceVertex, distance[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Take input for number of vertices
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Dynamically allocate memory for adjacency matrix
    int **Graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        Graph[i] = (int *)malloc(V * sizeof(int));
    }

    // Take input for adjacency matrix
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &Graph[i][j]);
        }
    }

    // Take input for source vertex
    int sourceVertex;
    printf("Enter the source vertex: ");
    scanf("%d", &sourceVertex);

    // Call Dijkstra's Algorithm
    dijkstra(Graph, V, sourceVertex);

    // Free memory
    for (int i = 0; i < V; i++) {
        free(Graph[i]);
    }
    free(Graph);
    return 0;
}