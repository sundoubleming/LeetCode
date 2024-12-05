#ifndef TREE_NODE_H
#define TREE_NODE_H

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
   struct TreeNode *next;
};

/**
 * @brief 创建新的TreeNode节点
 * @param  val              My Param doc
 * @return struct TreeNode* 
 */
struct TreeNode *newNode(int val);

/**
 * @brief 根据二进制的输入创建二叉树：输入需要按照层次遍历，空的子树用null代替
 * @param  argc             二进制输入的个数
 * @param  argv             二进制输入的参数
 * @return struct TreeNode* 二叉树的根节点
 */
struct TreeNode *buildTree(int argc, char **argv);
#endif