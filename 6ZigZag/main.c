#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
   int stringLen = strlen(s);
   if (stringLen == 0 || numRows == 0)
      return "";
   if (numRows == 1) return s;
   int turnTime = stringLen / (numRows * 2 - 2);  //从Z字的第一笔到斜线结束算一轮
   int numInTurn = numRows * 2 - 2;

   char *ret = calloc(1, stringLen + 1);
   if (!ret)
      return NULL;
   
   int retIdx = 0;
   for (int i = 0; i < turnTime; ++i)
      ret[retIdx++] = s[i * numInTurn];

   if (turnTime  * numInTurn < stringLen)
      ret[retIdx++] = s[turnTime * numInTurn];

   for (int i = 1; i < numRows; ++i)
   {
      for (int j = 0; j <= turnTime; ++j )
      {
         if ((i + j * numInTurn) < stringLen)
            ret[retIdx++] = s[i + j * numInTurn];
         
         if ( i < numRows - 1  && ((numInTurn - i + 1) + j * numInTurn) <= stringLen)
            ret[retIdx++] = s[(j + 1) * numInTurn - i];
      }
   }

   return ret;
}

int main (int argc, char **argv) 
{
   if (3 != argc || 0 >= atoi(argv[2]) || !argv[1])
   {
      printf("the call pattern as \"zigzag.o helloworld, 3\n\"");
      return 1;
   }
   printf("the string is %s\n", argv[1]);
   printf("the number of rows is %s\n", argv[2]);

   char *res = convert(argv[1], atoi(argv[2]));
   if (!res) 
   {
      perror("convert");
      return 1;
   }
   printf("the result is %s\n", res);
   free(res);
   
   return 0;
}