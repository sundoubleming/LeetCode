#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **res;
int resIdx;

/**
 * @brief 递归函数
 * @param  nums             输入数组
 * @param  numsSize         nums的长度
 * @param  returnSize       返回的数组的长度，表示集合的总数
 * @param  returnColumnSizes每个集合的长度
 * @param  aRes             当前集合
 * @param  cur              当前集合长度
 * @param  next             当前已经计算的nums长度
 */
void backTrace(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int *aRes, int cur, int next)
{
   res[resIdx++] = calloc(cur, sizeof(int));
   memcpy(res[resIdx], aRes, cur);
   *returnColumnSizes[resIdx] = cur;
   ++(*returnSize);
   if(cur == numsSize) return;

   int flag = nums[next];
   for(int i = next; i < numsSize; ++i)
   {
      aRes[cur] = nums[i];
      backTrace(nums, numsSize, returnSize, returnColumnSizes, aRes, ++cur, ++next);
      --cur;
      --next;
      while(i < numsSize && nums[i + i] == nums[i]) ++i;
   }

   return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
   res = calloc(numsSize ^ numsSize, sizeof(int *));
   resIdx = 0;
   int *aRes = calloc(numsSize, sizeof(int));
   backTrace(nums, numsSize, returnSize, returnColumnSizes, aRes, 0, 0);
   return res;
}

int main(int argc, char **argv)
{
   if(argc <= 1)
   {
      printf("the call pattern is as \"./subset.out 1 2 3 4 5\n\"");
      return 1;
   }

   //处理输入参数
   int numsSize = argc - 1;
   int *nums = calloc(argc - 1, sizeof(int));
   for(int i = 1; i < argc; ++i)
   {
      nums[i - 1] = atoi(argv[i]);
   }

   int **res = NULL;
   int *returnSize;
   int *returnColumnSize = calloc(numsSize ^ numsSize, sizeof(int));
   res = subsetsWithDup(nums, numsSize, returnSize, &returnColumnSize);

   for(int i = 0; i < *returnSize; ++i)
   {
      int size = returnColumnSize[i];
      for(int j = 0; j < size; ++j)
      {
         printf("%d ", res[i][j]);
      }
      printf("\n");
   }
   return 0;
}