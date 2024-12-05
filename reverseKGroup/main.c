#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct listNode {
   int val;
   struct listNode *next;
}  listNode;

listNode *new_Node(int val)
{
   listNode *node = malloc(sizeof(listNode));
   node->val = val;
   node->next = NULL;
   return node;
}

listNode *reverse(listNode *head)
{
   listNode *newHead = NULL;
   while (head)
   {
      listNode *tmp = head;
      head = head->next;
      tmp->next = newHead;
      newHead = tmp;
   }
   return newHead;
}

//head表示要翻转的子list的前一个node
listNode *handler(listNode *head, int k)
{
   int size = 0;
   listNode *newHead = NULL;  // 翻转后的子链表的第一个node
   listNode *node = head->next;  // 需要翻转的节点
   if (node == NULL)
      return NULL;
   listNode *tail = node;
   while (node && size < k)
   {
      ++size;
      listNode *tmp = node->next;   // 记录正序节点
      node->next = newHead;
      newHead = node;
      node = tmp;
   }

   if (size < k)
   {
      head->next = reverse(newHead);
      return NULL;
   }
   else
   {
      head->next = newHead;
      tail->next = node;
      return tail;
   }
}

void reverseKGroup(listNode *head, int k)
{
   listNode *node = head;
   while (node)
      node = handler(node, k);
   return;
}

int main(int argc, char **argv)
{
   listNode *head = new_Node(0);
   listNode *tail = head;
   for (int idx = 0; idx < argc - 1; ++idx)
   {
      listNode *new = new_Node(atoi(argv[idx + 1]));
      tail->next = new;
      tail = new;
   }
   int k = 0;
   scanf("%d", &k);
   reverseKGroup(head, k);
   //handler(head, 2);
   tail = head->next;
   while (tail)
   {
      printf("%d ", tail->val);
      tail = tail->next;
   }
   printf("\n");
   return 0;
}