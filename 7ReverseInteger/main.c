#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse(int x)
{
   int flag = 0;
   if (x < 0)
      flag = 1;

   int ret = 0;
   int tmp = 0;
   if (flag == 0) {
      while (x >= 10) {
         tmp = x % 10;  // 如果x是负数,tmp也是负数
         x = x / 10;
         if ((INT_MAX - tmp) / 10 < ret) return 0;
         ret = ret * 10 + tmp;
      }
      if ((INT_MAX - x) / 10 < ret) return 0;
   } else {
      while (x <= -10) {
         tmp = x % 10;
         x = x / 10;
         if ((INT_MIN - tmp) / 10 > ret) return 0;
         ret = ret * 10 + tmp;
      }
      if ((INT_MIN - x) / 10 > ret) return 0;
   }

   ret = ret * 10 + x;

   return ret;
}

#if 0
void reverse_string(char *s, int len)
{
   int end = len;
   int start = 0;
   int tmp;
   while (end > start) {
      tmp = s[end];
      s[end] = s[start];
      s[start] = tmp;
      --end;
      ++start;
   }

   return;
}

int com_string(char *ret, int ret_idx, char *max_s, int max_idx)
{
   if (ret_idx < max_idx) {
      reverse_string(ret, ret_idx);
      return atoi(ret);
   } else if (ret_idx > max_idx) {
      return 0;
   }

   while (ret_idx >= 0) {
      if (ret[ret_idx] > max_s[ret_idx]) 
         return 0;
      else
         --ret_idx;
   }

   reverse_string(ret, ret_idx);
   return atoi(ret);
}

int reverse(int x)
{
   int flag = 0;
   if (x < 0) {
      flag = 1;
      x = 0 - x;
   }

   char max_s[100] = {0};
   int idx = 0;
   int tmp = 0;
   int max_int = INT_MAX;
   while (max_int >= 10) {
      tmp = max_int % 10;
      max_int = max_int / 10;
      max_s[idx++] = tmp + '0';
   }
   max_s[idx] = max_int + '0';
   int idx_max = idx;

   idx = 0;
   char ret[100] = {0};
   while (x >= 10) {
      tmp = x % 10;
      x = x / 10;
      ret[idx++] = tmp + '0';
   }
   ret[idx] = x + '0';
   reverse_string(ret, idx);

   int ret_int = com_string(ret, idx, max_s, idx_max);
   if (flag) {
      ret_int = 0 - ret_int;
      return ret_int == INT_MIN ? 0 : ret_int;
   } else {
      return ret_int == INT_MAX ? 0 : ret_int;
   }
}
#endif
int main(int argc, char **argv)
{
   printf("the reet of reverse %d is %d\n", atoi(argv[1]), reverse(atoi(argv[1])));
   return 0;
}