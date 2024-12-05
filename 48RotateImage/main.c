#include <stdio.h>
#include <stdlib.h>

void swap(int *source, int *target)
{
   int temp = *target;
   *target = *source;
   *source = temp;
}

void deal_offset(int** matrix, __uint32_t turn, __uint32_t offset, __uint32_t edge)
{
   int temp = 0;
   //左上matrix[turn][turn]             右上matrix[turn][turn + edge]
   //左下matrix[turn + edge][turn]      右下matrix[turn + edge][turn + edge]
   temp = matrix[turn][turn + offset];
   swap(&temp, &(matrix[turn + offset][turn + edge]));
   swap(&temp, &(matrix[turn + edge][turn + edge - offset]));
   swap(&temp, &(matrix[turn + edge - offset][turn]));
   swap(&temp, &(matrix[turn][turn + offset]));
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
   //按圈处理， turnCount 表示要处理的圈数
   __uint32_t turnMax = matrixSize / 2;
   
   for(__uint32_t i = 0; i < turnMax; ++i)
   {
      // 对于每圈
      __uint32_t edge = matrixSize - 2 * i - 1;
      for(__uint32_t offset = 0; offset < edge; ++offset)
      {
         deal_offset(matrix, i, offset, edge);
      }
   }
   return;
}

int main(int argc, char **argv)
{
   if(argc != 2 || 0 == atoi(argv[1]))
   {
      printf("the call pattern is as \"./rotateImage.out 2\n\"");
      return 1;
   }

   // image
   __int32_t size = atoi(argv[1]);
   int **matrix = calloc(size, sizeof(int *));
   for(int idx = 0; idx < size; ++idx)
      matrix[idx] = calloc(size, sizeof(int));

   for(int i = 0; i < size; ++i)
   {
      for(int j = 0; j < size; ++j)
      {
         //matrix[i][j] = getchar() - '0';
         scanf("%d", &(matrix[i][j]));
         getchar();
      }
   }
   
   rotate(matrix, size, NULL);
   
   for(int i = 0; i < size; ++i)
   {
      for(int j = 0; j < size; ++j)
         printf("%d ", matrix[i][j]);

      printf("\n");
   }
   return 0;
}