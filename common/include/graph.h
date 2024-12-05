#ifndef GRAPH_H
#define GRAPH_H

struct Node {
   int val;
   int numNeighbors;
   struct Node** neighbors;
};

/**
 * @brief 用于生成一个新的Node节点，邻居列表为空
 * @param  val              当前节点的val值
 * @param  max_neighbors    最大可能的邻居数量，一般传图中节点数量
 * @return struct* Node     节点，需要使用free释放
 */
struct Node *newNode(int val);

/**
 * @brief 给node节点增加一个邻居
 * @param  node             待处理的节点
 * @param  neighbor         邻居节点
 */
void addNeighbor(struct Node *node, struct Node *neighbor);

/**
 * @brief 根据输入的矩阵生成有向图
 * @param  matrix           邻接矩阵
 * @param  m                矩阵的长度
 * @return struct Node*     图
 */
struct Node *newGraph(char **matrix, int m);

#endif
