#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct ListNode *getMid(struct ListNode *head)
{
   struct ListNode *slow = newListNode(0);
   slow->next = head;
   struct ListNode *fast = head;

   while(fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
   }

   return slow;
}

struct ListNode *mergeList(struct ListNode *list1, struct ListNode *list2)
{
   struct ListNode *head = newListNode(0);
   struct ListNode *p = head;
   while (list1 && list2) {
      if (list1->val < list2->val) {
         p->next = list1;
         list1 = list1->next;
      } else {
         p->next = list2;
         list2 = list2->next;
      }

      p = p->next;
   }

   if (list1)
      p->next = list1;
   else
      p->next = list2;

   return head->next;
}

struct ListNode* sortList(struct ListNode* head)
{
   if (head == NULL || head->next == NULL)
      return head;

   struct ListNode *list1 = head;
   struct ListNode *mid = getMid(head);
   struct ListNode *list2 = mid->next;
   mid->next = NULL;

   list1 = sortList(list1);
   list2 = sortList(list2);

   head = mergeList(list1, list2);

   return head;
}

int main(int argc, char **argv)
{
   int vals[argc - 1];
   for (int idx = 0; idx < argc - 1; ++idx)
      vals[idx] = atoi(argv[idx + 1]);

   struct ListNode *head = newList(argc - 1, vals);
   printList(sortList(head));
   return 0;
}