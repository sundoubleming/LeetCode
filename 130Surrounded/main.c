#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringCommon.h"

int isInBoard(int i, int j, int m, int n)
{
   if (i < m && i >= 0 && j < n && j >= 0)
      return 1;
   else
      return 0;
}

int isInEdge(int i, int j, int m, int n)
{
   if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
      return 1;
   else
      return 0;
}

int board_bfs(char **tmp, char **flags, int i, int j, int boardSize, int *boardColSize)
{
   int x[boardSize * boardColSize[0]];
   memset(x, 0, boardSize * boardColSize[0]);
   int y[boardSize * boardColSize[0]];
   memset(y, 0, boardSize * boardColSize[0]);
   int head = 0;
   int tail = 0;

   x[0] = i;
   y[0] = j;
   tail = 1;
   while(tail - head > 0)
   {
      tmp[x[head]][y[head]] = 'X';
      flags[x[head]][y[head]] = 1;
      int tmp_x = x[head];
      int tmp_y = y[head];
      ++head;
      //边缘检查，遇到边缘且为O则直接返回
      if (!isInBoard(tmp_x - 1, tmp_y, boardSize, boardColSize[0]) || 
         !isInBoard(tmp_x + 1, tmp_y, boardSize, boardColSize[0]) || 
         !isInBoard(tmp_x, tmp_y + 1, boardSize, boardColSize[0]) || 
         !isInBoard(tmp_x, tmp_y - 1, boardSize, boardColSize[0]))
         return 1;

      if (tmp[tmp_x - 1][tmp_y] == 'O')
      {
         if (!isInEdge(tmp_x - 1, tmp_y, boardSize, boardColSize[0]))
         {
            x[tail] = tmp_x - 1;
            y[tail] = tmp_y;
            ++tail;
         }
         else
            return 1;
      }
      
      if (tmp[tmp_x + 1][tmp_y] == 'O')
      {
         if (!isInEdge(tmp_x + 1, tmp_y, boardSize, boardColSize[0]))
         {
            x[tail] = tmp_x + 1;
            y[tail] = tmp_y;
            ++tail;
         }
         else
            return 1;
      }

      if (tmp[tmp_x][tmp_y - 1] == 'O')
      {
         if (!isInEdge(tmp_x, tmp_y - 1, boardSize, boardColSize[0]))
         {
            x[tail] = tmp_x;
            y[tail] = tmp_y - 1;
            ++tail;
         }
         else
            return 1;
      }

      if (tmp[tmp_x][tmp_y + 1] == 'O')
      {
         if (!isInEdge(tmp_x, tmp_y + 1, boardSize, boardColSize[0]))
         {
            x[tail] = tmp_x;
            y[tail] = tmp_y + 1;
            ++tail;
         }
         else
            return 1;
      }
   }

   return 0;
}


void solve(char** board, int boardSize, int* boardColSize)
{
   if (board == NULL || boardSize == 0 || boardColSize[0] == 0)
      return;

   char **tmp = calloc(boardSize, sizeof(char *));
   for (int i = 0; i < boardSize; ++i)
   {
      tmp[i] = calloc(boardColSize[i], sizeof(char));
      memcpy(tmp[i], board[i], sizeof(char) * boardColSize[i]);
   }
   char **flags = calloc(boardSize, sizeof(char *));
   for (int i = 0; i < boardSize; ++i)
   {
      flags[i] = calloc(boardColSize[i], sizeof(char));
   }

   for (int i = 0; i < boardSize; ++i)
   {
      for (int j = 0; j < boardColSize[i]; ++j)
      {
         if (tmp[i][j] == 'O' && flags[i][j] == 0)
         {
            int ret = board_bfs(tmp, flags, i, j, boardSize, boardColSize);
            if (ret == 1)
            {
               //board不动，需要把还原tmp，继续遍历
               for (int k = 0; k < boardSize; ++k)
                  memcpy(tmp[k], board[k], sizeof(char) * boardColSize[k]);
               continue;
            }

            //走到这说明没有遇到边界，则把tmp复制给board
            for (int k = 0; k < boardSize; ++k)
               memcpy(board[k], tmp[k], sizeof(char) * boardColSize[k]);
         }
      }
   }
   for (int i = 0; i < boardSize; ++i)
   {
      if (tmp[i]) free(tmp[i]);
   }
   free(tmp);
   for (int i = 0; i < boardSize; ++i)
   {
      if (flags[i]) free(flags[i]);
   }
   free(flags);
}

int main(int argc, char **argv)
{
   if (argc != 3 || atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
   {
      printf("the call pattern is such as:./main 3 2\n");
      return 1;
   }

   int boardSize = atoi(argv[1]);
   int *boardColSize = calloc(boardSize, sizeof(int));
   if (boardColSize)
   {
      for (int idx = 0; idx < boardSize; ++idx)
         boardColSize[idx] = atoi(argv[2]);
   }
   else
   {
      printf("calloc failed!\n");
      return 1;
   }

   char **board = buildBoard(boardSize, boardColSize[0]);
   if (board == NULL)
   {
      printf("calloc failed!\n");
      return 1;
   }

   solve(board, boardSize, boardColSize);

   for (int i = 0; i < boardSize; ++i)
   {
      for (int j = 0; j < boardColSize[i]; ++j)
         printf("%c ", board[i][j]);
      printf("\n");
   }

   for (int i = 0; i < boardSize; ++i)
   {
      if (board[i]) free(board[i]);
   }
   free(board);
   return 0;
}