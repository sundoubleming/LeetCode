#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
   int val;
   struct Node *left;
   struct Node *right;
   struct Node *next;
};

struct Node *newNode(int val)
{
   struct Node *root = calloc(1, sizeof(struct Node));
   root->val = val;
   root->left = NULL;
   root->right = NULL;
   root->next = NULL;
}

struct Node *buildTree(int argc, char **argv)
{
   //该数组暂存TreeNode，用于取出下一步作为父节点的节点
   struct Node *queue[argc - 1];
   int tail = 1;
   int cur = 0;
   int queue_tail = 1;
   struct Node *root = newNode(atoi(argv[tail++]));
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

struct Node *findNext(struct Node* root)
{
   struct Node *rootNext = root->next; 
   while(rootNext)
   {
      if (rootNext->left)
      {
         return rootNext->left;
      }
      if (rootNext->right)
      {
         return rootNext->right;
      }
      
      rootNext = rootNext->next;
   }
   return NULL;
}

struct Node* connect(struct Node* root)
{
	if (root == NULL)
   {
      return root;
   }
   
   //通过父节点寻找同层的下一个节点
   struct Node *next = findNext(root);
   if (root->left)
   {
      root->left->next = root->right ? root->right : next;
   }

   if (root->right)
   {
      root->right->next = next;
   }

   root->right = connect(root->right);
   root->left = connect(root->left);
   
   return root;
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is as: ./main 1 2 3 4 5 null 7");
      return 1;
   }

   struct Node *root = buildTree(argc, argv);
   root = connect(root);
   return 0;
}