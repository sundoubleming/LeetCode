#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize)
{
   int ret = 0;
   for (int offset = 0; offset < 32; ++offset) {
      int num = 0;
      for (int idx = 0; idx < numsSize; ++idx) {
         num += (nums[idx] >> offset) & 1;
         num = num % 3;
      }
      ret += num << offset;
   }
   return ret;
}

int main(int argc, char **argv)
{
   int size = argc - 1;
   int nums[size];
   for (int idx = 0; idx < size; ++idx)
      nums[idx] = atoi(argv[idx + 1]);

   printf("the single numbnle is %d\n", singleNumber(nums, size));
   return 0;
}