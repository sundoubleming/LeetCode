#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int lengthOfLongestSubstring(char * s)
{
   if (s == NULL || strlen(s) == 0)
      return 0;
   int s_len = strlen(s);
   if (s_len == 0)
      return 0;

   int offset[128] = {0};  //保存下标加1
   int start = 0;
   int max = 0;
   int len = 0;
   for (int idx = 0; idx < s_len; ++idx) {
      // 在目前的最长子串中出现过
      if (offset[s[idx]] - 1 >= start) {
         len = idx - start;
         max = len > max ? len : max;
         // 此处start最多等于end，不会超过
         // 此处不用更新max，因为不可能更大
         start = offset[s[idx]];
      }
      offset[s[idx]] = idx + 1;
   }

   len = s_len - start;
   return max > len ? max : len;
}

int main(int argc, char **argv)
{
   printf("the length of the longest substring without repeating characters is: %d\n", lengthOfLongestSubstring(argv[1]));
}
