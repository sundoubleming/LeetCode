#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "stringCommon.h"
#include "print.h"

// retutn a Next Array with the Same length as the pattern param, need free By Caller
int *GetNext(char *pattern, int len) {
   int *next = malloc(sizeof(int) * len);
   if (NULL == next) {
      return next;
   }
   memset(next, 0, sizeof(int) * len);
   next[0] = -1;
   int j = -1;
   int i = 0;
   for (; i < len;) {
      // j == -1作为一个特殊情况考虑，此时应该直接跳到0，既从头匹配
      if (j == -1 || pattern[i] == pattern[j]) {
         ++i;
         ++j;
         next[i] = j;
      } else {
         j = next[j];
      }
   }
   return next;
}

int Match(char *pattern, char *match, int *next, int p_len, int m_len) {
   int p = 0;
   int m = 0;
   for (;;) {
      while (p < p_len && m < m_len && pattern[p] == match[m]) {
         ++p;
         ++m;
      }
      if (p == p_len) {
         return m - p_len;
      }
      if (m == m_len) {
         return -1;
      }
      p = next[p];
      if (p == -1) {
         p = 0;
         ++m;
      }
   }
   return -1;
}

int main(int argc, char **argv) {
   if (argc < 3) {
      printf("KMP <pattern string> <match string>\n");
      return 1;
   }

   char *pattern = argv[1];
   char *match = argv[2];
   int p_len = strlen(pattern);
   int m_len = strlen(match);

   int *next = GetNext(pattern, p_len);
   printf("SubString Start At %d\n", Match(pattern, match, next, p_len, m_len));
}