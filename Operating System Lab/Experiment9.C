#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

// Structure for a process
typedef struct {
    int processId;
    int allocatedResources[MAX_RESOURCES];
    int maxResources[MAX_RESOURCES];
    int needResources[MAX_RESOURCES];
    int isVisited;
} Process;

// Structure for available resources
typedef struct {
    int availableResources[MAX_RESOURCES];
} AvailableResources;

// Check if a process can be allocated resources
int canAllocateResources(Process process, AvailableResources available, int numResources) {
    for (int i = 0; i < numResources; i++) {
        if (process.needResources[i] > available.availableResources[i]) {
            return 0;
        }
    }
    return 1;
}

// Allocate resources to a process
void allocateResources(Process *process, AvailableResources *available, int numResources) {
    for (int i = 0; i < numResources; i++) {
        available->availableResources[i] -= process->needResources[i];
        process->allocatedResources[i] += process->needResources[i];
        process->needResources[i] = 0;
    }
}

// Release resources allocated to a process
void releaseResources(Process *process, AvailableResources *available, int numResources) {
    for (int i = 0; i < numResources; i++) {
        available->availableResources[i] += process->allocatedResources[i];
        process->allocatedResources[i] = 0;
    }
}

// Perform Banker's algorithm
void performBankersAlgorithm(Process processes[], int numProcesses, AvailableResources available, int numResources) {
    int numVisitedProcesses = 0;
    int isSafe = 1;

    while (numVisitedProcesses < numProcesses) {
        int isAllocationDone = 0;

        for (int i = 0; i < numProcesses; i++) {
            if (!processes[i].isVisited && canAllocateResources(processes[i], available, numResources)) {
                allocateResources(&processes[i], &available, numResources);
                processes[i].isVisited = 1;
                numVisitedProcesses++;
                isAllocationDone = 1;
            }
        }

        if (!isAllocationDone) {
            isSafe = 0;
            break;
        }
    }

    if (isSafe) {
        printf("Banker's Algorithm: System is in a safe state.\n");
    } else {
        printf("Banker's Algorithm: System is not in a safe state.\n");
    }
}

int main() {
    // Example processes
    Process processes[] = {
        {1, {0, 1, 0}, {7, 5, 3}, {7, 4, 3}, 0},
        {2, {2, 0, 0}, {3, 2, 2}, {1, 2, 2}, 0},
        {3, {3, 0, 2}, {9, 0, 2}, {6, 0, 0}, 0},
        {4, {2, 1, 1}, {2, 2, 2}, {0, 1, 1}, 0},
        {5, {0, 0, 2}, {4, 3, 3}, {4, 3, 1}, 0}
    };
    int numProcesses = sizeof(processes) / sizeof(Process);

    // Example available resources
    AvailableResources available = {{3, 3, 2}};
    int numResources = sizeof(available.availableResources) / sizeof(int);

    // Perform Banker's algorithm
    performBankersAlgorithm(processes, numProcesses, available, numResources);

    return 0;
}
