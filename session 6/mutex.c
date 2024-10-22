#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared variable
int counter = 0;

// Mutex
pthread_mutex_t mutex;

void* incrementCounter(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);  // Lock the mutex
        counter++;  // Critical section (safe access to shared variable)
        printf("Thread %s: counter = %d\n", (char*)arg, counter);
        // pthread_mutex_unlock(&mutex);  // Unlock the mutex
        sleep(1);  // Simulate some work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, incrementCounter, "A");
    pthread_create(&thread2, NULL, incrementCounter, "B");

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    printf("Final counter value: %d\n", counter);

    return 0;
}
