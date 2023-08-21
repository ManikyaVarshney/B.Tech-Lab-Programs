#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    // Process Management System Calls
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) created.\n", getpid());
        // Add child process logic here
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) continuing.\n", getpid());
        // Add parent process logic here
        wait(NULL); // Wait for the child process to finish
    } else {
        // Fork failed
        printf("Failed to create child process.\n");
    }

    // File Management System Calls
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd != -1) {
        printf("File opened successfully.\n");
        // File operations logic here
        write(fd, "Hello, world!", 13); // Write to the file
        close(fd); // Close the file
    } else {
        printf("Failed to open file.\n");
    }

    // Input/Output System Calls
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    printf("You entered: %d\n", num);

    return 0;
}
