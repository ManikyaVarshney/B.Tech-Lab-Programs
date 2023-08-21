#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <fcntl.h>

// Process Management System Calls
void createProcess() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process created.\n");
        // Add child process logic here
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process continuing.\n");
        // Add parent process logic here
    } else {
        // Fork failed
        printf("Failed to create child process.\n");
    }
}

// File Management System Calls
void fileOperations() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd != -1) {
        printf("File opened successfully.\n");
        // File operations logic here
        close(fd);
    } else {
        printf("Failed to open file.\n");
    }
}

// Input/Output System Calls
void ioOperations() {
    printf("Input/output operations.\n");
    // Input/output operations logic here
}

int main() {
    // Process Management System Calls
    createProcess();

    // File Management System Calls
    fileOperations();

    // Input/Output System Calls
    ioOperations();

    return 0;
}
