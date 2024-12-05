#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursionFunc(int retCnt, char **ret, char *parenthsis, int leftCnt, int rightCnt, int n)
{
   // ret的范围
   if(100000 == retCnt)
      return retCnt;

   // 括号数量等于2n
   if(leftCnt + rightCnt == 2 * n)
   {
      char *tmp = malloc((2 * n + 1) * sizeof(char));
      memcpy(tmp, parenthsis, 2 * n + 1);
      ret[retCnt++] = tmp;
      return retCnt;
   }

   // 左右括号匹配，只能放左括号
   if(leftCnt - rightCnt == 0)
   {
      parenthsis[leftCnt + rightCnt] = '(';
      retCnt = recursionFunc(retCnt, ret, parenthsis, ++leftCnt, rightCnt, n);
      --leftCnt;
      parenthsis[leftCnt + rightCnt] = '\0';
   }
   else
   {
      // 不相等只有左括号大于右括号的情况：既可以放左括号，也能放右括号
      if(leftCnt < n)
      {
         // 先放左括号
         parenthsis[leftCnt + rightCnt] = '(';
         retCnt = recursionFunc(retCnt, ret, parenthsis, ++leftCnt, rightCnt, n);
         --leftCnt;
         parenthsis[leftCnt + rightCnt] = '\0';
      }

      // 再放右括号
      parenthsis[leftCnt + rightCnt] = ')';
      retCnt = recursionFunc(retCnt, ret, parenthsis, leftCnt, ++rightCnt, n);
      --rightCnt;
      parenthsis[leftCnt + rightCnt] = '\0';
   }
   
   return retCnt;
}
 
/*char ** generateParenthesis(int n, int* returnSize)
{
   char **ret = calloc(100000, sizeof(char *));
   if(!ret)
      return ret;
   
   char tmp[n * 2 + 1];
   memset(tmp, 0, n * 2 + 1);
   tmp[0] = '(';
   
   *returnSize = recursionFunc(0, ret, tmp, 1, 0, n);

   return ret;
}*/

char **generateParenthesis(int n, int* returnSize) {
   *returnSize = 0;
   char **ret = calloc(10000, sizeof(char *));
   if (!ret)
      return ret;

   int stack[10000] = {0};
   int top = -1;
   int idx = 0;
   int left = 0;
   int right = 0;

   ret[idx] = calloc(2 * n + 1, sizeof(char));
   stack[++top] = idx;
   stack[++top] = left;
   stack[++top] = right;

   while (top != -1) {
      right = stack[top--];
      left = stack[top--];
      idx = stack[top--];

      if (right == left) {
         if (left == n) {
            continue;
         }
         else {
            ret[idx][left + right] = '(';
            stack[++top] = idx;
            stack[++top] = left + 1;
            stack[++top] = right;
         }
      }
      else {
         if (left == n) {
            ret[idx][left + right] = ')';
            stack[++top] = idx;
            stack[++top] = left;
            stack[++top] = right + 1;
         }
         else {
            int tmp_idx = ++(*returnSize);
            ret[tmp_idx] = calloc(2 * n + 1, sizeof(char));
            memcpy(ret[tmp_idx], ret[idx], strlen(ret[idx]));
            ret[tmp_idx][left + right] = '(';
            stack[++top] = tmp_idx;
            stack[++top] = left + 1;
            stack[++top] = right;

            ret[idx][left + right] = ')';
            stack[++top] = idx;
            stack[++top] = left;
            stack[++top] = right + 1;
         }
      }
   }
   ++(*returnSize);
   return ret;
}

int main(int argc, char **argv)
{
   // 处理参数
   if(argc != 2 || 0 == atoi(argv[1]))
   {
      printf("the call pattern as \"./parenthese 3\n\"");
      return 1;
   }
   int parenthesesCount = atoi(argv[1]);
   
   int *returnSize = malloc(sizeof(int));
   *returnSize = 0;
   char **ret = generateParenthesis(parenthesesCount, returnSize);

   for(int idx = 0; idx < *returnSize && ret[idx] != NULL; ++idx)
   {
      printf("%s\n", ret[idx]);
      free(ret[idx]);
   }
   free(returnSize);
   free(ret);
   return 0;
}