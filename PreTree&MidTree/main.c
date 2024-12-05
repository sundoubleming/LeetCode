#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

struct TreeNode *handler(int *pre, int *vin, int len)
{
   if (len <= 0) return NULL;
   int idx = 0;
   while (idx < len) {
      printf("%d ", pre[idx++]);
   }
   printf("\n");
   idx = 0;
   while (idx < len) {
      printf("%d ", vin[idx++]);
   }
   printf("\n");
   int val = pre[0];
   idx = 0;
   while (vin[idx++] != val);
   struct TreeNode *root = malloc(sizeof(struct TreeNode));
   --idx;
   root->val = val,
   root->left = handler(pre + 1, vin, idx),
   root->right = handler(pre + idx + 1, vin + idx + 1, len - 1 - idx);
   return root;
}

struct TreeNode* reConstructBinaryTree(int* pre, int preLen, int* vin, int vinLen )
{
   if (pre == NULL || vin == NULL)
      return NULL;
   int val = pre[0];
   int idx = 0;         // 左子树的节点数及根在中序遍历中的下标
   while (vin[idx++] != val);
   struct TreeNode *root = malloc(sizeof(struct TreeNode));
   --idx;
   root->val = val,
   root->left = handler(pre + 1, vin, idx),
   root->right = handler(pre + idx + 1, vin + idx + 1, preLen - 1 - idx);

   return root;
}

int main(int argc, char **argv)
{
   int size = atoi(argv[1]);
   int pre[size];
   int vin[size];
   memset(pre, 0, sizeof(int) * size);
   memset(vin, 0, sizeof(int) * size);
   char c;
   int idx = 0;
   printf("input pre please:\n");
   while (idx < size) {
      c = getchar();
      pre[idx++] = atoi(&c);
      getchar();
   }

   idx = 0;
   printf("input vin please:\n");
   while (idx < size) {
      c = getchar();
      vin[idx++] = atoi(&c);
      getchar();
   }

   struct TreeNode *root = reConstructBinaryTree(pre, size, vin, size);

   return 0;
}