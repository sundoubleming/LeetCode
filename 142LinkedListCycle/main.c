#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
   if (head == NULL) return NULL;
   struct ListNode *slow_p = head;
   struct ListNode *fast_p = head;

   while (slow_p && fast_p)
   {
      slow_p = slow_p->next;
      if (fast_p->next)
         fast_p = fast_p->next->next;
      else
         return NULL;

      if (slow_p == fast_p)
         break;
   }
   if (fast_p == NULL || slow_p == NULL)
      return NULL;

   slow_p = head;
   while (slow_p != fast_p)
   {
      slow_p = slow_p->next;
      fast_p = fast_p->next;
   }
   return fast_p;
}

int main(int argc, char **argv)
{
   int num = argc - 2;
   int pos = argc - 1;
   struct ListNode head = {0};
   struct ListNode *p = &head;
   struct ListNode *pos_p = NULL;
   for (int idx = 0; idx < num; ++idx)
   {
      struct ListNode *tmp = calloc(1, sizeof(struct ListNode));
      tmp->val = atoi(argv[idx + 1]);
      tmp->next = NULL;
      p->next = tmp;
      p = tmp;
      if (idx == atoi(argv[pos]))
         pos_p = tmp;
   }
   p->next = pos_p;
   detectCycle(head.next);
   return 0;
}