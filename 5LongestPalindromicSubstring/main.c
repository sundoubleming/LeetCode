#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int len = 0;
char *g_s = NULL;
int max_start = 0;
int max_end = 0;

void palindrm(int start, int end)
{
   while (start >= 0 && end < len && g_s[start] == g_s[end]) {
      --start;
      ++end;
   }

   ++start;
   --end;

   if (start >= 0 && end < len && end - start > max_end - max_start) {
      max_start = start;
      max_end = end;
   }

   return;
}

char *longestPalindrome(char *s)
{
   len = strlen(s);
   g_s = s;
   for (int idx = 0; idx < len; ++idx) {
      if ((max_end - max_start + 1) / 2 > (len - idx))
         break;
      palindrm(idx, idx);
      palindrm(idx, idx + 1);
   }

   s[max_end + 1] = '\0';
   return s + max_start;
}

int main(int argc, char **argv)
{
   printf("the longest palindromic substring in %s is: %s\n", argv[1], longestPalindrome(argv[1]));
}