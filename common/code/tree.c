#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>

/**
 * @brief 创建新的TreeNode节点
 * @param  val              My Param doc
 * @return struct TreeNode* 
 */
struct TreeNode *newNode(int val)
{
   struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
   if (root == NULL)
   {
      return NULL;
   }
   root->val = val;
   return root;
}

/**
 * @brief 根据二进制的输入创建二叉树：输入需要按照层次遍历，空的子树用null代替
 * @param  argc             二进制输入的个数
 * @param  argv             二进制输入的参数
 * @return struct TreeNode* 二叉树的根节点
 */
struct TreeNode *buildTree(int argc, char **argv)
{
   //该数组暂存TreeNode，用于取出下一步作为父节点的节点
   struct TreeNode *queue[argc - 1];
   int tail = 1;
   int cur = 0;
   int queue_tail = 1;
   struct TreeNode *root = newNode(atoi(argv[tail++]));
   queue[cur] = root;
   while(argc - 1 >= tail)
   {
      while(queue[cur] == NULL) ++cur;
      if (0 != strncmp("null", argv[tail], sizeof("null")))
      {
         queue[cur]->left = newNode(atoi(argv[tail++]));
      }
      else
      {
         ++tail;
         queue[cur]->left = NULL;
      }
      queue[queue_tail++] = queue[cur]->left;

      if (argc - 1 < tail)
      {
         break;
      }
      if (0 != strncmp("null", argv[tail], sizeof("null")))
      {
         queue[cur]->right = newNode(atoi(argv[tail++]));
      }
      else
      {
         ++tail;
         queue[cur]->right = NULL;
      }
      queue[queue_tail++] = queue[cur]->right;

      ++cur;
   }
   return root;
}