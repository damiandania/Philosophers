<p>
<img src="https://github.com/damiandania/damiandania/blob/main/Pics/Philosophers.png"
    alt="Project pic" width="150" height="150"/>
</p>

# Philosophers 🍽️

**Philosophers** is a project that simulates the classic dining philosophers problem. The goal is to understand and implement the mechanics of concurrent programming and synchronization using threads and mutexes.

## Features

- **Thread Management:** Create and manage multiple threads.
- **Synchronization:** Use mutexes to handle synchronization between threads.
- **Deadlock Prevention:** Implement strategies to prevent deadlocks.

## Technologies Used

- **C:** The project is implemented in C.

## Installation

1. **Clone this repository:**
    ```bash
    git clone https://github.com/damiandania/Philosophers.git
    ```

2. **Navigate to the project directory:**
    ```bash
    cd Philosophers
    ```

3. **Build the project:**
    ```bash
    make
    ```

## Usage

Once the project is built, you can run the philosophers simulation. For example:

```bash
$ ./philo number_of_philosophers [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

**Example:**

```bash
$ ./philo 5 800 200 200
```

This command will start a simulation with 5 philosophers, where each philosopher has 800ms to live without eating, takes 200ms to eat, and 200ms to sleep.
