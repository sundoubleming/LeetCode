#include <string.h>
#include <stdio.h>
#include <string.h>

char *theLongestSubStr(char *str1, char *str2)
{
   int ret_i = 0;
   int ret_j = 0;
   int matrix[1001][1001] = {0};
   for (int i = 0; i < strlen(str1); ++i)
   {
      for (int j = 0; j < strlen(str2); ++j)
      {
         if (str1[i] == str2[j])
         {
            matrix[i + 1][j + 1] = matrix[i][j] + 1;
            if (matrix[i + 1][j + 1] > matrix[ret_i][ret_j])
            {
               ret_i = i;
               ret_j = j;
            }
         }
         else
         {
            matrix[i + 1][j + 1] = 0;
         }
      }
   }
   printf("%d %d\n", ret_i, ret_j);
   return NULL;
}

int main(int argc, char **argv)
{
   char str1[1000] = {0};
   char str2[1000] = {0};
   scanf("%s", str1);
   scanf("%s", str2);
   printf("%s %s\n", str1, str2);
   (void)theLongestSubStr(str1, str2);
   return 0;
}