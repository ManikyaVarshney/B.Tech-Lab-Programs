#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

// Structure for a node in the graph
typedef struct Node {
    int processId;
    struct Node* next;
} Node;

// Structure for the adjacency list
typedef struct {
    Node* head;
} AdjList[MAX_PROCESSES];

// Add an edge to the adjacency list
void addEdge(AdjList graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->processId = dest;
    newNode->next = NULL;

    if (graph[src].head == NULL) {
        graph[src].head = newNode;
    } else {
        Node* temp = graph[src].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Convert RAG to WFG
void convertRAGtoWFG(Process processes[], int numProcesses) {
    AdjList wfg;
    for (int i = 0; i < numProcesses; i++) {
        wfg[i].head = NULL;
    }

    // Traverse the processes to find dependencies
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numProcesses; j++) {
            if (i != j && processes[i].allocatedResources[j] == 0 && processes[j].requestedResources[i] > 0) {
                addEdge(wfg, i, j);
            }
        }
    }

    // Print the Wait-For Graph (WFG)
    printf("Wait-For Graph (WFG):\n");
    for (int i = 0; i < numProcesses; i++) {
        Node* temp = wfg[i].head;
        printf("P%d -> ", i);
        while (temp != NULL) {
            printf("P%d ", temp->processId);
            temp = temp->next;
            if (temp != NULL) {
                printf("-> ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Example processes
    Process processes[] = {
        {0, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0},
        {1, {1, 1, 0}, {1, 0, 0}, {0, 1, 0}, 0},
        {2, {0, 1, 0}, {0, 1, 0}, {0, 0, 0}, 0},
        {3, {1, 0, 1}, {1, 0, 1}, {0, 0, 0}, 0}
    };
    int numProcesses = sizeof(processes) / sizeof(Process);

    // Convert RAG to WFG
    convertRAGtoWFG(processes, numProcesses);

    return 0;
}
