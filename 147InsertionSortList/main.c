#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <list.h>

static void insert(struct ListNode *pre, struct ListNode *base)
{
   struct ListNode *tmp1 = pre->next->next;
   struct ListNode *tmp2 = base->next->next;
   struct ListNode *tmp = pre->next;
   pre->next = base->next;
   base->next = tmp;
   pre->next->next = tmp2;
   base->next->next = tmp1;
   return;
}

struct ListNode* insertionSortList(struct ListNode* head)
{
   struct ListNode *pre = newListNode(0);
   struct ListNode *newHead = pre;
   pre->next = head;
   struct ListNode *base = head;
   struct ListNode *tmp = head;

   while (base->next) {
      struct ListNode *cur = base->next;
      while (pre->next) {
         if (pre->next->val > cur->val) {
            insert(pre, base);
         }
         pre = pre->next;
      }
      base = base->next;
   }

   printList(newHead);
}

int main(int argc, char **argv)
{
   int vals[argc - 1];
   for (int idx = 0; idx < argc - 1; ++idx)
      vals[idx] = atoi(argv[idx + 1]);
   struct ListNode *head = newList(argc - 1, vals);

   (void)insertionSortList(head);
   //printList(insertionSortList(head));
   return 0;
}