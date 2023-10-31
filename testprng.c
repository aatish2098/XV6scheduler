#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int
main(int argc, char *argv[])
{   printf(2, "Invalid\n");
    //prng(atoi(argv[1]));
    double sum=0,min=0,max=-1;
     for (int i = 0; i < 1000; i++) {
      int random_num = prng();
      sum=sum+random_num;
      if (random_num <=min)
      {
        min=random_num;
      }
            if (random_num >=max)
      {
            max=random_num;
      }

 printf(1, "Random number: %d\n", random_num);
    }
    // Ensure it's a positive integer.
    
    printf(1, "Mean: %d\n", sum/1000);
     printf(1, "Minimum number: %d\n", min);
    printf(1, "Maximum number: %d\n", max);

    exit();
}
