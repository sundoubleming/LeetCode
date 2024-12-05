#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor){
   unsigned int udividend;
   unsigned int udivisor;

   int flag = 0;
   if (dividend > 0 && divisor < 0) {
      flag = 1;
      udivisor = -divisor;
      udividend = dividend;
   }
   else if (dividend < 0 && divisor > 0) {
      flag = 1;
      udividend = -dividend;
      udivisor = divisor;
   }
   else if(dividend < 0 && divisor < 0) {
      udividend = -dividend;
      udivisor = -divisor;
   }
   else {
      udividend = dividend;
      udivisor = divisor;
   }

   int ret = 0;
   while (udividend >= udivisor) {
      int tmp = udivisor;
      int tmp_ret = 1;
      while (udividend > tmp) {
         tmp = tmp << 1;
         tmp_ret = tmp_ret << 1;
      }
      if (udividend == tmp) {
         ret += tmp_ret;
         ++ret;
         break;
      }
      udividend -= (tmp >> 1);
      ret += (tmp_ret >> 1);
   }

   return flag == 1 ? -ret : ret;
}

int main(int argc, char **argv)
{
   // 处理参数
   if(argc != 3 || 0 == atoi(argv[1]) || 0 == atoi(argv[2]))
   {
      printf("the call pattern as \"./divide 6 3\n\"");
      return 1;
   }

   printf("the result of %d / %d is: %d\n", atoi(argv[1]), atoi(argv[2]), divide(atoi(argv[1]), atoi(argv[2])));

   return 0;
}