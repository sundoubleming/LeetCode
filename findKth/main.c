#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void swap(int *nums, int a, int b)
{
   int tmp = nums[a];
   nums[a] = nums[b];
   nums[b] = tmp;
   return;
}

int handler(int *nums, int start, int end, int K)
{
   if (start >= end)
      return nums[start];
   int base = nums[start];
   int right = end;
   int left = start;
   while (left < right)
   {
      while (left < right && nums[right] >= base) --right;
      while (left < right && nums[left] <= base) ++left;
      swap(nums, left, right);
   }

   swap(nums, start, left);
   if (left == K - 1) return nums[left];
   else if (left > K - 1)
      return handler(nums, start, left - 1, K);
   else
      return handler(nums, left + 1, end, K);
}

int findKth(int *nums, int len, int K)
{
   return handler(nums, 0, len - 1, K);
}

int main(int argc, char **argv)
{
   int nums[argc - 1];
   for (int idx = 0; idx < argc - 1; ++idx)
      nums[idx] = atoi(argv[idx + 1]);

   int K = 0;
   scanf("%d", &K);
   printf("the %dth is %d\n", K, findKth(nums, argc - 1, K));
   return 0;
}