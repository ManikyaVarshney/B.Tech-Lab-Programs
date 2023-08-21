#include <stdio.h>

#define MEMORY_SIZE 100

// Process structure
typedef struct {
    int processId;
    int blockSize;
    int allocatedBlock;
} Process;

// Contiguous Allocation (Worst-Fit)
void worstFitAllocation(Process processes[], int n, int memory[], int memorySize) {
    for (int i = 0; i < n; i++) {
        int worstFitBlockIndex = -1;
        int worstFitBlockSize = -1;

        for (int j = 0; j < memorySize; j++) {
            if (memory[j] == 0 && j + processes[i].blockSize <= memorySize) {
                int currentBlockSize = 0;
                int k = j;
                while (k < memorySize && memory[k] == 0) {
                    currentBlockSize++;
                    k++;
                }

                if (currentBlockSize >= processes[i].blockSize && currentBlockSize > worstFitBlockSize) {
                    worstFitBlockIndex = j;
                    worstFitBlockSize = currentBlockSize;
                }
            }
        }

        if (worstFitBlockIndex != -1) {
            // Allocate memory block to the process
            for (int j = worstFitBlockIndex; j < worstFitBlockIndex + processes[i].blockSize; j++) {
                memory[j] = processes[i].processId;
            }
            processes[i].allocatedBlock = worstFitBlockIndex;
        }
    }

    printf("Worst-Fit Allocation:\n");
    printf("Process\tBlock\tAllocation\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", processes[i].processId, processes[i].blockSize);
        if (processes[i].allocatedBlock != -1) {
            printf("%d-%d\n", processes[i].allocatedBlock, processes[i].allocatedBlock + processes[i].blockSize - 1);
        } else {
            printf("Not allocated\n");
        }
    }
    printf("\n");
}

// Contiguous Allocation (Best-Fit)
void bestFitAllocation(Process processes[], int n, int memory[], int memorySize) {
    for (int i = 0; i < n; i++) {
        int bestFitBlockIndex = -1;
        int bestFitBlockSize = MEMORY_SIZE + 1;

        for (int j = 0; j < memorySize; j++) {
            if (memory[j] == 0 && j + processes[i].blockSize <= memorySize) {
                int currentBlockSize = 0;
                int k = j;
                while (k < memorySize && memory[k] == 0) {
                    currentBlockSize++;
                    k++;
                }

                if (currentBlockSize >= processes[i].blockSize && currentBlockSize < bestFitBlockSize) {
                    bestFitBlockIndex = j;
                    bestFitBlockSize = currentBlockSize;
                }
            }
        }

        if (bestFitBlockIndex != -1) {
            // Allocate memory block to the process
            for (int j = bestFitBlockIndex; j < bestFitBlockIndex + processes[i].blockSize; j++) {
                memory[j] = processes[i].processId;
            }
            processes[i].allocatedBlock = bestFitBlockIndex;
        }
    }

    printf("Best-Fit Allocation:\n");
    printf("Process\tBlock\tAllocation\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", processes[i].processId, processes[i].blockSize);
        if (processes[i].allocatedBlock != -1) {
            printf("%d-%d\n", processes[i].allocatedBlock, processes[i].allocatedBlock + processes[i].blockSize - 1);
        } else {
            printf("Not allocated\n");
        }
    }
    printf("\n");
}

// Contiguous Allocation (First-Fit)
void firstFitAllocation(Process processes[], int n, int memory[], int memorySize) {
    for (int i = 0; i < n; i++) {
        int allocated = 0;

        for (int j = 0; j < memorySize; j++) {
            if (memory[j] == 0 && j + processes[i].blockSize <= memorySize) {
                // Allocate memory block to the process
                for (int k = j; k < j + processes[i].blockSize; k++) {
                    memory[k] = processes[i].processId;
                }
                processes[i].allocatedBlock = j;
                allocated = 1;
                break;
            }
        }

        if (!allocated) {
            processes[i].allocatedBlock = -1;
        }
    }

    printf("First-Fit Allocation:\n");
    printf("Process\tBlock\tAllocation\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", processes[i].processId, processes[i].blockSize);
        if (processes[i].allocatedBlock != -1) {
            printf("%d-%d\n", processes[i].allocatedBlock, processes[i].allocatedBlock + processes[i].blockSize - 1);
        } else {
            printf("Not allocated\n");
        }
    }
    printf("\n");
}

int main() {
    // Example processes and memory
    Process processes[] = {
        {1, 20, -1},
        {2, 10, -1},
        {3, 30, -1},
        {4, 5, -1},
        {5, 15, -1}
    };
    int n = sizeof(processes) / sizeof(Process);

    int memory[MEMORY_SIZE] = {0};  // Memory blocks
    int memorySize = sizeof(memory) / sizeof(int);

    // Call allocation functions
    worstFitAllocation(processes, n, memory, memorySize);
    bestFitAllocation(processes, n, memory, memorySize);
    firstFitAllocation(processes, n, memory, memorySize);

    return 0;
}
