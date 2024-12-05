#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void dfs_handler(struct TreeNode* root, int cur, int *sum)
{
   cur = cur * 10 + root->val;
   if (root->left == NULL && root->right == NULL)
   {
      *sum += cur;
   }
   else
   {
      if (root->left)
      {
         dfs_handler(root->left, cur, sum);
      }
      if (root->right)
      {
         dfs_handler(root->right, cur, sum);
      }
   }
}

int sumNumbers(struct TreeNode* root)
{
   if (root == NULL)
   {
      return 0;
   }
   int sum = 0;
   int cur = root->val;
   dfs_handler(root, 0, &sum);
   return sum;
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is as: ./main 1 2 3 4 5 null 6");
      return 1;
   }

   struct TreeNode *root = buildTree(argc, argv);
   if (root == NULL)
   {
      printf("the buildTree is failed");
      return 1;
   }

   printf("ret = %d\n", sumNumbers(root));
   return 0;
}