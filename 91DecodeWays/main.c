#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isCharacter(char *s, int len)
{
   if (len != 1 && len != 2)
      return 0;

   if (len == 1)
   {
      if (s[0] <= '9' && s[0] >= '1')
         return 1;
      else
         return 0;
   }
   else
   {
      if (s[0] == '1' && s[1] <= '9' && s[1] >= '0')
         return 1;
      else if (s[0] == '2' && s[1] <= '6' && s[1] >= '0')
         return 1;
      else
         return 0;
   }
}

void handler(char *s, size_t len, int cur_idx, int *ret)
{
   // 递归退出条件
   if (cur_idx == len)
   {
      ++(*ret);
      return;
   }
   if (s[cur_idx] == '0' || cur_idx > len)
      return;

   // 处理小于10的情况
   if (isCharacter(s + cur_idx, 1) == 1)
      handler(s, len, cur_idx + 1, ret);
   if (cur_idx + 2 <= len && isCharacter(s + cur_idx, 2) == 1)
      handler(s, len, cur_idx + 2, ret);

   return;
}

// 递归解法
/*int numDecodings(char *s)
{
   int ret = 0;
   int cur_idx = 0;
   size_t len = strlen(s);
   handler(s, len, cur_idx, &ret);
   return ret;
}*/

//DP解法
int numDecodings(char *s)
{
   int cur_idx = 0;
   int len = strlen(s);
   int dp[len + 1];
   memset(dp, 0, (len + 1) * sizeof(int));
   dp[0] = 1;
   if (isCharacter(s, 1))
      dp[1] = 1;

   for(u_int32_t idx = 1; idx < len; ++idx)
   {
      dp[idx + 1] += isCharacter(s + idx, 1) ? dp[idx] : 0;
      dp[idx + 1] += isCharacter(s + idx - 1, 2) ? dp[idx - 1] : 0;
   }

   return dp[len];
}

int main(int argc, char **argv)
{
   if(argc != 2)
   {
      printf("the call pattern is as: ./main 225");
      return 1;
   }

   printf("the result is : %d\n", numDecodings(argv[1]));
   return 0;
}