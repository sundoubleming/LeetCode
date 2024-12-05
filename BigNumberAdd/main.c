#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXINDEX 100000

int solve(char *s, char *t)
{
   // idx1 is the last index of s
   // idx2 is the last index of t
   int idx1 = strlen(s) - 1;
   int idx2 = strlen(t) - 1;
   char *tar = idx1 > idx2 ? s : t;
   int tar_idx = idx1 > idx2 ? idx1 : idx2;
   int flag = 0;
   while (idx1 >= 0 && idx2 >= 0)
   {
      char tmp = (s[idx1--] - '0') + (t[idx2--] - '0') + '0' + flag;
      if (tmp > '9')
      {
         flag = 1;
         tmp = tmp - '9' - 1 + '0';
      }
      else
      {
         flag = 0;
      }
      tar[tar_idx--] = tmp;
   }

   while (tar_idx >= 0 && flag == 1)
   {
      char tmp = tar[tar_idx] + flag;
      if (tmp > '9')
      {
         flag = 1;
         tmp = tmp - '9' - 1 + '0';
      }
      else
         flag = 0;
   }
   printf("the result is: %s\n", tar);
   return 0;
}

int main(int argc, char **argv)
{
   char num1[100000] = {0};
   char num2[100000] = {0};
   char tmp = 0;

   printf("please input the first big number:\n");
   int idx = 0;
   while ((tmp = getchar()) != '\n')
      num1[idx++] = tmp;

   printf("please input the second big number:\n");
   idx = 0;
   while ((tmp = getchar()) != '\n')
      num2[idx++] = tmp;

   printf("the first big numbers is:%s\n", num1);
   printf("the second big numbers is:%s\n", num2);

   (void)solve(num1, num2);
   return 0;
}