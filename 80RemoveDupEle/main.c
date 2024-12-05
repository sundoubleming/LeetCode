#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{  /*
   if(numsSize <= 2) return numsSize;
   int count = 1;
   int replace_idx = 0;
   int head = 0;
   int tail = 0;

   while(tail < numsSize)
   {
      if(nums[tail] == nums[head])  //重复时，tail继续移动
         ++tail;
      else
      {
         if(tail - head < 2) //重复数量小于2，开始检查下一个数
            nums[replace_idx++] = nums[head];
         else
         {
            nums[replace_idx++] = nums[head];
            nums[replace_idx++] = nums[head]; 
         }
         head = tail;
      }
   }
   if(tail - head < 2) //重复数量小于2，开始检查下一个数
      nums[replace_idx++] = nums[head];
   else
   {
      nums[replace_idx++] = nums[head];
      nums[replace_idx++] = nums[head]; 
   }
   return replace_idx;*/
   int len = 2;
	int i;

	if (numsSize <= 2)
		return numsSize;

	for (i = 2; i < numsSize; i++)
	{
        if( nums[i] != nums[len - 2] || nums[i] != nums[len - 1])
        {
            nums[len] = nums[i];
            len++;
        }
	}

	return len;
}

int main(int argc, char **argv)
{
   int numSize = argc - 1;
   int *nums = calloc(numSize, sizeof(int));
   for(int idx = 0; idx < numSize; ++idx)
      nums[idx] = atoi(argv[idx + 1]);
   
   printf("the length of result is: %d\n", removeDuplicates(nums, numSize));
   for(int idx = 0; idx < numSize; ++idx)
      printf("%d ", nums[idx]);
   printf("\n");
   return 0;
}