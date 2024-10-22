#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Task function that will run concurrently
void* task(void* arg) {
    char* name = (char*)arg;
    for (int i = 0; i < 5; i++) {
        printf("Task %s is running iteration %d\n", name, i);
        sleep(1); // Simulate work with a 1-second delay
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads to run the task concurrently
    pthread_create(&thread1, NULL, task, "A");
    pthread_create(&thread2, NULL, task, "B");

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("All tasks completed\n");

    return 0;
}
