_This project has been created as part of the 42 curriculum by nlallema_

# Codexion

![ci workflow](https://github.com/parad0xe/codexion/actions/workflows/ci.yml/badge.svg)

## Table of contents

- [Description](#description)
- [Usage](#usage)
  - [Execution](#execution)
    - [Arguments & options](#arguments--options)
    - [Development commands](#development-commands)
- [Blocking cases handled](#blocking-cases-handled)
- [Thread synchronization mechanisms](#thread-synchronization-mechanisms)
- [Feature list](#feature-list)
- [Resources](#resources)
  - [AI Usage](#ai-usage)
  - [Research & documentation](#research--documentation)

## Description

**Codexion** is a concurrent simulation project written in C. Its primary goal is to model a constrained environment where a specific number of developers (coders) must share limited resources (dongles) to successfully compile, debug, and refactor their code before suffering from burnout. 

This project provides a practical overview of multithreading, focusing on avoiding concurrency issues like deadlocks and data races through scheduling algorithms.

## Usage

Compile the project:

```bash
make
```

### Execution

Run the simulation by providing the required parameters:

```bash
./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles> <dongle_cooldown> <scheduler>
```

> This command requires all 8 arguments to be provided in the exact order for the simulation to initialize correctly.

#### Arguments & options

| Argument | Description |
|----------|-------------|
| `number_of_coders` | The total amount of coders (and dongles) in the simulation. |
| `time_to_burnout` | Time (in ms) a coder can survive without compiling. |
| `time_to_compile` | Time (in ms) it takes for a coder to compile (requires 2 dongles). |
| `time_to_debug` | Time (in ms) it takes for a coder to debug their code. |
| `time_to_refactor` | Time (in ms) it takes for a coder to refactor their code. |
| `number_of_compiles` | The goal number of successful compilations required for a coder to finish. |
| `dongle_cooldown` | Time (in ms) a dongle needs to cool down after being used. |
| `scheduler` | The scheduling algorithm for resource distribution (`fifo` or `edf`). |


#### Development commands

| Command | Mode | Description |
|---------|------|-------------|
| `make` / `make all` | production | compile the project with strict flags (`-Wall -Wextra -Werror`). |
| `make check ARGS="..."` | production | compile and run the simulation through valgrind to check for memory leaks. |
| `make check-threads ARGS="..."` | production | compile and run the simulation through hellgrind to check threads. |
| `make tests` | production | compile and run all unit tests (append `TEST_VERBOSE=1` for detailed output). |
| `make check-tests` | production | run all unit tests through valgrind to ensure complete memory safety. |
| `make build-debug` | debug | compile the project with debug symbols (`-g3`) without strict flags. |
| `make debug ARGS="..."` | debug | compile and immediately execute the simulation. |
| `make check-debug ARGS="..."` | debug | compile and execute through valgrind. |
| `make clean` | - | remove the `build/` directory, including object files and dependencies. |
| `make fclean` | - | execute `make clean` and remove the final executable. |
| `make re` | production | clean the project and recompile it entirely from scratch. |

## Blocking cases handled

- **Deadlock prevention and Coffman’s conditions:**
  - **Problem:** deadlocks can freeze the simulation when coders end up waiting indefinitely for dongles held by one another, creating circular-wait and hold-and-wait conditions.
  - **Solution:** the circular-wait condition is eliminated by alternating the dongle acquisition order based on coder parity, breaking symmetric locking patterns and preventing cyclic dependencies between threads. Additionally, if a coder acquires one dongle but cannot obtain the second, they immediately release the first to eliminate hold-and-wait. The coder then relies on `cond_timedwait` to efficiently block until the contested dongle becomes available, ensuring responsive and deadlock-free retries.

- **Starvation prevention:**
  - **Problem:** starvation occurs when a coder is repeatedly bypassed by competing threads, preventing timely access to dongles and leading to burnout.
  - **Solution:** this is addressed by centralizing dongle requests within a synchronized min-heap priority queue, ensuring controlled resource allocation. Two complementary scheduling policies are supported: FIFO (First-In, First-Out) guarantees strict ordering, while EDF (Earliest Deadline First) dynamically elevates priority for coders nearing their burnout threshold, reducing the risk of indefinite postponement.

- **Precise burnout detection:**
  - **Problem:** accurately detecting a coder’s burnout in a concurrent environment is non-trivial. Relying on worker threads to signal their own starvation is unreliable due to OS scheduling latency and potential lock contention.
  - **Solution:** this is handled by a detached monitoring thread that continuously scans all coders using an optimized *O(n)* loop. By safely reading absolute burnout deadlines through thread-safe accessors and comparing them against the current time, the monitor can deterministically trigger termination at the exact moment a coder expires, independent of worker thread scheduling delays.

- **Log serialization:**
  - **Problem:** concurrent writes to standard output can interleave or overlap, producing corrupted and unreadable logs.
  - **Solution:** all console output is synchronized through a dedicated global `log_mutex`, ensuring each print operation is atomic. This preserves a consistent, strictly chronological execution trace and guarantees log integrity under concurrency.

## Thread synchronization mechanisms

- **`pthread_mutex_t`:**
  - **Purpose:** to enforce mutual exclusion when accessing shared resources, ensuring data consistency under concurrency.
  - **Implementation:** multiple specialized mutexes are used across the system. The `access_mutex` protects the min-heap priority queue responsible for dongle allocation. A global `log_mutex` ensures atomic and ordered console output. Additionally, per-coder state mutexes isolate and protect individual data (e.g., running state) from concurrent access.

- **`pthread_cond_t`:**
  - **Purpose:** to enable efficient thread blocking and coordination based on state changes, avoiding costly busy-waiting.
  - **Implementation:** a global `start_cond` synchronizes the simultaneous launch of all coder threads. Condition variables, used in conjunction with `cond_timedwait`, are integrated with the priority queue: when a dongle becomes available after being released by another thread, the appropriate waiting thread is signaled to resume execution.

- **Race condition prevention & thread-safe communication:**
  - **Purpose:** to guarantee that shared state remains consistent and observable without corruption, particularly for the monitoring thread.
  - **Implementation:** all shared data access is encapsulated within thread-safe getters and setters. The monitor thread never reads raw memory directly; instead, it acquires the relevant coder’s state mutex, retrieves a consistent snapshot (e.g., coder is running), and releases the lock immediately. This approach eliminates race conditions, even under tightly concurrent updates.

## Feature list

- **Domain-Driven Design (DDD):**  
  the system is architected with clear modularity, isolating core domain entities (e.g., coders, dongles) from supporting utilities and error-handling components.
- **Error handling:**  
  an error-propagation mechanism prevents silent failures, guaranteeing predictable and reliable behavior.
- **Unit testing:**  
  targeted tests for critical lifecycles and core actions verify correctness and guarantee memory management.
- **GitHub CI workflow:**  
  automated continuous-integration pipelines run compilation and Valgrind memory checks on every push and pull request to the main branch, ensuring code integrity and preventing regressions.

## Resources

### AI Usage

The development of this project was supported by AI for:

- Code refactoring
- Drafting the README
- Generating doxygen-style docstrings
- Writing unit tests

### Research & documentation

- [Web: Priority heap queue](https://en.wikipedia.org/wiki/Heap_(data_structure))
- [Web: Deadlock](https://en.wikipedia.org/wiki/Deadlock_(computer_science))
- [Web: Resource starvation](https://en.wikipedia.org/wiki/Starvation_(computer_science))
- [Youtube: Thread introduction](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
