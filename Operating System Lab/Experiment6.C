#include <stdio.h>

#define MAX_BLOCKS 100

// Structure for free blocks
typedef struct {
    int startBlock;
    int endBlock;
} FreeBlock;

// Structure for process file
typedef struct {
    int processId;
    int startBlock;
    int endBlock;
} ProcessFile;

// Calculate external fragmentation
void calculateExternalFragmentation(FreeBlock freeBlocks[], int numFreeBlocks) {
    int totalExternalFragmentation = 0;

    for (int i = 0; i < numFreeBlocks; i++) {
        totalExternalFragmentation += (freeBlocks[i].endBlock - freeBlocks[i].startBlock + 1);
    }

    printf("External Fragmentation: %d blocks\n\n", totalExternalFragmentation);
}

// Calculate internal fragmentation
void calculateInternalFragmentation(ProcessFile processFiles[], int numProcessFiles) {
    int totalInternalFragmentation = 0;

    for (int i = 0; i < numProcessFiles; i++) {
        int fileBlocks = processFiles[i].endBlock - processFiles[i].startBlock + 1;
        int fileSize = fileBlocks * sizeof(int);
        int actualFileSize = fileBlocks * sizeof(int) + sizeof(ProcessFile);
        int internalFragmentation = actualFileSize - fileSize;
        totalInternalFragmentation += internalFragmentation;
    }

    printf("Internal Fragmentation: %d bytes\n\n", totalInternalFragmentation);
}

int main() {
    // Example free space list
    FreeBlock freeBlocks[] = {
        {10, 19},
        {30, 35},
        {45, 49}
    };
    int numFreeBlocks = sizeof(freeBlocks) / sizeof(FreeBlock);

    // Example process file list
    ProcessFile processFiles[] = {
        {1, 10, 13},
        {2, 25, 29},
        {3, 40, 44}
    };
    int numProcessFiles = sizeof(processFiles) / sizeof(ProcessFile);

    // Calculate external fragmentation
    calculateExternalFragmentation(freeBlocks, numFreeBlocks);

    // Calculate internal fragmentation
    calculateInternalFragmentation(processFiles, numProcessFiles);

    return 0;
}
