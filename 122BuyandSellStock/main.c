#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int maxProfit(int* prices, int pricesSize)
{
   int end = pricesSize - 1;
   int ret = 0;
   int cur = 0;

   for (int idx = end - 1; idx >= 0; --idx) {
      int profit = prices[end] - prices[idx];
      if (profit < cur) {
         ret += cur;
         end = idx;
         cur = 0;
      } else {
         cur = profit;
      }
   }

   return ret + cur;
}

int main(int argc, char **argv)
{
   int size = argc - 1;
   int arr[size];
   for (int idx = 0; idx < size; ++idx)
      arr[idx] = atoi(argv[idx + 1]);

   printf("Max Profit = %d\n", maxProfit(arr, size));
}