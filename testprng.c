#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int
main(int argc, char *argv[])
{
    int min=2147483647,max=-1;
    long sum=0;
     for (int i = 0; i < 1000; i++) {
      int random_num = prng();
      sum=sum+ (random_num/1000);
      if (random_num <=min)
      {
            min=random_num;
      }
      if (random_num >=max)
      {
            max=random_num;
      }

 printf(1, "%d\n", random_num);
    }
    // Ensure it's a positive integer.
    printf(1,"Mean \t Mininum \t Maximum \n");
    printf(1, " %d \t %d \t %d\n",sum,min,max);
//      printf(1, "Minimum number: %d\n", min);
//     printf(1, "Maximum number: %d\n", max);

    exit();
}
