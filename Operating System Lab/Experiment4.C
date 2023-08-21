#include <stdio.h>
#include <stdlib.h>

// File block structure for linked-list allocation
typedef struct ListNode {
    int blockNumber;
    struct ListNode* next;
} ListNode;

// Contiguous Allocation (Using Array)
void contiguousAllocation(int fileBlocks[], int fileSize) {
    printf("Contiguous Allocation:\n");
    printf("File Blocks:\n");
    for (int i = 0; i < fileSize; i++) {
        printf("%d ", fileBlocks[i]);
    }
    printf("\n\n");
}

// Linked-List Allocation (Using Linked-List)
void linkedListAllocation(ListNode* head) {
    printf("Linked-List Allocation:\n");
    printf("File Blocks:\n");
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->blockNumber);
        current = current->next;
    }
    printf("\n\n");
}

// Indirect Allocation (Using Indexing)
void indirectAllocation(int indirectBlocks[], int fileSize, int indexBlocks) {
    printf("Indirect Allocation:\n");
    printf("Index Blocks:\n");
    for (int i = 0; i < indexBlocks; i++) {
        printf("%d ", indirectBlocks[i]);
    }
    printf("\n");

    printf("File Blocks:\n");
    for (int i = 0; i < fileSize; i++) {
        printf("%d ", indirectBlocks[indexBlocks + i]);
    }
    printf("\n\n");
}

int main() {
    // Contiguous Allocation (Using Array)
    int contiguousFileBlocks[] = {1, 2, 3, 4, 5};
    int contiguousFileSize = sizeof(contiguousFileBlocks) / sizeof(int);
    contiguousAllocation(contiguousFileBlocks, contiguousFileSize);

    // Linked-List Allocation (Using Linked-List)
    ListNode* head = NULL;
    ListNode* current = NULL;
    for (int i = 1; i <= 5; i++) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->blockNumber = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    linkedListAllocation(head);

    // Indirect Allocation (Using Indexing)
    int indirectBlocks[] = {10, 20, 30, 40, 50, 60, 70};
    int indirectFileSize = 5;
    int indexBlocks = 2;
    indirectAllocation(indirectBlocks, indirectFileSize, indexBlocks);

    return 0;
}
