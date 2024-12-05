#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void swap(int *nums, int a, int b)
{
   int tmp = nums[a];
   nums[a] = nums[b];
   nums[b] = tmp;
   return;
}

void heapIns(int *heap, int size, int num)
{
   heap[size] = num;
   int cur = size;
   while (cur > 0)
   {
      int father = (cur - 1) / 2;
      if (heap[cur] <= heap[father])
         break;
      else
      {
         swap(heap, cur, father);
         cur = father;
      }
   }
   return;
}

void heapUpd(int *heap, int k, int num)
{
   // 新的数字大于等于堆顶，则不用处理
   // 因为此时，堆中的所有数字都比堆顶小，所以num肯定不是我们需要输出的数字
   if (heap[0] <= num)
      return;

   heap[0] = num;
   int cur = 0;
   int left = 2 * cur + 1;
   int right = 2 * cur + 2;
   while (left < k)
   {
      int child = cur;
      if (right < k && heap[right] > heap[left])
         child = right;
      else
         child = left;
      if (heap[child] <= heap[cur])
         break;
      else
      {
         swap(heap, child, cur);
         cur = child;
         left = 2 * cur + 1;
         right = 2 * cur + 2;
      }
   }
}

int *getLeastNumbers(int *nums, int len, int k)
{
   int *heap = malloc(sizeof(int) * k);
   memset(heap, 0, sizeof(int) * k);
   int idx = 0;
   for (; idx < k; ++idx)
      heapIns(heap, idx, nums[idx]);

   for (; idx < len; ++idx)
      heapUpd(heap, k, nums[idx]);

   return heap;
}

int main(int argc, char **argv)
{
   int len = argc - 1;
   int nums[len];
   for (int idx = 0; idx < len; ++idx)
      nums[idx] = atoi(argv[idx + 1]);
   int k;
   scanf("%d", &k);
   int *res = getLeastNumbers(nums, len, k);
   for (int idx = 0; idx < k; ++idx)
      printf("%d ", res[idx]);
   printf("\n");
}