#include <stdio.h>
#include "tree.h"

int dfs(struct TreeNode *root, struct TreeNode **stack, int *top, int *father, int o1, int o2)
{
   if (root == NULL)
      return -1;

   *top = *top + 1;
   stack[*top] = root;  //压栈
   if (root->val == o1 || root->val == o2) {
      if (*father == -1)         //确认第一个的位置
         *father = *top;
      else                       //确认到第二个，直接返回当前father即可
         return 0;
   }

   if (dfs(root->left, stack, top, father, o1, o2) == 0)
      return 0;
   if (dfs(root->right, stack, top, father, o1, o2) == 0)
      return 0;

   if (*father == *top) *father = *father - 1;
   *top = *top - 1;
   return -1;
}

int lowestCommonAncestor(struct TreeNode* root, int o1, int o2 )
{
   if (root == NULL) return -1;
   struct TreeNode *stack[1000] = {0};
   int father = -1;
   int top = -1;  //栈顶
   if (dfs(root, stack, &top, &father, o1, o2) == 0)
      return stack[father]->val;
   else
      return -1;
}

int main(int argc, char **argv)
{
   struct TreeNode *root = buildTree(argc, argv);
   int o1, o2;
   scanf("%d %d", &o1, &o2);
   printf("the common father is: %d\n", lowestCommonAncestor(root, o1, o2));
   return 0;
}