*This project has been created as part of the 42 curriculum by seungele.*

# Philosophers

## Description
The Philosophers project is a classic concurrency problem in computer science, based on Edsger Dijkstra's Dining Philosophers Problem. 

The objective of this project is to learn the fundamentals of threading, shared memory management, and process synchronization using mutexes in C. Philosophers sit at a round table with a large bowl of spaghetti in the middle and alternate between three states: eating, sleeping, and thinking. To eat, a philosopher must acquire two forks (one on their left and one on their right). The primary challenge is to prevent deadlocks, data races, and starvation while ensuring accurate time management.

### Overview & Rules
* One or more philosophers sit at a round table with a fork between each pair of adjacent philosophers.
* Each philosopher is represented by a POSIX thread (pthread_t).
* Each fork is protected by a mutex (pthread_mutex_t).
* To prevent data races, state updates (such as meal timestamps) and log output printing are protected by dedicated mutexes (meal_lock, print_lock, dead_lock).
* A philosopher dies if they do not start eating within time_to_die milliseconds after their last meal or the start of the simulation.

### Implementation & Architecture Overview
This project is built around a concurrent multi-threaded architecture with fine-grained synchronization to guarantee maximum performance and precision without encountering deadlocks or race conditions.

#### 1. Thread Initialization & Start Time Synchronization
* **Simultaneous Simulation Start**: To prevent early thread starvation and time drift caused by `pthread_create` overhead, all philosopher structures are initialized with a uniform reference timestamp (`now_time = get_time()`) before starting the thread routine execution.
* **Staggered Execution**: Even-numbered philosophers (`philo_id % 2 == 0`) are initially delayed by `time_to_eat / 2` upon thread creation to immediately break initial resource contention over forks.

#### 2. Deadlock Prevention Strategy (Asymmetric Resource Acquisition)
* To prevent the circular wait condition (a key requirement for deadlocks), asymmetric locking is implemented in `taking_fork()`:
  * Regular philosophers (`id < num_philo`) acquire the **left fork first**, followed by the **right fork**.
  * The last philosopher (`id == num_philo`) acquires the **right fork first**, followed by the **left fork**.
* **Immediate Fork Release on Termination**: If a philosopher thread acquires its first fork and detects that the simulation termination flag (`is_dead`) has been raised, it immediately releases the held fork before returning to prevent starvation of adjacent threads.

#### 3. Starvation Avoidance & Odd-Number Balancing
* When the total number of philosophers is odd, simple alternation between eating and sleeping causes resource imbalances.
* In `thinking_time()`, odd-numbered total groups dynamically calculate a required thinking buffer:
  `think_time = (time_to_eat * 2) - time_to_sleep`
  This ensures smooth rotation of fork availability and prevents continuous fork stealing between neighboring threads.

#### 4. Thread-Safe State & Logging Protection
* **`meal_lock`**: Each philosopher has an individual mutex protecting `last_meal_time` and `eat_cnt`. This prevents data races when the monitoring thread reads timestamp data while a philosopher thread updates it during `philo_action()`.
* **`dead_lock`**: Protects the shared `is_dead` flag, ensuring thread-safe state modification and checking across all running threads.
* **`print_lock`**: Wraps all console output (`printf`) calls to guarantee atomic status logging without overlapped or garbled text lines.

#### 5. Real-Time Monitoring & Single Philosopher Handling
* **Monitoring Thread (`check_dead`)**: Continuously loops through all philosopher structures in real-time. If the elapsed time since `last_meal_time` exceeds `time_to_die`, it sets `is_dead = 1`, locks `print_lock`, logs the exact death timestamp, and terminates the program.
* **Edge Case (`num_philo == 1`)**: Handled explicitly in `philo_routine()`. A single philosopher acquires the left fork, waits until `time_to_die` expires without acquiring a second fork, releases the fork, and dies gracefully.

---

## Instructions

### Compilation
The project includes a Makefile that compiles the source code with standard flags (-Wall -Wextra -Werror).

To build the executable, run:
make

Other available Makefile rules:
* make clean: Removes object files (.o).
* make fclean: Removes object files and the generated executable (philo).
* make re: Recompiles the entire project from scratch.

### Execution
Run the program with the required positional arguments:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

#### Arguments
1. number_of_philosophers: The number of philosophers and forks.
2. time_to_die (ms): Maximum time a philosopher can go without eating before dying.
3. time_to_eat (ms): Time it takes for a philosopher to eat.
4. time_to_sleep (ms): Time a philosopher spends sleeping.
5. [number_of_times_each_philosopher_must_eat] (Optional): If all philosophers eat at least this many times, the simulation stops. If unspecified, the simulation stops when a philosopher dies.

### Usage Examples
# 5 philosophers, no one should die
./philo 5 800 200 200 | xclip -selection clipboard
* to check the leak :
  valgrind --leak-check=full --show-leak-kinds=all
---

## Technical Details & Architecture

* Thread Synchronization: Each philosopher runs on a dedicated thread. Mutexes are used for:
  * Forks: Protecting shared fork access between adjacent philosophers.
  * Logging (print_lock): Ensuring output messages are never mixed or overlapped.
  * Meal Data (meal_lock): Preventing race conditions between philosopher threads updating last_meal_time and the monitoring loop reading it.
  * Simulation Flag (dead_lock): Safely checking and setting the global termination status.
* Deadlock Prevention: Asymmetric fork acquisition is implemented (e.g., the last philosopher picks up the right fork before the left fork) to break the circular wait condition.
* Starvation Avoidance: Dynamic thinking delays (think_time) are calculated for odd numbers of philosophers to ensure fair scheduling of shared forks.

* **Data Structures**:
  * `t_check`: Global context containing configuration timers, simulation state (`is_dead`), array of fork mutexes, `print_lock`, and `dead_lock`.
  * `t_philo`: Individual philosopher thread state containing thread handle, IDs, meal counter, timestamps, dedicated `meal_lock`, and pointers to assigned left/right fork mutexes.

---

## Resources

### References & Documentation
* POSIX Threads Programming : https://redisgate.kr/redis/server/pthread.php
* Unix Threads in C
* man pthread_create, man pthread_mutex_init, man gettimeofday, man usleep

### How AI Was Used
An AI assistant (Gemini) was utilized during the development and debugging phases of this project for the following tasks:
1. Documentation:
   * Structuring and formatting the project README.md according to 42 curriculum standards.
2. Norm & Modular Refactoring:
   * Assisting in splitting helper functions (`routine_helper.c`, `check_helper.c`) to conform to 42 Norminette coding standards.