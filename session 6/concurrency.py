import threading
import time

def task(name):
    for i in range(5):
        print(f"Task {name} is running iteration {i}")
        time.sleep(1)  # Simulate work

# Create threads
thread1 = threading.Thread(target=task, args=("A",))
thread2 = threading.Thread(target=task, args=("B",))

# Start threads
thread1.start()
thread2.start()

# Wait for both threads to complete
thread1.join()
thread2.join()

print("All tasks completed")
