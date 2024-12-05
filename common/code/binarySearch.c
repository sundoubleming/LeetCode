#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int searchHandler(int *nums, int start, int end, int target)
{
   int left = start;
   int right = end;
   if (left > right) return -1;
   int mid = left + (right - left) / 2;
   if (nums[mid] == target)
      return mid;

   if (nums[mid] > target)
      return searchHandler(nums, left, mid - 1, target);
   else
      return searchHandler(nums, mid + 1, end, target);
}

int binarySearch(int *nums, int len, int target)
{
   return searchHandler(nums, 0, len - 1, target);
}

int searchFirstHandler(int *nums, int start, int end, int target)
{
   if (start > end) return -1;
   if (start == end && nums[start] == target) return start;
   int mid = start + (end - start) / 2;
   if (nums[mid] > target)
      return searchFirstHandler(nums, start, mid - 1, target);
   else if (nums[mid] < target)
      return searchFirstHandler(nums, mid + 1, end, target);
   else
      return searchFirstHandler(nums, start, mid, target);
}

int binarySearch_first(int *nums, int len, int target)
{
   //return searchFirstHandler(nums, 0, len - 1, target);
   int left = 0;
   int right = len - 1;
   if (nums[0] == target)
      return 0;

   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target && nums[mid - 1] != target) {
         return mid;
      }

      if (nums[mid] < target) {
         left = mid + 1;
      } else {
         right = mid - 1;
      }
   }
}

int binarySearch_last(int *nums, int len, int target)
{
   int left = 0;
   int right = len - 1;
   if (nums[right] == target)
      return right;
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target && nums[mid + 1] != target) {
         return mid;
      }

      if (nums[mid] <= target) {
         left = mid + 1;
      } else {
         right = mid - 1;
      }
   }

   return -1;
}

int main(int argc, char **argv)
{
   int len = argc - 1;
   int nums[len];
   for (int idx = 0; idx < len; ++idx)
      nums[idx] = atoi(argv[idx + 1]);

   int target = 0;
   scanf("%d", &target);
   printf("%d is in nums[%d]\n", target, binarySearch(nums, len, target));
   printf("%d is firstly in nums[%d]\n", target, binarySearch_first(nums, len, target));
   printf("%d is lastly in nums[%d]\n", target, binarySearch_last(nums, len, target));
   return 0;
}