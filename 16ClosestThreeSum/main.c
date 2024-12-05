#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

void swap(int *nums, int left, int right)
{
   int tmp = nums[left];
   nums[left] = nums[right];
   nums[right] = tmp;
   return;
}

void quickHandler(int *nums, int start, int end, int size)
{
   int left = start;
   int right = end;
   if (left >= right)
      return;
   int base = left;
   while (left < right)
   {
      while(left < right && nums[right] >= nums[base]) --right;
      while(left < right && nums[left] <= nums[base]) ++left;
      swap(nums, left, right);
   }
   swap(nums, base, left);
   quickHandler(nums, start, left - 1, size);
   quickHandler(nums, left + 1, end, size);
   return;
}

int nextNum(int *nums, int numsSize, int base) {
   int num = nums[base];
   int idx = base + 1;
   for (; idx < numsSize && nums[idx] == num; ++idx);
   return idx; 
}

int preNum(int *nums, int numsSize, int base) {
   int num = nums[base];
   int idx = base - 1;
   for (; idx >= 0 && nums[idx] == num; --idx);
   return idx;
}

int threeSumClosest(int* nums, int numsSize, int target) {
   quickHandler(nums, 0, numsSize - 1, numsSize);
   int ret = nums[0] + nums[1] + nums[numsSize - 1];
   for (int base = 0; base < numsSize; ++base) {
      int left = base + 1;
      int right = numsSize - 1;
      int tmp;
      while (left < right) {
         tmp = nums[base] + nums[left] + nums[right];
         if (abs(tmp - target) < abs(ret - target))
            ret = tmp;
         if (tmp == target)
            return tmp;
         if (tmp > target)
            --right;
         else
            ++left;
      }
   }

   return ret;
}

int main(int argc, char **argv) {
   int numsSize = argc - 2;

   int nums[numsSize];
   for (int idx = 0; idx < numsSize; ++idx) {
      nums[idx] = atoi(argv[idx + 1]);
   }

   int target = atoi(argv[argc - 1]);

   printf("the result of threeSumClosest is %d\n", threeSumClosest(nums, numsSize, target));
   return 0;
}