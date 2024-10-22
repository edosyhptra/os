package main

import (
	"fmt"
	"time"
)

func task(name string) {
	for i := 0; i < 5; i++ {
		fmt.Printf("Task %s is running iteration %d\n", name, i)
		time.Sleep(1 * time.Second) // Simulate work
	}
}

func main() {
	go task("A") // Start a goroutine for task A
	go task("B") // Start a goroutine for task B

	time.Sleep(6 * time.Second) // Wait for the tasks to finish
	fmt.Println("All tasks completed")
}
