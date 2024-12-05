#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

struct ListNode *newListNode(int val)
{
   struct ListNode *node = calloc(1, sizeof(struct ListNode));
   node->val = val;
   node->next = NULL;
   return node;
}

struct TreeNode *newTreeNode(int val)
{
   struct TreeNode *node = calloc(1, sizeof(struct TreeNode));
   node->val = val;
   node->left = NULL;
   node->right = NULL;
   return node;
}

int getLength(struct ListNode *head)
{
   int ret = 0;
   while(head)
   {
      ++ret;
      head = head->next;
   }

   return ret;
}

struct TreeNode *handler(int l, int r, struct ListNode **head)
{
   //l == r时还有当前节点（第l/r个节点需要处理）
   if (l > r)
   {
      return NULL;
   }

   int mid = (l + r) / 2;
   struct TreeNode *left = handler(l, mid - 1, head);
   struct TreeNode *node = newTreeNode((*head)->val);
   *head = (*head)->next;
   node->left = left;
   node->right = handler(mid + 1, r, head);
   return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
   int r = getLength(head) - 1;

   return handler(0, r, &head);
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is as: main -10 -5 0 3 9");
      return -1;
   }

   struct ListNode *head = newListNode(atoi(argv[1]));
   struct ListNode *p = head;
   for(int idx = 2; idx < argc; ++idx)
   {
      p->next = newListNode(atoi(argv[idx]));
      p = p->next;
   }
   struct TreeNode *root = sortedListToBST(head);
/*
   while(head)
   {
      printf("%d->", head->val);
      head = head->next;
   }
   printf("NULL\n");
*/
   return 0;
}