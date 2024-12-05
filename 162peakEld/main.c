#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize)
{
   int left = 0;
   int right = numsSize - 1;
   int mid = (left + right) / 2;

   while(left < right)
   {
      if(left == right) return left;
      if(nums[mid] > nums[mid + 1])
         right = mid;
      else
         left = mid + 1;

      mid = (left + right) / 2;
   }
}

int main(int argc, char **argv)
{
   int *nums = calloc(argc - 1, sizeof(int));
   int numsSize = argc - 1;
   for(int argIdx = 1; argIdx < argc; ++argIdx)
      nums[argIdx - 1] = atoi(argv[argIdx]);

   printf("the result is: %d\n", findPeakElement(nums, numsSize));
   free(nums);
   return 0;
}