#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode *newList()
{
   int tmp = 0;
   int idx = 0;
   int len = 0;
   scanf("%d", &len);
   struct ListNode ret;
   struct ListNode *p = &ret;
   printf("please input the list, and split with space:\n");
   while (idx < len) {
      p->next = calloc(1, sizeof(struct ListNode));
      p = p->next;
      scanf("%d", &tmp);
      p->val = tmp;
      ++idx;
   }
   return ret.next;
}

int cmp(struct ListNode *a, struct ListNode *b)
{
   if (a->val < b->val) {
      return 1;
   } else {
      return 0;
   }
}

void swap(struct ListNode **a, struct ListNode **b)
{
   struct ListNode *tmp = *b;
   *b = *a;
   *a = tmp;
}

void inputHeap(struct ListNode **lists, int idx)
{
   int father_idx = (idx - 1) / 2;
   while (father_idx >= 0) {
      if (cmp(lists[idx], lists[father_idx])) {
         swap(&(lists[idx]), &(lists[father_idx]));
         father_idx = (father_idx - 1) / 2;
      } else {
         break;
      }
   }
   return;
}

void build(struct ListNode **lists, int listLen)
{
   for (int idx = 1; idx < listLen; ++idx) {
      inputHeap(lists, idx);
   }
   return;
}

int can_update(struct ListNode **lists, int listLen, int idx)
{
   int left = idx * 2 + 1;
   int right = idx * 2 + 2;
   int ret = -1;
   if (left > listLen)
      return -1;
   if (right <= listLen && cmp(lists[right], lists[left])) {
      ret = right;
   } else {
      ret = left;
   }

   if (cmp(lists[ret], lists[idx])) {
      return ret;
   } else {
      return -1;
   }
}

void update(struct ListNode **lists, int listLen)
{
   int idx = 0;
   //int left = idx * 2 + 1;
   //int right = idx * 2 + 2;
   int next = can_update(lists, listLen, idx);
   while (next != -1) {
      swap(&(lists[idx]), &(lists[next]));
      idx = next;
      next = can_update(lists, listLen, idx);
   }

   return;
}

struct ListNode *handler(struct ListNode **lists, int listLen)
{
   build(lists, listLen);
   struct ListNode head = {0};
   struct ListNode *p = &head;
   int len = listLen - 1;
   while (lists[0]) {
      p ->next = lists[0];
      p = p->next;
      lists[0] = lists[0]->next;
      if (lists[0] == NULL)
         swap(&(lists[0]), &(lists[len--]));
      update(lists, len);
   }
   return head.next;
}

int main(int argc, char **argv)
{
   int listsLen = 0;
   printf("please input list length:\n");
   scanf("%d", &listsLen);
   struct ListNode **lists = calloc(listsLen, sizeof(struct ListNode*));
   for (int idx = 0; idx < listsLen; ++idx) {
      printf("please input the %d list:\n", idx);
      struct ListNode *list = newList();
      lists[idx] = list;
   }

   struct ListNode *list = handler(lists, listsLen);
   while (list) {
      printf("%d ", list->val);
      list = list->next;
   }

   return 0;
}