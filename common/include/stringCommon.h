#ifndef STRING_COMMON_H
#define STRING_COMMON_H

#include <sys/types.h>

/**
 * @brief 分割字符串成int数组
 * @param  buff             待分割的字符串
 * @param  retArr           存放结果的数组
 * @param  arrLen           retArr的长度
 * @param  delimiter        分割符
 * @return int 如果成功返回数组实际长度；失败返回-1
 */
int split(char *buff, int *retArr, u_int32_t arrLen, char delimiter);

/**
 * @brief 根据m n要求用户输入并生成m*n的矩阵
 * @param  m                矩阵的行数
 * @param  n                矩阵的列数
 * @return char**           矩阵
 */
char **buildBoard(int m, int n);
#endif