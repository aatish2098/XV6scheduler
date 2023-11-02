#include "types.h"
#include "user.h"

#define TOTAL_TASKS 100000
#define NUM_CHILDREN 3

void customTask(int index, int tickets) {
    int taskIndex, calculationIndex;
    for (taskIndex = 0; taskIndex < TOTAL_TASKS; ++taskIndex) {
        // Simulate custom calculations
        for (calculationIndex = 0; calculationIndex < 100; calculationIndex++) {
            asm("nop");
        }
    }
    printf(1, "Child %d (Tickets: %d) has completed its custom tasks\n", index, tickets);
    exit();
}

int main(void) {
    int childTickets[NUM_CHILDREN] = {10, 20, 30}; // Assign different ticket values to each child process
    int childPID, childIndex;

    for (childIndex = 0; childIndex < NUM_CHILDREN; ++childIndex) {
        childPID = fork();
        if (childPID == 0) {
            settickets(childTickets[childIndex]);
            customTask(childIndex, childTickets[childIndex]);
        } else if (childPID < 0) {
            printf(2, "Child process creation failed\n");
            exit();
        }
    }

    for (childIndex = 0; childIndex < NUM_CHILDREN; ++childIndex) {
        wait(); // Wait for each child process to finish
    }

    printf(1, "All children with varying ticket values have finished their tasks\n");
    exit();
}
