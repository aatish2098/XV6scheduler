#include "types.h"
#include "user.h"
#include "date.h"

// Do some useless computations
void spin(int tix) {
    struct rtcdate end;
    // unsigned x = 0;
    // unsigned y = 0;
    // while (x < 100000) { // Changed from 100000
    //     y = 0;
    //     while (y < 10000) {
    //         y++;
    //     }
    //     x++;
    // }
    int z,x;
    	for(z = 0; z < 4000000000; z+=1)
	    x = x + 3.14*89.64; //Useless calculation to consume CPU Time

    gettime(&end);
    printf(0, "spin with %d tickets ended at %d hours %d minutes %d seconds\n", tix, end.hour, end.minute, end.second);
}

int main() {
    int pid1;
    int pid2;
    struct rtcdate start;
    gettime(&start);
    printf(0, "starting test at %d hours %d minutes %d seconds\n", start.hour, start.minute, start.second);
    if ((pid1 = fork()) == 0) {
        settickets(1);
        spin(1);
        exit();
    }
    else if ((pid2 = fork()) == 0) {
        settickets(8000000);
        spin(8000000);
        exit();
    }
    // Go to sleep and wait for subprocesses to finish
    wait();
    wait();
    exit();
    
}
