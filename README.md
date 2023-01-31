# philosophers
 
<p align="center">
  <img src = "https://user-images.githubusercontent.com/91738456/215802454-136c717c-c15a-4b3a-98db-44d4852b5ca8.png" />
</p>

Philosophers is a 42 Wolfsburg parallel computing project. An implementation of the Dining Philosophers Problem. A classic computer science project tinvented by Dijkstra. 

Main concepts that are used : thread and mutexes for mandatory part, semaphoras and processes for bonus.
 
## Rules
 
<ul>
<li> A number of philosophers sit at a round table where a large bowl of spaghetti lies in the center.</li>
<li> Each philosopher has a routine of eating, sleeping and thinking that repeats.</li>
<li> There are as many forks as there are philosophers on the table. </li>
<li> Each philosopher needs the two closest forks to eat.</li>
<li> Philosophers can’t speak with each other.</li>
<li> Every philosopher needs to eat and should never starve.</li>
<li> Unless the conditions do not allow it. No philosophers should die.</li>
</ul>
 
### Available parameters:
 
<ul>
<li> number_of_philosophers: The number of philosophers and also the number of forks.</li>
<li> time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.</li>
<li> time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks. </li>
<li> time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.</li>
<li> number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.</li>
</ul>
 
In case of invalid arguments, the program must display an appropriate error message.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer and/or zero or negative values are present in places it does not make sense.
 
# Usage
 
Use `make` to compile the program.
 
Add the desired parameters:
 
```
./philo <parameters>
```

# Output

Program outputs actions by every individual philosopher including its index and timestamp from the begining of the action. It looks somewhat like this

| timestamp in ms | index | action |
| :------------ |:---------------:| :----- |

```
0 ms: 1 has taken a fork
0 ms: 1 has taken a fork
0 ms: 1 is eating
0 ms: 3 has taken a fork
0 ms: 3 has taken a fork
0 ms: 3 is eating
0 ms: 5 has taken a fork
200 ms: 3 is sleeping
200 ms: 1 is sleeping
200 ms: 4 has taken a fork
200 ms: 2 has taken a fork
200 ms: 2 has taken a fork
200 ms: 2 is eating
200 ms: 5 has taken a fork

```

