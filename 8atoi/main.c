#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int myAtoi(char * str)
{
   int start = 0;
   int ret = 0;
   int flag = 0; // 正负数标记
   while (str[start] == ' ') ++start;

   //不是数值则返回0
   if (str[start] != '+' && str[start] != '-' && str[start] > '9' && str[start] < '0')
      return 0;

   if (str[start] == '-')
   {
      flag = 1;
      ++start;
   }
   else
   {
      if (str[start] == '+')
      {
         flag = 0;
         ++start;
      }
   }

   double tmp = 0;
   while (str[start] >= '0' && str[start] <= '9')
   {
      if (ret * 10 + (str[start] - '0') < ret)
      //if (flag == 0 && (INT_MAX - (str[start] - '0')) / 10 <= ret && (INT_MAX - (str[start] - '0')) % 10 >= 7)
         return INT_MAX ;

      ret = ret * 10 + (str[start] - '0');
      ++start;
   }

   return flag ? 0 - ret : ret;
}

int main (int argc, char **argv)
{
   if (2 != argc || !argv[1])
   {
      printf("the call pattern as \"atoi.o -101010\n\"");
      return 1;
   }
   printf("the string is %s\n", argv[1]);

   printf("the ret is %d\n", myAtoi(argv[1]));

   return 0;
}