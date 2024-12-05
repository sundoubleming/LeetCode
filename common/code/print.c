#include <stdio.h>

/*
 * @brief 打印Int数组
 * @param array      数组起始地址
 * @param len        数组长度
*/
void PrintInts(int *array, int len) {
   for (int i = 0; i < len; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
}