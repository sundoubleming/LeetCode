#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handler(const char *s1, const char *s2, const char *s3)
{
   if (s1 == NULL || s2 == NULL || s3 == NULL) return 0;
   int s1_len = strlen(s1);
   int s2_len = strlen(s2);
   if (s1_len + s2_len != strlen(s3)) {
      return 0;
   }
   int dp[s1_len + 1][s2_len + 1];

   dp[0][0] = 1;
   for (int i = 1; i <= s1_len; ++i) {
      if (s3[i - 1] == s1[i - 1])
         dp[i][0] = dp[i - 1][0];
      else
         dp[i][0] = 0;
   }
   for (int j = 1; j <= s2_len; ++j) {
      if (s3[j - 1] == s2[j - 1])
         dp[0][j] = dp[0][j - 1];
      else
         dp[0][j] = 0;
   }

   for (int i = 1; i <= s1_len; ++i) {
      for (int j = 1; j <= s2_len; ++j) {
         dp[i][j] = 0;
         if (s3[i + j - 1] == s1[i - 1])
            dp[i][j] = dp[i - 1][j];
         if (dp[i][j] == 1)   continue;
         if (s3[i + j - 1] == s2[j - 1])
            dp[i][j] = dp[i][j - 1];
      }
   }
   for (int i = 0; i <= s1_len; ++i) {
      for (int j = 0; j <= s2_len; ++j) {
         printf("%d ", dp[i][j]);
      }
      printf("\n");
   }

   return dp[s1_len][s2_len]; 
}

int main(int argc, char **argv)
{
   char *s1 = "a";
   char *s2 = "";
   char *s3 = "aa";

   printf("ret = %d\n", handler(s1, s2, s3));
}