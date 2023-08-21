#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

// Structure for a process
typedef struct {
    int processId;
    int allocatedResources[MAX_RESOURCES];
    int requestedResources[MAX_RESOURCES];
    int isVisited;
} Process;

// Structure for a resource
typedef struct {
    int resourceId;
    int availableInstances;
} Resource;

// Check if a process can be allocated resources
int canAllocateResources(Process process, Resource resources[], int numResources) {
    for (int i = 0; i < numResources; i++) {
        if (process.requestedResources[i] > resources[i].availableInstances) {
            return 0;
        }
    }
    return 1;
}

// Allocate resources to a process
void allocateResources(Process *process, Resource resources[], int numResources) {
    for (int i = 0; i < numResources; i++) {
        resources[i].availableInstances -= process->requestedResources[i];
        process->allocatedResources[i] += process->requestedResources[i];
        process->requestedResources[i] = 0;
    }
}

// Release resources allocated to a process
void releaseResources(Process *process, Resource resources[], int numResources) {
    for (int i = 0; i < numResources; i++) {
        resources[i].availableInstances += process->allocatedResources[i];
        process->allocatedResources[i] = 0;
    }
}

// Perform resource allocation graph (RAG) algorithm
void performRAG(Process processes[], int numProcesses, Resource resources[], int numResources) {
    int numVisitedProcesses = 0;
    int isSafe = 1;

    while (numVisitedProcesses < numProcesses) {
        int isAllocationDone = 0;

        for (int i = 0; i < numProcesses; i++) {
            if (!processes[i].isVisited && canAllocateResources(processes[i], resources, numResources)) {
                allocateResources(&processes[i], resources, numResources);
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
        printf("Resource Allocation Graph (RAG) is safe.\n");
    } else {
        printf("Resource Allocation Graph (RAG) is not safe.\n");
    }
}

int main() {
    // Example processes
    Process processes[] = {
        {1, {1, 0, 1}, {0, 0, 1}, 0},
        {2, {2, 1, 0}, {2, 0, 0}, 0},
        {3, {1, 1, 1}, {0, 1, 0}, 0}
    };
    int numProcesses = sizeof(processes) / sizeof(Process);

    // Example resources
    Resource resources[] = {
        {1, 2},
        {2, 1},
        {3, 1}
    };
    int numResources = sizeof(resources) / sizeof(Resource);

    // Perform resource allocation graph (RAG) algorithm
    performRAG(processes, numProcesses, resources, numResources);

    return 0;
}
