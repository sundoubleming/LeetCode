#include <stdlib.h>
#include <stdio.h>

int maxArea(int* height, int heightSize)
{
   int start = 0;
   int end = heightSize - 1;
   int ret = ((height[start] > height[end]) ? height[end] : height[start]) * (end - start);

   if (height[start] > height[end]) 
      --end;
   else
      ++start;
   
   int tmp = 0;
   while(start < end)
   {
      tmp = ((height[start] > height[end]) ? height[end] : height[start]) * (end - start);
      if (tmp > ret)
         ret = tmp;

      if (height[start] > height[end]) 
         --end;
      else
         ++start;
   }

   return ret;
}

int main(int argc, char **argv)
{
   int heightSize = argc - 1;
   int *height = calloc(heightSize, sizeof(int));
   if (!height)
   {
      perror("CALLOC");
      return 1;
   }

   for (int argIdx = 1; argIdx < argc; ++argIdx)
      height[argIdx - 1] = atoi(argv[argIdx]);

   printf("the area is %d", maxArea(height, heightSize));
   free(height);

   return 0;
}