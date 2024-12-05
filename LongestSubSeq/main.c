#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 找array中第一个比target大的数字的下标
int binary_search(int *array, int start, int end, int target)
{
   if (start > end) return -1;
   int mid = start + (end - start) / 2;
   
   if (array[mid] >= target){
      if (mid - 1 >= 0 && array[mid - 1] < target)
         return mid;
      else
         return binary_search(array, start, mid - 1, target);
   }
   else  //array[mid] < target
      return binary_search(array, mid + 1, end, target);
}

int handler(int *num, int size)
{
   int max_nums[size + 1];
   memset(max_nums, 0, sizeof(int) * (size + 1));

   int dp[size];
   // dp[i] = dp[j] + 1，其中j是0~i - 1中，dp最大的，且num[j] <= num[i]
   memset(dp, 0, sizeof(int) * size);

   dp[0] = 1;
   max_nums[1] = 1;
   int top = 1;
   for (int idx = 1; idx < size; ++idx) {
      if (num[idx] > max_nums[top]) {
         ++top;
         dp[idx] = top;
         max_nums[top] = num[idx];
      } else {
         //二分法找第一个大于num[idx]的并代替其位置
         int tmp_idx = binary_search(max_nums, 0, top, num[idx]);
         max_nums[tmp_idx] = num[idx];
         dp[idx] = tmp_idx;
      }
   }
   return top;
}

int main(int argc, char **argv)
{
   int size = argc - 1;
   int num[size];
   for (int idx = 0; idx < size; ++idx) {
      num[idx] = atoi(argv[idx + 1]);
   }

   //int target = 0;
   //printf("please input target: \n");
   //scanf("%d", &target);
   //int ret = binary_search(num, 0, size - 1, target);
   int ret = handler(num, size);
   printf("ret = %d\n", ret);
}