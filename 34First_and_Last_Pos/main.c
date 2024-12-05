#include <stdio.h>
#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
   // 处理特殊情况
   int *ret = calloc(2, sizeof(int));
   *returnSize = 2;
   ret[0] = -1;
   ret[1] = -1;
   if(numsSize == 0) return ret;
   if((nums[0] > target) || (nums[numsSize - 1] < target))
      return ret;

   int left = 0, right = numsSize;
   int mid = (left + right) / 2;

   // 找左边界
   while(left < right) 
   {
      if(nums[mid] == target)
         right = mid;
      else if(nums[mid] > target)
         right = mid;
      else
         left = mid + 1;

      mid = (left + right) / 2;
   }

   ret[0] = nums[left] == target ? left : -1;

   left = ret[0];
   right = numsSize;
   mid = (left + right) / 2;

   // 找右边界
   while(left < right)
   {
      if(nums[mid] == target)
         left = mid + 1;
      else if(nums[mid] > target)
         right = mid;
      else
         left = mid + 1;
      
      mid = (left + right) / 2;
   }

   ret[1] = nums[right - 1] == target ? (right - 1) : -1;

   return ret;
}

int main(int argc, char **argv)
{
   // 获取参数   ./pos &target [array]
   int numsSize = argc - 2;
   int target = atoi(argv[1]);
   int *nums = calloc(numsSize, sizeof(int));
   for(int argidx = 2; argidx < argc; ++argidx)
      nums[argidx - 2] = atoi(argv[argidx]);

   // 调用算法
   int returnSize = 0;
   int *ret = searchRange(nums, numsSize, target, &returnSize);

   if(!ret)
   {
      perror("searchRange");
      return 1;
   }

   printf("[ %d, %d ]\n", ret[0], ret[1]);
   free(ret);
   free(nums);
   return 0;
}