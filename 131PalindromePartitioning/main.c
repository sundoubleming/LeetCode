#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
int handler(char *s, int start, char **cur, int cur_idx, char ***ret, int *ret_idx, char **book, int **returnColumnSizes)
{
   if (start >= strlen(s))
   {
      ret[*ret_idx] = cur;
      (*returnColumnSizes)[*ret_idx] = cur_idx;
      return ++(*ret_idx);
   }

   for (int end = start; end < strlen(s); ++end)
   {
      if ( book[start][end] == 1 ||
         (s[start] == s[end] && (end - start <= 2 || book[start + 1][end - 1] == 1)))
      {
         book[start][end] = 1;
         cur[cur_idx] = calloc(end - start + 2, sizeof(char));
         strncpy(cur[cur_idx], s + start, end - start + 1);
         handler(s, end + 1, cur, cur_idx + 1, ret, ret_idx, book, returnColumnSizes);
         free(cur[cur_idx]);
         cur[cur_idx] = NULL;
      }
   }
}

//returnSize是ret的长度
//returnColumnSizes是ret中每个元素的长度
char ***partition(char * s, int* returnSize, int** returnColumnSizes)
{
   int size = strlen(s);
   *returnColumnSizes = calloc(size * size, sizeof(int));
   *returnSize = 0;

   char ***ret = calloc(size * size, sizeof(char **));
   char **cur = calloc(size, sizeof(char *));
   char **book = calloc(size, sizeof(char *));
   for (int idx = 0; idx < size; ++idx)
      book[idx] = calloc(size, sizeof(char));
   handler(s, 0, cur, 0, ret, returnSize, book, returnColumnSizes);

   ++(*returnSize);
   return ret;
}
#endif

char dp[16][16] = {0};

void handler(char *s, int start, int *returnSize, int **returnColumnSizes, char **ret, int cur_idx)
{
   int len = strlen(s);
   if (start == len)

   for (int idx = start; idx < len; ++idx) {
      int left = idx;
      int right = idx;
      while (left >= start && right < len && s[left] == s[right]) {
         dp[left][right] = 1;
         --left;
         ++right;
      }

      left = idx;
      right = idx + 1;
      while (left >= start && right < len && s[left] == s[right]) {
         dp[left][right] = 1;
         --left;
         ++right;
      }
   }
}

//returnSize是ret的长度
//returnColumnSizes是ret中每个元素的长度
char ***partition(char * s, int* returnSize, int** returnColumnSizes)
{
   int len = strlen(s);
   returnSize = 0;
   *returnColumnSizes = malloc(sizeof(len * len));

   char **ret = malloc(sizeof(char *) * 16);

   for (int idx = 0; idx < len; ++idx) {
      int left = idx;
      int right = idx;
      while (left >= 0 && right < len && s[left] == s[right]) {
         dp[left][right] = 1;
         --left;
         ++right;
      }

      left = idx;
      right = idx + 1;
      while (left >= 0 && right < len && s[left] == s[right]) {
         dp[left][right] = 1;
         --left;
         ++right;
      }
   }



   return NULL;
}

int main(int argc, char **argv)
{
   if (argc != 2)
   {
      printf("the called pattern is such as: ./main abc \n");
      return 1;
   }


   int returnSize;
   int *returnColumnSizes;

   char ***ret = partition(argv[1], &returnSize, &returnColumnSizes);

   for (int i = 0; i < returnSize; ++i)
   {
      for (int j = 0; j < returnColumnSizes[i]; ++j)
         printf("%s ", ret[i][j]);

      printf("\n");
   }
   return 0;
}