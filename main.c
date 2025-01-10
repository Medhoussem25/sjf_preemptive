#include <stdio.h>
#include <stdlib.h>

int main() {
    // Note: If you enter a letter, you will encounter an infinite loop for the number of processes, execution time, or arrival time.
    int processCount;
    int execution = 1;

    while (execution != 0) {
        printf("Enter the number of processes: ");
        scanf("%d", &processCount);

        if (processCount < 0 || processCount == 'c') {
            printf("Input error\n");
        } else {
            printf("\n..............................................................\n");
            int processTable[processCount][5];

            for (int i = 0; i < processCount; i++) {
                printf("\nEnter the arrival time of process %d: ", i + 1);
                scanf("%d", &processTable[0][i]);
                if (processTable[0][i] < 0 || processTable[0][i] == 'c') {
                    printf("Input error\n");
                    printf("Enter the arrival time of process %d: ", i + 1);
                    scanf("%d", &processTable[0][i]);
                }
            }

            printf("\n..............................................................\n");
            printf("\n..............................................................\n");

            for (int i = 0; i < processCount; i++) {
                printf("\nEnter the execution time of process %d: ", i + 1);
                scanf("%d", &processTable[1][i]);
                if (processTable[1][i] < 0) {
                    printf("Input error\n");
                    printf("Enter the execution time of process %d: ", i + 1);
                    scanf("%d", &processTable[1][i]);
                }
            }

            for (int i = 0; i < processCount; i++) {
                processTable[4][i] = 1000; // Set an initial large value
                processTable[3][i] = processTable[1][i];
            }

            printf("\n..............................................................\n");
            int clock = 0, loop = 0;

            while (loop < 1) {
                int candidate = 1000, selected = 0;

                for (int i = 0; i < processCount; i++) {
                    if (clock >= processTable[0][i] && processTable[1][i] != 0) {
                        if (selected == 0) {
                            candidate = i;
                            selected = 1;
                        } else if (processTable[1][i] < processTable[1][candidate] && processTable[1][i] != 0) {
                            candidate = i;
                        }
                    }
                }

                if (candidate != 1000) {
                    printf("At time %d, process %d is selected\n", clock, candidate + 1);
                    if (processTable[4][candidate] == 1000) {
                        processTable[4][candidate] = clock;
                    }
                    processTable[1][candidate] -= 1;
                    if (processTable[1][candidate] == 0) {
                        processTable[2][candidate] = clock - processTable[0][candidate] + 1;
                        processTable[3][candidate] = processTable[2][candidate] - processTable[3][candidate];
                    }
                } else {
                    printf("At time %d, no process is selected to take the processor\n", clock);
                }

                loop = 1;
                for (int i = 0; i < processCount; i++) {
                    if (processTable[1][i] != 0) {
                        loop = 0;
                    }
                }
                clock++;
            }

            printf("Response times:\n");
            float total = 0, average;

            for (int i = 0; i < processCount; i++) {
                printf("%d\n", processTable[2][i]);
                total += processTable[2][i];
            }

            average = total / processCount;
            printf("The average response time is %.2f\n", average);

            printf("Waiting times:\n");
            total = 0;

            for (int i = 0; i < processCount; i++) {
                printf("%d\n", processTable[3][i]);
                total += processTable[3][i];
            }

            average = total / processCount;
            printf("The average waiting time is %.2f\n", average);
        }

        printf("Enter 0 to exit or 1 to restart: ");
        scanf("%d", &execution);
    }

    return 0;
}
