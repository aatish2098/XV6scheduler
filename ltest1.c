#include "types.h"
#include "user.h"

#define NUM_ITERATIONS 10000
#define NUM_PROCESSES 10
#define PROCESS_PRIORITY 10

void simulateIntensiveTask() {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        int sum = 0;
        for (int j = 0; j < 100; j++) {
            sum += j;
        }
    }
    exit();
}

int main(void) {
    for (int processIndex = 0; processIndex < NUM_PROCESSES; ++processIndex) {
        int childPid = fork();
        if (childPid == 0) {
            settickets(PROCESS_PRIORITY);
            simulateIntensiveTask();
        } else if (childPid < 0) {
            printf(2, "Failed to create a new process.\n");
            exit();
        }
    }

    for (int processIndex = 0; processIndex < NUM_PROCESSES; ++processIndex) {
        wait();
    }

    printf(1, "All child processes with equal number of tickets have completed their tasks.\n");
    exit();
}
