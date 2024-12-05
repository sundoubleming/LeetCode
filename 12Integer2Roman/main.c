#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct number{
   int val;
   char symbol;
   char sub_symbol;
};

struct number romans[] = {
   {1,      'I'},
   {10,     'X'},
   {100,    'C'},
   {1000,   'M'}
};

struct number sub_romans[] = {
   {5,      'V'},
   {50,     'L'},
   {500,    'D'}
};

char *intToRoman(int num)
{
   int cur_idx = 3;
   int tmp;
   static char ret[16];
   memset(ret, 0, 16);
   int ret_idx = 0;

   while (cur_idx >= 0) {
      tmp = num / romans[cur_idx].val;
      num = num % romans[cur_idx].val;

      if (tmp == 0) {
         --cur_idx;
         continue;
      }

      if (tmp / 5) {
         if (tmp == 9) {
            ret[ret_idx++] = romans[cur_idx].symbol;
            ret[ret_idx++] = romans[cur_idx + 1].symbol;
         } else {
            ret[ret_idx++] = sub_romans[cur_idx].symbol;
            for (int i = 0; i < tmp % 5; ++i)
               ret[ret_idx++] = romans[cur_idx].symbol;
         }
      } else {
         if (tmp == 4) {
            ret[ret_idx++] = romans[cur_idx].symbol;
            ret[ret_idx++] = sub_romans[cur_idx].symbol;
         } else {
            for (int i = 0; i < tmp; ++i)
               ret[ret_idx++] = romans[cur_idx].symbol;
         }
      }
      --cur_idx;
   }

   return ret;
}

int main(int argc, char **argv)
{
   printf("the result of intToRoman(%d) is %s\n", atoi(argv[1]), intToRoman(atoi(argv[1])));
   return 0;
}