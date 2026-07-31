*This project has been created as part of the 42 curriculum by seungele.*

# Philosophers

## Description
The Philosophers project is a classic concurrency problem in computer science, based on Edsger Dijkstra's Dining Philosophers Problem.

The objective of this project is to learn the fundamentals of threading, shared memory management, and process synchronization using mutexes in C. Philosophers sit at a round table with a large bowl of spaghetti in the middle and alternate between three states: eating, sleeping, and thinking. To eat, a philosopher must acquire two forks (one on their left and one on their right). The primary challenge is to prevent deadlocks, data races, and starvation while ensuring accurate time management.

### Overview & Rules
* One or more philosophers sit at a round table with a fork between each pair of adjacent philosophers.
* Each philosopher is represented by a POSIX thread (`pthread_t`).
* Each fork is represented by a custom structure (`t_fork`) containing an individual mutex (`pthread_mutex_t`) and a state variable (`is_taken`).
* To prevent data races, state updates (such as meal timestamps) and log output printing are protected by dedicated mutexes (`meal_lock`, `print_lock`, `dead_lock`).
* A philosopher dies if they do not start eating within `time_to_die` milliseconds after their last meal or the start of the simulation.

#### 1. Structure-Based Fork Management (`t_fork`)
this project wraps each fork inside a dedicated state-managing structure:
* **State Protection**: The `fork_mutex` strictly protects access and updates to the `is_taken` flag.
* **Polling & Waiting Strategy**: When attempting to acquire a fork (`take_one_fork()`), a philosopher locks `fork_mutex`, checks if `is_taken == 0`, marks it as `1`, and unlocks `fork_mutex` before logging. If occupied (`is_taken == 1`), the thread unlocks and polls in short intervals (`usleep(100)`) while continually checking for termination flags.

#### 2. Thread Initialization, Start Time Synchronization & Input Validation
* **Strict Parameter Checking**: Arguments are verified during parsing (`init_check()`). If `num_philo <= 0`, `time_to_die <= 0`, `time_to_eat <= 0`, `time_to_sleep <= 0`, or invalid eating counts are provided, the program safely exits immediately.
* **Simultaneous Simulation Start**: All philosopher structures are initialized with a uniform reference timestamp (`now_time = get_time()`) before starting execution to prevent timing drift caused by `pthread_create()` overhead.
* **Staggered Execution**: Even-numbered philosophers (`philo_id % 2 == 0`) delay their initial routine by `time_to_eat / 2` upon thread creation to eliminate immediate resource contention over forks.

#### 3. Uniform Single Philosopher Lifecycle ($N=1$)
The program handles $N=1$ through the **exact same lifecycle routine** (`philo_action` $\rightarrow$ `taking_fork`) without artificial or hardcoded early-exit branches:
* A single philosopher picks up their first fork (`is_taken = 1`).
* When attempting to pick up the second fork, the philosopher discovers `left_fork == right_fork` (which is already `is_taken == 1`).
* Instead of invoking a recursive `pthread_mutex_lock` (which would cause a self-deadlock), `take_one_fork()` continuously polls while holding the first fork, waiting for the second fork to become free.
* After `time_to_die` milliseconds, the monitoring thread (`check_dead`) detects the timeout, logs `died`, sets `is_dead = 1`, and the philosopher thread cleanly exits its polling loop after releasing the first fork.

#### 4. Asymmetric Fork Acquisition & Mid-Routine Abort
* **Asymmetric Locking**: Regular philosophers ($1 \sim N-1$) acquire their left fork first and right fork second. The last philosopher ($N$) acquires their right fork first and left fork second to break circular wait conditions.
* **Immediate Fork Release on Termination**: If a philosopher thread acquires its first fork and detects that the simulation termination flag (`is_dead`) has been raised, it immediately resets `is_taken = 0`, unlocks the fork mutex, and exits `taking_fork()` to prevent dangling locks.

#### 5. Starvation Avoidance & Odd-Number Balancing
* When the total number of philosophers is odd, simple alternation between eating and sleeping can cause resource imbalances.
* In `thinking_time()`, odd-numbered groups dynamically calculate a required thinking buffer:
  `think_time = (time_to_eat * 2) - time_to_sleep`
  This ensures smooth rotation of fork availability and prevents continuous fork stealing between neighboring threads.

#### 6. Real-Time Monitoring & Safe Resource Destruction
* **Monitoring Thread (`check_dead`)**: Continuously loops through all philosopher structures in real-time. If the elapsed time since `last_meal_time` exceeds `time_to_die`, it updates `is_dead = 1`, logs the exact death timestamp atomically, and terminates the simulation loop.
* **Safe Destruction (`cleanup`)**:
  * For $N=1$, `pthread_detach` is used so the main thread does not block waiting on the thread polling for a second fork.
  * For $N > 1$, `pthread_join` waits for all threads to cleanly finish their routines.
  * All mutexes are guaranteed to be fully unlocked before calling `pthread_mutex_destroy`, avoiding undefined behavior.

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