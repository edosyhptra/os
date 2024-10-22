#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared variable
int counter = 0;

// Semaphores
sem_t semA, semB;

void* incrementCounterA(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&semA);  // Wait for semaphore A
        counter++;  // Critical section
        printf("Thread A: counter = %d\n", counter);
        sem_post(&semB);  // Signal semaphore B
        sleep(1);  // Simulate some work
    }
    return NULL;
}

void* incrementCounterB(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&semB);  // Wait for semaphore B
        counter++;  // Critical section
        printf("Thread B: counter = %d\n", counter);
        sem_post(&semA);  // Signal semaphore A
        sleep(1);  // Simulate some work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize semaphores
    sem_init(&semA, 0, 1);  // Semaphore A starts at 1 (Thread A starts first)
    sem_init(&semB, 0, 0);  // Semaphore B starts at 0 (Thread B waits)

    // Create two threads
    pthread_create(&thread1, NULL, incrementCounterA, NULL);
    pthread_create(&thread2, NULL, incrementCounterB, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy semaphores
    sem_destroy(&semA);
    sem_destroy(&semB);

    printf("Final counter value: %d\n", counter);

    return 0;
}
