#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void reorderList(struct ListNode* head)
{
   if (head == NULL)
      return;
   struct ListNode *first = head;
   struct ListNode *mid = findListMid(head);
   struct ListNode *second = mid->next;
   mid->next = NULL;

   printList(first);
   printList(second);

   //reverseList(first);
   second = reverseList(second);
   printList(second);

   while(first && second)
   {
      struct ListNode *tmp = first->next;
      first->next = second;
      second = second->next;
      first->next->next = tmp;
      first = tmp;
   }

   printList(head);
   return;
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      printf("the call pattern is such as: ./main 1 2 3 4 5\n");
      return 1;
   }

   int cnt = argc - 1;
   int *vals = calloc(cnt, sizeof(int));
   for (int idx = 1; idx < argc; ++idx)
      vals[idx - 1] = atoi(argv[idx]);

   struct ListNode *head = newList(cnt, vals);
   //printList(head);

   reorderList(head);
   //printList(head);

   free(vals);
}