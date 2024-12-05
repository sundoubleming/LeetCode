#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char product[10][10] = {
   {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
   {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
   {'0', '2', '4', '6', '8', '0', '2', '4', '6', '8'},
   {'0', '3', '6', '9', '2', '5', '8', '1', '4', '7'},
   {'0', '4', '8', '2', '6', '0', '4', '8', '2', '6'},
   {'0', '5', '0', '5', '0', '5', '0', '5', '0', '5'},
   {'0', '6', '2', '8', '4', '0', '6', '2', '8', '4'},
   {'0', '7', '4', '1', '8', '5', '2', '9', '6', '3'},
   {'0', '8', '6', '4', '2', '0', '8', '6', '4', '2'},
   {'0', '9', '8', '7', '6', '5', '4', '3', '2', '1'}
};

char plus[10][10] = {
   {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
   {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
   {'0', '0', '0', '0', '0', '1', '1', '1', '1', '1'},
   {'0', '0', '0', '0', '1', '1', '1', '2', '2', '2'},
   {'0', '0', '0', '1', '1', '2', '2', '2', '3', '3'},
   {'0', '0', '1', '1', '2', '2', '3', '3', '4', '4'},
   {'0', '0', '1', '1', '2', '3', '3', '4', '4', '5'},
   {'0', '0', '1', '2', '2', '3', '4', '4', '5', '6'},
   {'0', '0', '1', '2', '3', '4', '4', '5', '6', '7'},
   {'0', '0', '1', '2', '3', '4', '5', '6', '7', '8'}
};

void multiSingle(char *num1, char num, char *tmp)
{
   printf("|");
   char plusC = '0';
   __int32_t len1 = strlen(num1);
   int i = 0;
   for(i = len1 - 1; i >= 0; --i)
   {
      tmp[i + 1] = product[num - '0'][num1[i] - '0'] + (plusC - '0');
      if(tmp[i + 1] > '9')
      {
         tmp[i + 1] = tmp[i + 1] - 58 + '0';
         plusC = plus[num - '0'][num1[i] - '0'] + 1;
      }
      else
         plusC = plus[num - '0'][num1[i] - '0'];
      printf("%c * %c = %c & %c|", num1[i], num, tmp[i + 1], plusC);
   }
   tmp[0] = plusC;
   printf("======>%s\n", tmp);
}

void plusFunc(char *res, char *plusNum, int resB)
{
   char temp = '0';
   int tmpB = strlen(plusNum) - 1;
   while(tmpB >= 0)
   {
      temp = (plusNum[tmpB--] - '0') + (res[resB] - '0') + (temp - '0') + '0';
      if(temp > '9')
      {
         res[resB--] = temp - 58 + '0';
         temp = '1';
      }
      else
      {
         res[resB--] = temp;
         temp = '0';
      }
   }
   printf("======>%s\n", res);
}

char *multiply(char * num1, char * num2)
{
   if(strncmp(num1, "0", 1) == 0 || strncmp(num2, "0", 1) == 0) return "0";
   __uint32_t len1 = strlen(num1);
   __uint32_t len2 = strlen(num2);

   char *res = calloc(len1 + len2 + 1, sizeof(char));
   char *tmp = calloc(len1 + 2, sizeof(char));
   memset(res, '0', sizeof(char) * (len1 + len2));
   int resB = len1 + len2 - 1;
   for(int i = len2 - 1; i >= 0; --i)
   {
      // num2的每一个数都乘以num1
      multiSingle(num1, num2[i], tmp);
      plusFunc(res, tmp, resB--);
      memset(tmp, 0, sizeof(char) * (len1 + 1));
   }

   int i = 0;
   while(res[i] == '0') ++i;
   res = res + i;
   return res;
}

int main(int argc, char **argv)
{
   if(argc != 3)
   {
      printf("the call pattern is as \"./mutliStr 2 3\n\"");
      return 1;
   }

   char *res = multiply(argv[1], argv[2]);
   printf("The result is %s \n", res);
   
   //free(res);
   return 0;
}