# Shortest Job First (SJF) Preemptive Scheduling

This program implements the **Shortest Job First (SJF) Preemptive Scheduling Algorithm**, also known as **Shortest Remaining Time First (SRTF)**. The goal of the algorithm is to schedule processes based on their burst time, minimizing the overall waiting time and ensuring efficient CPU utilization.

## How the Algorithm Works

1. **Process Input**:
   - The user is prompted to enter the number of processes.
   - For each process, the user inputs:
     - The arrival time (when the process arrives in the ready queue).
     - The burst time (time required for the process to execute).

2. **Scheduling Logic**:
   - At each unit of time, the process with the shortest remaining burst time among the available processes is selected for execution.
   - If a new process arrives with a shorter burst time than the current executing process, the CPU preempts the current process and switches to the new process.

3. **Output**:
   - The program calculates and displays the response time, waiting time, and average values for these metrics.
   - The output provides a detailed breakdown of how the processes are scheduled at each time unit.

## Key Features

- **Preemption**: The CPU can switch between processes if a new process with a shorter burst time arrives.
- **Dynamic Scheduling**: The scheduler continuously evaluates the processes in the ready queue.
- **Efficiency Metrics**:
  - **Response Time**: Time from process arrival to its first execution.
  - **Waiting Time**: Total time a process spends waiting in the ready queue.

## Code Breakdown

1. **Input Validation**:
   - Ensures valid input for the number of processes, arrival times, and burst times.
   - Re-prompts the user in case of invalid input.

2. **Simulation**:
   - Simulates the passage of time using a clock (`horloge`).
   - At each tick, the scheduler checks all available processes to select the one with the shortest remaining burst time.

3. **Metrics Calculation**:
   - Response time is calculated when a process is first scheduled.
   - Waiting time is derived from the total execution and response times.

4. **Output**:
   - Displays the scheduling decisions for each time unit.
   - Outputs response and waiting times for all processes, as well as their averages.

## Example Run

```text
Enter the number of processes: 3

Enter the arrival time of process 1: 0
Enter the burst time of process 1: 5

Enter the arrival time of process 2: 1
Enter the burst time of process 2: 3

Enter the arrival time of process 3: 2
Enter the burst time of process 3: 8

...
At time 0: Process 1 is executing
At time 1: Process 2 is executing
At time 4: Process 1 is executing
...

Response Times:
Process 1: 0
Process 2: 1
Process 3: 2

Average Response Time: 1.00
Average Waiting Time: 4.33
```

## Error Handling

- Invalid inputs (e.g., negative numbers, non-integer values) prompt the user to re-enter values.
- Processes are not scheduled if their arrival time is not yet reached.

## Limitations

- The program assumes all processes are entered at the beginning.
- Input errors can lead to infinite loops if not corrected.

## How to Run the Program

1. Compile the program using a C compiler (e.g., GCC):
   ```bash
   gcc sjf_preemptive.c -o sjf
   ```
2. Run the program:
   ```bash
   ./sjf
   ```

3. Follow the prompts to input process details.

## Further Enhancements

- Add Gantt chart visualization to display the scheduling timeline.
- Allow dynamic addition of processes during runtime.
- Implement a graphical interface for better user experience.

## Author
This program demonstrates an SJF preemptive scheduling algorithm designed for educational purposes.

