#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void nextPermutation(int* nums, int numsSize) {
   if (nums == NULL || numsSize <= 1) {
      return;
   }

   int idx;
   for (idx = numsSize - 2; idx >=0; --idx) {
      if (nums[idx] < nums[idx + 1]) {
         swap(nums, idx, idx + 1);
         break;
      }
   }
   
   if (idx == -1) {
      reversal(nums, numsSize);
   }
   else {
      sort(nums + idx + 1, numsSize);
   }
}

int main(int argc, char **argv) {
   int nums[argc - 1];
   for (int idx = 0; idx < argc - 1; ++idx) {
      nums[idx] = atoi(argv[idx + 1]);
   }

   nextPermutation(nums, argc - 1);
   for (int idx = 0; idx < argc - 1; ++idx) {
      printf("%d ");
   }
   printf("\n");
   return 0;
}