#include <stdio.h>
#include <string.h>
#include <stringCommon.h>
#include <graph.h>

int main()
{
   printf("input the size of nodes:\n");
   int size = 0;
   scanf("%d", &size);

   char **matrix = buildBoard(size, size);
   struct Node *node = newGraph(matrix, size);
   return 0;
}