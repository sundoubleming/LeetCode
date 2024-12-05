#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 从cur往后找第一个和cur的val不同的值，返回其下标
int nextNum(int *nums, int end, int cur)
{
   int idx = cur + 1;
   while (idx < end && nums[idx] == nums[cur])
      ++idx;

   if (idx < end)
      return idx;
   else
      return -1;
}

// 从cur往前找第一个和cur的val不同的值，返回其下标
int preNum(int *nums, int start, int cur)
{
   int idx = cur - 1;
   while (idx > start && nums[idx] == nums[cur])
      --idx;

   if (idx > start)
      return idx;
   else
      return -1;
}

void aadRet(int base, int start, int end, int **ret, int *returnColumnSizes, int *returnSize)
{
   int *tmp = calloc(3, sizeof(int));
   tmp[0] = base;
   tmp[1] = start;
   tmp[2] = end;
   ret[*returnSize] = tmp;
   returnColumnSizes[*returnSize] = 3;
   ++(*returnSize);
   return;
}

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

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
   int *tmp_returnSize = calloc(1, sizeof(int)); 
   if (nums == NULL || numsSize < 3) {
      *returnSize = 0;
      returnColumnSizes = NULL;
      return NULL;
   }

   int tmp_nums[numsSize];
   memcpy(tmp_nums, nums, sizeof(int) * numsSize);
   quickHandler(tmp_nums, 0, numsSize - 1, numsSize);

   int retSize = numsSize * numsSize * numsSize;
   int **ret = calloc(retSize, sizeof(int *));
   int *columnSizes = calloc(retSize, sizeof(int));
   int base, start, end;

   for (int base = 0; base != -1;) {
      end = numsSize - 1;
      start = base + 1;
      while (start != -1 && end != -1) {
         int sum = tmp_nums[base] + tmp_nums[start] + tmp_nums[end];
         if (sum == 0) {
            aadRet(tmp_nums[base], tmp_nums[start], tmp_nums[end], ret, columnSizes, returnSize);
            start = nextNum(tmp_nums, end, start);
            end = preNum(tmp_nums, start, end);
         } else if (sum < 0)
            start = nextNum(tmp_nums, end, start);
         else
            end = preNum(tmp_nums, start, end);
      }

      base = nextNum(tmp_nums, numsSize - 2, base);
   }

   returnColumnSizes = &columnSizes;
   return ret;
}

int main(int argc, char **argv)
{
   int numsSize = argc - 1;
   int nums[numsSize];
   for (int idx = 0; idx < numsSize; ++idx)
      nums[idx] = atoi(argv[idx + 1]);

   int *returnSize = NULL;
   int **returnColumnSizes = NULL;
   int **ret = threeSum(nums, numsSize, returnSize, returnColumnSizes);

   for (int i = 0; i < *returnSize; ++i) {
      printf("%d %d %d\n", ret[i][0], ret[i][1], ret[i][2]);
   }

   return 0;
}