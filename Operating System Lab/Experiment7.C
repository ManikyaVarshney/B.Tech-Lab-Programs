#include <stdio.h>

#define MAX_BLOCKS 100

// Structure for process file
typedef struct {
    int processId;
    int startBlock;
    int endBlock;
} ProcessFile;

// Perform compaction on the memory layout
void performCompaction(ProcessFile processFiles[], int numProcessFiles) {
    int totalMovement = 0;

    // Sort the process files based on their start block in ascending order
    for (int i = 0; i < numProcessFiles - 1; i++) {
        for (int j = 0; j < numProcessFiles - i - 1; j++) {
            if (processFiles[j].startBlock > processFiles[j + 1].startBlock) {
                ProcessFile temp = processFiles[j];
                processFiles[j] = processFiles[j + 1];
                processFiles[j + 1] = temp;
            }
        }
    }

    // Perform compaction and calculate total movement
    int currentBlock = 0;
    for (int i = 0; i < numProcessFiles; i++) {
        int blockSize = processFiles[i].endBlock - processFiles[i].startBlock + 1;
        int movement = processFiles[i].startBlock - currentBlock;

        totalMovement += movement;

        processFiles[i].startBlock -= movement;
        processFiles[i].endBlock = processFiles[i].startBlock + blockSize - 1;

        currentBlock = processFiles[i].endBlock + 1;
    }

    printf("Total Movement: %d blocks\n\n", totalMovement);
}

int main() {
    // Example process file list
    ProcessFile processFiles[] = {
        {1, 5, 8},
        {2, 10, 14},
        {3, 20, 24},
        {4, 30, 36}
    };
    int numProcessFiles = sizeof(processFiles) / sizeof(ProcessFile);

    // Perform compaction and calculate total movement
    performCompaction(processFiles, numProcessFiles);

    return 0;
}
