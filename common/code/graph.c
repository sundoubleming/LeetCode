#include <graph.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief 用于生成一个新的Node节点，邻居列表为空
 * @param  val              当前节点的val值
 * @return struct* Node     节点，需要使用free释放
 */
struct Node *newNode(int val)
{
   struct Node *node = calloc(1, sizeof(struct Node));
   if (node == NULL)
      exit(1);
   node->val = val;

   return node;
}

/**
 * @brief 给node节点增加一个邻居
 * @param  node             待处理的节点
 * @param  neighbor         邻居节点
 */
void addNeighbor(struct Node *node, struct Node *neighbor)
{
   assert(node && neighbor);
   ++(node->numNeighbors);
   struct Node **tmp = realloc(node->neighbors, node->numNeighbors);
   if (tmp == NULL)
      exit(1);
   node->neighbors = tmp;
   node->neighbors[node->numNeighbors - 1] = neighbor;
   return;
}

/**
 * @brief 根据输入的矩阵生成有向图
 * @param  matrix           邻接矩阵
 * @param  m                矩阵的长度
 * @return struct Node*     图
 */
struct Node *newGraph(char **matrix, int m)
{
   struct Node *nodes = calloc(m, sizeof(struct Node));
   for (int i = 0; i < m; ++i)
   {
      nodes[i].val = i;
      nodes[i].neighbors = calloc(m, sizeof(struct Node *));
      nodes[i].numNeighbors = 0;
      for (int j = 0; j < m; ++j)
      {
         if (matrix[i][j])
         {
            nodes[i].neighbors[nodes[i].numNeighbors] = &(nodes[j]);
            ++(nodes[i].numNeighbors);
         }
      }
   }
   return nodes;
}