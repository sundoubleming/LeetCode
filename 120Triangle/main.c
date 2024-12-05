#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringCommon.h>

#define SUM 200 * 10000;

int handler(int** triangle, int triangleSize, int* triangleColSize, int sum, int raw, int col)
{
   //raw和col表示上一层的坐标
   //当前是最后一层
   ++raw;
   int a = sum + triangle[raw][col];
   int b = sum + triangle[raw][col + 1];
   if (raw == triangleSize - 1)
   {
      return a < b ? a : b;
   }

   a = handler(triangle, triangleSize, triangleColSize, sum + triangle[raw][col], raw, col);
   if (col + 1 < triangleColSize[raw])
      b = handler(triangle, triangleSize, triangleColSize, sum + triangle[raw][col + 1], raw, col + 1);
   else
      b = SUM;
   return a < b ? a : b;
}
/*递归版本，耗时
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
   if (triangleSize == 0 || triangle == NULL)
   {
      return -1;
   }

   if (triangleSize == 1)
   {
      return triangle[0][0];
   }
   int cur_sum = triangle[0][0];
   int a = handler(triangle, triangleSize, triangleColSize, cur_sum, 0, 0);
   int b = handler(triangle, triangleSize, triangleColSize, cur_sum, 0, 0);
   return a < b ? a : b;
}
*/

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
   for (int i = triangleSize - 2; i >= 0; --i)
   {
      for (int j = 0; j < triangleColSize[i]; ++j)
      {
         triangle[i][j] += (triangle[i + 1][j] < triangle[i + 1][j + 1] ?
            triangle[i + 1][j] : triangle[i + 1][j + 1]);
      }
   }
   return triangle[0][0];
}

int main(int argc, char **argv)
{
   int triangleSize = 0;
   printf("input the sizeof Triangle:");
   scanf("%d", &triangleSize);
   getchar();
   char *triangleBuff[triangleSize];
   for (int idx = 0; idx < triangleSize; ++idx)
   {
      char *buff = calloc(1024, sizeof(char));
      scanf("%[^\n]", buff);
      getchar();
      triangleBuff[idx] = buff;
   }

   int **triangle = calloc(triangleSize, sizeof(int *));
   int *triangleColSize = calloc(triangleSize, sizeof(int));
   for (int idx = 0; idx < triangleSize; ++idx)
   {
      int arr[1024] = {0};
      int len = split(triangleBuff[idx], arr, 1024, ' ');
      if (len < 0)
      {
         printf("split(triangle[%d]) failed", idx);
         return -1;
      }
      triangle[idx] = calloc(len, sizeof(int));
      memcpy(triangle[idx], arr, len * sizeof(int));
      triangleColSize[idx] = len;
   }

   printf("the short path length is: %d\n", minimumTotal(triangle, triangleSize, triangleColSize));
   return 0;
}