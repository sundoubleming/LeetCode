#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
   struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
   root->val = val;
   return root;
}

struct TreeNode *buildTree(int argc, char **argv)
{
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

void handler(struct TreeNode *root, int targetSum, int *returnSize, int **returnColumSizes, 
   int *tmp, int tmp_cur, int **ret, int cur_sum)
{
   if (root == NULL)
   {
      return;
   }
   cur_sum += root->val;
   tmp[tmp_cur++] = root->val;
   //非叶节点，直接加上之后继续递归
   if (root->left != NULL || root->right != NULL)
   {
      handler(root->left, targetSum, returnSize, returnColumSizes, tmp, tmp_cur, ret, cur_sum);
      handler(root->right, targetSum, returnSize, returnColumSizes, tmp, tmp_cur, ret, cur_sum);
   }
   else
   {
      if (cur_sum == targetSum)
      {
         ret[*returnSize] = calloc(tmp_cur, sizeof(int));
         memcpy(ret[*returnSize], tmp, tmp_cur * sizeof(int));
         (*returnColumSizes)[*returnSize] = tmp_cur;
         ++(*returnSize);
      }
   }

   return;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumSizes)
{
   *returnColumSizes = calloc(5000, sizeof(int));
   *returnSize = 0;
   int *tmp = calloc(5000, sizeof(int));
   int **ret = calloc(5000, sizeof(int *));
   if (root == NULL)
   {
      return ret;
   }
   tmp[0] = root->val;
   if (root->val == targetSum && root->left == NULL && root->right == NULL)
   {
      ret[*returnSize] = calloc(1, sizeof(int));
      memcpy(ret[*returnSize], tmp, 1 * sizeof(int));
      (*returnColumSizes)[*returnSize] = 1;
      ++(*returnSize);
   }
   else
   {
      handler(root->left, targetSum, returnSize, returnColumSizes, tmp, 1, ret, root->val);
      handler(root->right, targetSum, returnSize, returnColumSizes, tmp, 1, ret, root->val);
   }
   return ret;
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is as: ./main 5 4 8 11 null 13 4 7 2 null null 5 1");
      return 1;
   }
   struct TreeNode *root = buildTree(argc, argv);

   int targetSum = 0;
   scanf("%d", &targetSum);
   int returnSize = 0;
   int *returnColumSizes = calloc(5000, sizeof(int));
   int **ret = pathSum(root, targetSum, &returnSize, &returnColumSizes);
   return 0;
}