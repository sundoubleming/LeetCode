
/**
 * @file main.c
 * @brief 
 * @author sunminming (sundoubleming@163.com)
 * @date 2020-11-28
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int *nums, int numsSize, int target)
{
   if (numsSize == 0)
      return false;
   if (numsSize == 1)
   {
      if (nums[0] == target)
         return true;
      else
         return false;
   }

   int left = 0;
   int right = numsSize - 1;
   int mid;
   while (left <= right)
   {
      mid = (left + right) / 2;
      if (nums[mid] == target)
         return true;
      //右边按序
      if (nums[mid] < nums[right])
      {
         if (nums[mid] < target && target <= nums[right])
         {
            left = mid + 1;
         }
         else
         {
            right = mid - 1;
         }
      }
      //左边按序
      else if(nums[mid] > nums[right])
      {
         if (nums[left] <= target && target < nums[mid])
         {
            right = mid - 1;
         }
         else
         {
            left = mid + 1;
         }
      }
      else --right;
   }

   return false;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is as \"./search.out 1 2 3 4 5\n\"");
      return 1;
   }
   int nums[argc - 1];
   for (int idx = 0; idx < argc - 1; ++idx)
   {
      nums[idx] = atoi(argv[idx + 1]);
   }

   int target = 0;
   scanf("%d", &target);

   if (search(nums, argc - 1, target))
   {
      printf("%d is in nums\n", target);
   }
   else
   {
      printf("%d is not in nums\n", target);
   }

   return 0;
}