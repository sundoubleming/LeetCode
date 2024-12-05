#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
   int cost_sum = 0;
   int gas_sum = 0;
   for (int idx = 0; idx < gasSize; ++idx)
   {
      cost_sum += cost[idx];
      gas_sum += gas[idx];
   }
   if (gas_sum < cost_sum) return -1;

   int cur_gas = 0;
   int cur_cost = 0;
   for (int s_idx = 0; s_idx < gasSize; ++s_idx)
   {
      cur_gas += gas[s_idx];
      cur_cost += cost[s_idx];

      if (cur_cost < cur_gas)
   }
}

int main(int argc, char **argv)
{
   if (argc != 2 || atoi(argv[1]) == 0)
   {
      printf("the call pattern is such as: main 3\n");
      return 1;
   }

   int gas[atoi(argv[1])];
   int cost[atoi(argv[1])];
   int idx = 0;

   printf("the gas of each station is: ");
   for (idx = 0; idx < atoi(argv[1]); ++idx)
   {
      scanf("%d", &gas[idx]);
   }

   printf("the cost of each station is: ");
   for (idx = 0; idx < atoi(argv[1]); ++idx)
   {
      scanf("%d", &cost[idx]);
   }

   for (idx = 0; idx < atoi(argv[1]); ++idx)
   {
      printf("%d ", gas[idx]);
   }
   printf("\n");
   for (idx = 0; idx < atoi(argv[1]); ++idx)
   {
      printf("%d ", cost[idx]);
   }
   printf("\n"); 
}