#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void sort(int *nums, int start, int end)
{
   if (start >= end)
      return;
   int base = start;
   int left = start;
   int right = end;
   while (left < right) {
      while (nums[right] >= nums[base] && left < right) --right;
      while (nums[left] <= nums[base] && left < right) ++left;
      int tmp = nums[right];
      nums[right] = nums[left];
      nums[left] = tmp;
   }
   int tmp = nums[base];
   nums[base] = nums[left];
   nums[left] = tmp;
   sort(nums, start, left - 1);
   sort(nums, left + 1, end);
   return;
}

int handler(int num1, int num2, int num3, int **ret, int ret_idx)
{
   ret[ret_idx] = malloc(3 * sizeof(int));
   ret[ret_idx][0] = num1;
   ret[ret_idx][1] = num2;
   ret[ret_idx][2] = num3;
   return ++ret_idx;
}

int** threeSum(int* num, int numLen, int* returnSize, int** returnColumnSizes)
{
   int **ret = malloc(sizeof(int *) * numLen);
   memset(ret, 0, sizeof(int *) * numLen);
   int ret_idx = 0;
   sort(num, 0, numLen - 1);
   int left = 0;
   int right = numLen - 1;
   for (int idx = 0; idx < numLen; ++idx) {
      if (idx > 0 && num[idx] == num[idx - 1]) continue;
      int left = idx + 1;
      int right = numLen;
      while (left < right) {
         int base = num[idx];
         int left_num = num[left];
         int right_num = num[right];
         int sum = base + left_num + right_num;
         if (sum == 0) {
            ret_idx = handler(base, left_num, right_num, ret, ret_idx);
            while (num[left] == left_num) ++left;
            while (num[right] == right_num) --right;
         } else if (sum <= 0) {
            while (num[left] == left_num) ++left;
         } else {
            while (num[right] == right_num) --right;
         }
      }
   }
   *returnSize = ret_idx;
   return ret;
}

int main(int argc, char **argv)
{
   int count = argc - 1;
   int nums[count];
   memset(nums, 0, 0 * sizeof(int) * count);
   for (int idx = 0; idx < count; ++idx)
      nums[idx] = atoi(argv[idx + 1]);

   for (int idx = 0; idx < count; ++idx)
      printf("%d ", nums[idx]);
   printf("\n");
   sort(nums, 0, count - 1);

   int retSize = 0;
   int **ret = threeSum(nums, count - 1, &retSize, NULL);
   for (int idx = 0; idx < retSize; ++idx) {
      printf("%d %d %d\n", ret[idx][0], ret[idx][1], ret[idx][2]);
   }
   return 0;
}