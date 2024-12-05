#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void inputMatrx(int *matrx, int m, int n)
{
   for (int i = 0; i < m; ++i)
   {
      int *tmp = matrx + i * n;
      for (int j = 0; j < n; ++j)
         scanf("%d", tmp + j);
   }
   return;
}

void outputMatrx(int *matrx, int m, int n)
{
   for (int i = 0; i < m; ++i)
   {
      int *tmp = matrx + i * n;
      for (int j = 0; j < n; ++j)
         printf("%d ", *(tmp + j));
      printf("\n");
   }
   return;
}

int colHandler(int *matrx, int start, int end, int target, int n)
{
   if (start > end)
      return -1;

   int mid = start + (end - start) / 2;
   int row_start = *(matrx + mid * n);
   int row_end = *(matrx + (mid + 1) * n - 1);
   if (row_start <= target && row_end >= target)
      return mid;
   else if(row_start > target)
      return colHandler(matrx, start, mid - 1, target, n);
   else
      return colHandler(matrx, mid + 1, end, target, n);
}

int rowHandler(int *row, int start, int end, int target)
{
   if (start > end)
      return -1;

   int mid = start + (end - start) / 2;
   int mid_num = *(row + mid);
   if (mid_num == target)
      return mid;
   else if(mid_num > target)
      return rowHandler(row, start, mid - 1, target);
   else
      return rowHandler(row, mid + 1, end, target);
}

void binargInMatrx(int *matrx, int m, int n, int target)
{
   int target_m = colHandler(matrx, 0, m - 1, target, n);
   int target_n = rowHandler(matrx + target_m * n, 0, n - 1, target);
   printf("%d is in matrx[%d][%d]\n", target, target_m, target_n);
   return;
}

int main(int argc, char **argv)
{
   int m = atoi(argv[1]);
   int n = atoi(argv[2]);
   int matrx[m][n];
   int target = 0;
   inputMatrx((int *)matrx, m, n);
   scanf("%d", &target);
   outputMatrx((int *)matrx, m, n);
   binargInMatrx((int *)matrx, m, n, target);
}