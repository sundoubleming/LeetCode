#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <stringCommon.h>

/**
 * @brief 分割字符串成int数组
 * @param  buff             待分割的字符串
 * @param  retArr           存放结果的数组
 * @param  arrLen           retArr的长度
 * @param  delimiter        分割符
 * @return int 
 */
int split(char *buff, int *retArr, u_int32_t arrLen, char delimiter)
{
   char tmpBuff[1024] = {0};
   int start = -1;
   u_int32_t arrCur = 0;
   u_int32_t buffLen = strlen(buff);
   int idx = 0;
   for (; idx <= buffLen; ++idx)
   {
      if ((buff[idx] > '9' || buff[idx] < '0') && buff[idx] != '-')
      {
         if (buff[idx] != delimiter && idx != buffLen)
         {
            //既不是数字，也不是分隔符则报错
            return -1;
         }
         else
         {
            //截断单个数字
            memset(tmpBuff, 0, sizeof(char) * 1024);
            strncpy(tmpBuff, buff + start + 1, idx - start - 1);
            //赋值前先检查是否越界
            if (arrCur > arrLen)
            {
               return -1;
            }
            *(retArr + arrCur) = atoi(tmpBuff);
            ++arrCur;
            start = idx;
         }
      }
   }

   return arrCur;
}

/**
 * @brief 根据m n要求用户输入并生成m*n的矩阵
 * @param  m                矩阵的行数
 * @param  n                矩阵的列数
 * @return char**           矩阵
 */
char **buildBoard(int m, int n)
{
   if (m <= 0 || n <= 0)
      return NULL;
   char **board = calloc(m, sizeof(char *));
   if (board == NULL)
      return NULL;

   for (int i = 0; i < m; ++i)
   {
      board[i] = calloc(n, sizeof(char));
      if (board == NULL)
      {
         return NULL;
      }
      for (int j = 0; j < n; ++j)
      {
         board[i][j] = getchar();
         getchar(); //去掉空格和回车
      }
   }

   /*for (int i = 0; i < m; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         printf("%c ", board[i][j]);
      }
      printf("\n");
   }*/
   return board;
}