#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int numTrees(int n)
{
   int dp[n + 1];
   memset(dp, 0, sizeof(int) * (n + 1));
   dp[0] = 1;
   dp[1] = 1;
   for (int i = 2; i <= n; ++i) {
      int sum = 0;
      for (int root = 0; root < i; ++root) {
         int left_num = root;
         int right_num = i - root - 1;
         sum += (dp[left_num] * dp[i - root - 1]);
      }
      dp[i] = sum;
   }
   return dp[n];
}

int main(int argc, char **argv)
{
   printf("ret = %d\n", numTrees(atoi(argv[1])));
}