*This project has been created as part of the 42 curriculum by jcano-du.*

# Philosophers

## Description

**Philosophers** is a project centered on the basics of threading a process and managing shared memory. It is based on the famous **Dining Philosophers problem** proposed by Edsger Dijkstra.

The goal of this project is to learn how to:
- Manage threads using the `pthread` library.
- Handle synchronization and avoid **data races**.
- Use **mutexes** (and semaphores for the bonus part) to protect shared resources.
- Prevent **deadlocks** and resource starvation.

In this simulation, philosophers sit at a round table with a bowl of spaghetti in the center. They alternate between three states: **eating**, **sleeping**, and **thinking**. To eat, they need two forks (mutexes). The challenge is to keep them alive as long as possible without getting blocked.


### Compilation

First time you need to compile the makefile with this -> make

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

### Informations

number_of_philosophers: The number of philosophers and also the number of forks.

time_to_die: Time (in ms) a philosopher can survive without eating.

time_to_eat: Time (in ms) it takes to eat.

time_to_sleep: Time (in ms) spent sleeping.

[number_of_times_each_philosopher_must_eat] (Optional): If all philosophers eat at least this many times, the simulation stops.

### Example 
./philo 4 410 200 200  if you don't put the nb_meal


./philo 4 410 200 200 5 if you put the nb_meal

If you want clean you need to use this command -> make fclean
