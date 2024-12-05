#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <tree.h>

void swap(struct TreeNode *a, struct TreeNode *b)
{
   int tmp = a->val;
   a->val = b->val;
   b->val = tmp;
   return;
}
 
void handler(struct TreeNode *root, struct TreeNode *pre, struct TreeNode *fir, struct TreeNode *sec)
{
   if (root == NULL)
      return;

   handler(root->left, pre, fir, sec);
   if (pre && pre->val > root->val) {
      if (fir == NULL)
         fir = pre;
      else 
         sec = root;
   }

   pre = root;
   handler(root->right, pre, fir, sec);
}

void recoverTree(struct TreeNode *root)
{
   if (root == NULL)
      return;
   struct TreeNode *pre = NULL;
   struct TreeNode *fir = NULL;
   struct TreeNode *sec = NULL;
   handler(root, pre, fir, sec);
   swap(fir, sec);
   return;
}

int main(int argc, char **argv)
{
   struct TreeNode *root = buildTree(argc, argv);
   recoverTree(root);
   return 0;
}