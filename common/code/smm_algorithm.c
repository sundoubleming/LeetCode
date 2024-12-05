#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int printArray(int *array, int cnt)
{
   printf("Array:");
   for (int idx = 0; idx < cnt; ++idx)
      printf("%d ", array[idx]);

   printf("\n");
}

/*===================================快排开始=======================================*/
int quickSortHandler(int *array, int cnt)
{
   int base = 0;
   int left = 0;
   int right = cnt - 1;
   while(left < right)
   {
      while(left < right && array[right] >= array[base])
         --right;
      while(left < right && array[left] <= array[base])
         ++left;

      int tmp = array[right];
      array[right] = array[left];
      array[left] = tmp;
   }
   int tmp = array[base];
   array[base] = array[left];
   array[left] = tmp;
   return left;
}

void quickSort(int *array, int cnt)
{
   if (cnt <= 1)
      return;

   int mid = quickSortHandler(array, cnt);
   quickSort(array, mid);
   quickSort(array + mid + 1, cnt - mid - 1);
}
/*===================================快排结束=======================================*/

/*===================================二分开始=======================================*/
//普通二分
int binarySearch(int *array, int cnt, int target)
{
   if (cnt <= 0)
      return -1;

   int left = 0;
   int right = cnt - 1;
   while(left <= right)
   {
      int mid = left + (right - left) / 2;
      if (array[mid] == target)
         return mid;
      else if(array[mid] > target)
         right = mid - 1;
      else
         left = mid + 1;
   }

   return -1;
}

//找左侧
int binarySearch_left(int *array, int cnt, int target)
{
   if (cnt <= 0)
      return -1;

   int left = 0;
   int right = cnt - 1;
   while(left <= right)
   {
      int mid = left + (right - left) / 2;
      if (array[mid] < target)
         left = mid + 1;
      else if(array[mid] >= target)
         right = mid - 1;
   }

   return array[left] == target ? left : -1;
}

//找右侧
int binarySearch_right(int *array, int cnt, int target)
{
   if (cnt <= 0)
      return -1;

   int left = 0;
   int right = cnt - 1;
   while(left <= right)
   {
      int mid = left + (right - left) / 2;
      if (array[mid] <= target)
         left = mid + 1;
      else if(array[mid] > target)
         right = mid - 1;
   }

   return array[right] == target ? right : -1;
}

void merga(int *array, int left1, int right1, int left2, int right2)
{
   int len1 = right1 - left1 + 1;
   int len2 = right2 - left2 + 1;
   int tmp[len1 + len2];

   int idx1 = left1;
   int idx2 = left2;
   int tmp_idx = 0;
   while (idx1 <= right1 && idx2 <= right2)
   {
      if (array[idx1] < array[idx2])
         tmp[tmp_idx++] = array[idx1++];
      else
         tmp[tmp_idx++] = array[idx2++];
   }

   if (idx1 <= right1)
   {
      for (int i = idx1; i <= right1; ++i)
         tmp[tmp_idx++] = array[i];
   }

   if (idx2 <= right2)
   {
      for (int i = idx2; i <= right2; ++i)
         tmp[tmp_idx++] = array[i];
   }
   printArray(tmp, len1 + len2);
   memcpy(array + left1, tmp, sizeof(int) * (len1 + len2));
   return;
}

void mergaSort(int *array, int cnt)
{
   // 递归返回条件
   if (cnt <= 1)
      return;
   int left = 0;
   int right = cnt - 1;
   int mid = left + (right - left) / 2;
   mergaSort(array, mid - left + 1);
   mergaSort(array + mid + 1, right - mid);
   merga(array, 0, mid, mid + 1, right);
}

int main(int argc, char **argv)
{
   int cnt = argc - 1;
   int *array = (int *)malloc(cnt * sizeof(int));
   memset(array, 0, cnt * sizeof(int));
   for (int idx = 0; idx < cnt; ++idx)
   {
      array[idx] = atoi(argv[idx + 1]);
   }

   printArray(array, cnt);
   mergaSort(array, cnt);
   //int target;
   //scanf("%d", &target);
   //printf("target is in index %d\n", binarySearch_right(array, cnt, target));
   return 0;
}