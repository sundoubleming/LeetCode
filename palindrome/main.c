#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int handler(char *string, int size)
{
   char dp[size][size];
   memset(dp, 0, size * size * sizeof(char));
   for (int idx = 0; idx < size; ++idx)
      dp[idx][idx] = 1;

   int ret = 1;
   for (int right = 1; right < size; ++right)
   {
      for (int left = right - 1; left >= 0; --left)
      {
         if (string[left] != string[right])
            continue;
         if (right - left <= 1)
         {
            dp[left][right] = 1;
            ret = ret > 2 ? ret : 2;
            continue;
         }
         else if (dp[left + 1][right - 1])
         {
            dp[left][right] = 1;
            ret = ret > (right - left + 1) ? ret : (right - left + 1);
         }
      }
   }
   return ret;
}

int main(int argc, char **argv)
{
   int size = strlen(argv[1]);

   printf("the length is %d\n", handler(argv[1], size));
   return 0;
}