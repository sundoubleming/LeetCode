#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief 创建新的ListNode节点
 * @param  val node节点的val值
 * @return struct TreeNode* 新建的节点指针
 */
struct ListNode *newListNode(int val)
{
   struct ListNode *ret = calloc(1, sizeof(struct ListNode));
   ret->val = val;
   ret->next = NULL;
   return ret;
}

/**
 * @brief 创建新的list
 * @param  argc               同main函数
 * @param  argv               同main函数
 * @return struct ListNode *  链表
 */
struct ListNode *newList(int argc, int *argv)
{
   struct ListNode head = {0};
   struct ListNode *p = &head;
   for (int idx = 0; idx < argc; ++idx)
   {
      p->next = newListNode(argv[idx]);
      p = p->next;
   }

   return head.next;
}

/**
 * @brief 释放list
 * @param  head             list
 */
void freeList(struct ListNode *head)
{
   struct ListNode *p = head;
   struct ListNode *tmp = NULL;
   while(p)
   {
      tmp = p->next;
      free(p);
      p = tmp;
   }

   return;
}

/**
 * @brief 打印list
 * @param  head             list
 */
void printList(struct ListNode *head)
{
   struct ListNode *p = head;
   while(p)
   {
      printf("%d ", p->val);
      p = p->next;
   }
   printf("\n");

   return;
}

/**
 * @brief 找链表list的中间节点
 * @param  head             链表头指针
 * @return struct ListNode* 中间节点指针
 */
struct ListNode *findListMid(struct ListNode *head)
{
   // 快慢指针 用来找中点
   struct ListNode *s = head;
   struct ListNode *f = head;
   while(f->next && f->next->next)
   {
      s = s->next;
      f = f->next->next;
   }

   return s;
}

/**
 * @brief 反转链表
 * @param  head             链表头
 */
struct ListNode *reverseList(struct ListNode *head)
{
   if (head == NULL || head->next == NULL)
      return head;
   struct ListNode *new_head = head;
   struct ListNode *tmp = NULL;
   head = new_head->next;
   new_head->next = NULL;
   while(head)
   {
      tmp = head->next;
      head->next = new_head;
      new_head = head;
      head = tmp;
   }

   return new_head;
}