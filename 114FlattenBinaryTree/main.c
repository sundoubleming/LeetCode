#include <stdio.h>
#include <stdlib.h>
#include <tree.h>

void handler(struct TreeNode *root)
{
   //没有左子树不用处理
   if (root->left == NULL)
   {
      return;
   }

   struct TreeNode *tmp = root->right;
   root->right = root->left;
   root->left = NULL;
   struct TreeNode *right = root->right;

   //这里每次只会一直找到原左子树的最右叶节点，不会重复计算
   while(right->right)
   {
      right = right->right;
   }
   right->right = tmp;
   return;
}

void flatten(struct TreeNode* root)
{
   while(root)
   {
      handler(root);
      root = root->right;
   }
   return;
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is as: ./main 1 2 3 4 5 null 6");
      return 1;
   }

   struct TreeNode *root = buildTree(argc, argv);
   flatten(root);
   struct TreeNode *tmp = root;
   while(tmp)
   {
      printf("%d->", tmp->val);
      tmp = tmp->right;
   }
   printf("null\n");
}