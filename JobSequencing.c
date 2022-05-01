// Program to demonstrate Job Sequencing in C
// Explanation:
/*
    Job Sequencing is a problem where you have to find the sequence of jobs that will finish in the shortest time. The inputs are the number of jobs, the profit of each job, and the time required to complete each job.

    The output is the sequence of jobs that will finish in the shortest time.
*/

// Includes
#include <stdio.h>  // Basic I/O
#include <stdlib.h> // Standard Library

// Swapper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if any other job is already scheduled at the same time
int check(int *jobs, int n, int i) {
    for (int j = 0; j < n; j++) {
        if (jobs[j] == i) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    // Take input for number of jobs
    int jobs;
    printf("Enter number of jobs: ");
    scanf("%d", &jobs);

    // Dynamically allocate memory for profit and deadline
    int *profit = (int *)malloc(jobs * sizeof(int));
    int *deadline = (int *)malloc(jobs * sizeof(int));

    // Dynamically allocate memory for job sequence
    int *slot = (int *)malloc(jobs * sizeof(int));

    // Take input for profit of each job
    printf("Enter profit of each job: \n");
    for (int i = 0; i < jobs; i++) {
        scanf("%d", &profit[i]);
    }
    // Take input for deadline of each job
    printf("Enter deadline of each job: \n");
    for (int i = 0; i < jobs; i++) {
        scanf("%d", &deadline[i]);
    }

    // Initialize the job sequence to 0
    for (int i = 0; i < jobs; i++) {
        slot[i] = 0;
    }

    // Sort the profit and deadline arrays in descending order of profit
    for (int i = 0; i < jobs - 1; i++) {
        for (int j = i + 1; j < jobs; j++) {
            if (profit[i] < profit[j]) {
                swap(&profit[i], &profit[j]);
                swap(&deadline[i], &deadline[j]);
            }
        }
    }

    // Iterate through the jobs (highest profit first)
    for (int i = 0; i < jobs; i++) {
        // Schedule the current job as late as possible
        for (int j = deadline[i]; j >= 0; j--) {
            // j is the time slot
            // If the time slot is available
            if (check(slot, jobs, j)) {
                // Schedule the job
                slot[i] = j;
                break;
            }
        }
    }

    // Print the job sequence
    printf("Job sequence: \n");
    printf("\n INDEX\tPROFIT\tDEADLINE\tSLOT ALLOTTED\n");
    for (int i = 0; i < jobs; i++) {
        // If the job is scheduled
        if (slot[i] != 0) {
            printf("\n %d\t%d\t%d\t\t%d", i, profit[i], deadline[i], slot[i]);
        } else {
            printf("\n %d\t%d\t%d\t\tREJECTED", i, profit[i], deadline[i]);
        }
    }

    // Free the memory
    free(profit);
    free(deadline);
    free(slot);

    return 0;
}