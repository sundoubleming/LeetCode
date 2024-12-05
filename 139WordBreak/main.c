#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
   int size = strlen(s);
   int dp[size + 1];
   memset(dp, 0, sizeof(int) * (size + 1));
   dp[0] = 1;
   for (int i = 0; i < size; ++i)
   {
      for (int j = 0; j <wordDictSize; ++j)
      {
         int wordlen = strlen(wordDict[j]);
         if (i >= wordlen - 1)
         {
            if (strncmp(s + i - wordlen + 1, wordDict[j], wordlen) == 0 && dp[i - wordlen + 1] == 1)
            {
               dp[i + 1] = 1;
               break;
            }
         }
      }
   }
   return dp[size];
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is such as: ./main apple pen\n");
      return 1;
   }

   int wordDictSize = argc - 1;
   char **wordDict = argv + 1;
   printf("please input the string:\n");
   char buf[128] = {0};
   int size = read(STDIN_FILENO, buf, 128);
   buf[size - 1] = '\0';
   printf("%s\n", (wordBreak(buf, wordDict, wordDictSize) == 1)?"true":"false");
   return 0;
}