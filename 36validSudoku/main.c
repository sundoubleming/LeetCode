#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
   int flag[9][9] = {0};

   for(int i = 0; i < 9; ++i)
   {
      for(int j = 0; j < 9; ++j)
      {
         //printf("%d ", (j / 3) * 3 + i / 3);
         if(board[i][j] == '.') continue;

         int val = board[i][j] - '0' - 1;

         // 检查行
         if(flag[i][val] & (1 << 1)) return false;
         else flag[i][val] = flag[i][val] | (1 << 1);
         
         // 检查列
         if(flag[j][val] & (1 << 2)) return false;
         else flag[j][val] = flag[j][val] | (1 << 2);

         
         // 检查九宫格 
         if(flag[(j / 3) * 3 + i / 3][val] & (1 << 3)) return false;
         else flag[(j / 3) * 3 + i / 3][val] = flag[(j / 3) * 3 + i / 3][val] | (1 << 3);
      }
      //printf("\n");
   }

   return true;
}

int main()
{
   // 数独棋盘.
   char **board = calloc(9, sizeof(char *));
   for(int idx = 0; idx < 9; ++idx)
      board[idx] = calloc(9, sizeof(char));
   
   for(int i = 0; i < 9; ++i)
   {
      for(int j = 0; j < 9; ++j)
      {
         board[i][j] = getchar();
         getchar();
      }
   }

   printf("the result is: %s\n", (isValidSudoku(board, 9, NULL) ? "TRUE" : "FALSE"));
   
   /*
   for(int i = 0; i < 9; ++i)
   {
      for(int j = 0; j < 9; ++j)
         printf("%c ", board[i][j]);

      printf("\n");
   }*/
   
   free(board);
   return 0;
}