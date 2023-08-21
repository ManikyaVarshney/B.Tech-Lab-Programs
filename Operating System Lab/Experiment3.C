#include <stdio.h>

// Process structure
typedef struct {
    int processId;
    int burstTime;
    int priority;
} Process;

// Shortest Job First (SJF) Scheduling
void sjfScheduling(Process processes[], int n) {
    // Sort processes based on burst time (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap the processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("SJF Scheduling:\n");
    printf("Process\tBurst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", processes[i].processId, processes[i].burstTime);
    }
    printf("\n");
}

// Priority Scheduling
void priorityScheduling(Process processes[], int n) {
    // Sort processes based on priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                // Swap the processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("Priority Scheduling:\n");
    printf("Process\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", processes[i].processId, processes[i].priority);
    }
    printf("\n");
}

// First-Come, First-Served (FCFS) Scheduling
void fcfsScheduling(Process processes[], int n) {
    printf("FCFS Scheduling:\n");
    printf("Process\tBurst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", processes[i].processId, processes[i].burstTime);
    }
    printf("\n");
}

// Multi-level Queue Scheduling
void multilevelQueueScheduling(Process processes[], int n) {
    // Divide processes into different queues based on priority
    Process highPriorityQueue[n];
    Process lowPriorityQueue[n];
    int highPriorityCount = 0;
    int lowPriorityCount = 0;

    for (int i = 0; i < n; i++) {
        if (processes[i].priority <= 5) {
            highPriorityQueue[highPriorityCount++] = processes[i];
        } else {
            lowPriorityQueue[lowPriorityCount++] = processes[i];
        }
    }

    printf("Multi-level Queue Scheduling:\n");
    printf("High Priority Queue:\n");
    printf("Process\tPriority\n");
    for (int i = 0; i < highPriorityCount; i++) {
        printf("%d\t%d\n", highPriorityQueue[i].processId, highPriorityQueue[i].priority);
    }
    printf("\n");
    printf("Low Priority Queue:\n");
    printf("Process\tPriority\n");
    for (int i = 0; i < lowPriorityCount; i++) {
        printf("%d\t%d\n", lowPriorityQueue[i].processId, lowPriorityQueue[i].priority);
    }
    printf("\n");
}

int main() {
    // Example processes
    Process processes[] = {
        {1, 8, 2},
        {2, 4, 1},
        {3, 6, 3},
        {4, 2, 5},
        {5, 10, 4}
    };

    int n = sizeof(processes) / sizeof(Process);

    // Call scheduling functions
    sjfScheduling(processes, n);
    priorityScheduling(processes, n);
    fcfsScheduling(processes, n);
    multilevelQueueScheduling(processes, n);

    return 0;
}
