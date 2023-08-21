#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t emptySlots; // Semaphore for empty slots in the buffer
sem_t filledSlots; // Semaphore for filled slots in the buffer
pthread_mutex_t mutex; // Mutex for buffer access

// Producer function
void* producer(void* arg) {
    int item;

    for (int i = 0; i < NUM_ITEMS; i++) {
        item = rand() % 100; // Generate a random item

        sem_wait(&emptySlots);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        printf("Produced item: %d\n", item);

        pthread_mutex_unlock(&mutex);
        sem_post(&filledSlots);
    }

    pthread_exit(NULL);
}

// Consumer function
void* consumer(void* arg) {
    int item;

    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&filledSlots);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        printf("Consumed item: %d\n", item);

        pthread_mutex_unlock(&mutex);
        sem_post(&emptySlots);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphores and mutex
    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&filledSlots, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&emptySlots);
    sem_destroy(&filledSlots);
    pthread_mutex_destroy(&mutex);

    return 0;
}
