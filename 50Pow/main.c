#include <stdio.h>
#include <stdlib.h>

double myPow_Recursion(double x, unsigned int n)
{
   //递归函数中n绝对是正数
   if(n == 1)
   {
      return x;
   }

   double res= myPow_Recursion(x, n / 2);
   res = res * res * ((n % 2) ? x : 1);

   return res;
}

double myPow(double x, int n)
{
   if(x == 0.0)
   {
      return 0;
   }
   if(x == 1.0 || n == 1)
   {
      return x;
   }
   if(n == 0)
   {
      return 1;
   }
   if(n == -1)
   {
      return 1 / x;
   }
   
   int sign_flag = (n > 0) ? 1 : 0;       //n为正数时为1
   unsigned int nn = labs(n);
   double res = myPow_Recursion(x, nn / 2);
   res = res * res * ((nn % 2) ? x : 1);

   if(sign_flag == 0)
   {
      res = 1 / res;
   }
   return res;
}

int main(int argc, char **argv)
{
   //参数检查
   if(argc != 3)
   {
      printf("the call pattern is as \"./pow.out 2 2\n\"");
      return 1;
   }

   printf("the result is: %lf\n", myPow(atof(argv[1]), atoi(argv[2])));
}