#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    int priority, pid;

    if(argc < 3)
    {
        printf(2, "Usage: nice pid priority\n");
        exit();
    }
    pid = atoi(argv[1]);
    priority = atoi(argv[2]);
    if ((*argv[2]=='-') || (priority>20))
    {
        printf(2, "Invalid priority, must be in this range(0-20)!\n");
        exit();
    }
    printf(1, "pid=%d, pr=%d\n", pid, priority);
    chpr(pid, priority);
    exit();
}
