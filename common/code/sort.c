#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void printNums(int *nums, int size)
{
   for (int idx = 0; idx < size; ++idx)
      printf("%d ", nums[idx]);
   printf("\n");
}

void swap(int *nums, int left, int right)
{
   int tmp = nums[left];
   nums[left] = nums[right];
   nums[right] = tmp;
   return;
}

//===========================快排====================================
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
   //printNums(nums, size);
   quickHandler(nums, start, left - 1, size);
   quickHandler(nums, left + 1, end, size);
   return;
}

void quickSort(int *input, int size)
{
   int nums[size];
   memcpy(nums, input, sizeof(int) * size);
   quickHandler(nums, 0, size - 1, size);
   printNums(nums, size);
}
//====================快排结束=====================================
void marge(int *nums, int start, int mid, int end)
{
   int len = end - start + 1;
   int tmp[len];
   int i = start;
   int j = mid + 1;
   int idx = 0;
   while (i <= mid && j <= end)
   {
      if (nums[i] < nums[j])
         tmp[idx++] = nums[i++];
      else
         tmp[idx++] = nums[j++];
   }
   if (i <= mid)
      for (;i <= mid; ++i)  tmp[idx++] = nums[i];
   if (j <= end)
      for (;j <= end; ++j)  tmp[idx++] = nums[j];
   memcpy(nums + start, tmp, sizeof(int) * len);
   return;
}


void binaryHandler(int *nums, int start, int end, int size)
{
   if (start >= end)
      return;

   int left = start;
   int right = end;
   int mid = left + (right - left) / 2;
   binaryHandler(nums, start, mid, size);
   binaryHandler(nums, mid + 1, end, size);
   marge(nums, start, mid, end);
   printNums(nums, size);
}

void binarySort(int *input, int size)
{
   int nums[size];
   memcpy(nums, input, sizeof(int) * size);
   binaryHandler(nums, 0, size - 1, size);
   printNums(nums, size);
   return;
}

void heapInsert(int *nums, int cur, int val)
{
   nums[cur] = val;
   int father = (cur - 1) / 2;
   while (father >= 0 && nums[father] > nums[cur])
   {
      swap(nums, father, cur);
      cur = father;
      father = (cur - 1) / 2;
   }
   return;
}

int min(int *nums, int cur, int left, int right, int size)
{
   // right存在且比left小
   if (right < size && nums[right] < nums[left])
   {
      if (nums[right] < nums[cur])
      {
         swap(nums, right, cur);
         return right;
      }
      else
         return cur;
   }
   else  // right不存在或left比right小
   {
      if (nums[left] < nums[cur])
      {
         swap(nums, left, cur);
         return left;
      }
      else
         return cur;
   }
}

void heapDelete(int *nums, int size)
{
   swap(nums, 0, size - 1);
   int cur = 0;
   int left = cur * 2 + 1;
   int right = cur * 2 + 2;
   int len = size - 2;
   while (left < size - 1 || right < size - 1)
   {
      int tmp = min(nums, cur, left, right, size - 1);
      if (tmp == cur)
         break;
      cur = tmp;
      left = cur * 2 + 1;
      right = cur * 2 + 2;
   }
   printNums(nums, size);
}

void heapSort(int *input, int size)
{
   int nums[size];
   memcpy(nums, input, sizeof(int) * size);

   for (int idx = 0; idx < size; ++idx)
      heapInsert(nums, idx, nums[idx]);

   for (int idx = 0; idx < size; ++idx)
      heapDelete(nums, size - idx);

   printNums(nums, size);
}

int main(int argc, char **argv)
{
   int size = argc - 1;
   int nums[size];
   for (int idx = 0; idx < size; ++idx)
      nums[idx] = atoi(argv[idx + 1]);

   quickSort( nums, size);
   //binarySort(nums, size);
   //heapSort(nums, size);
   return 0;
}