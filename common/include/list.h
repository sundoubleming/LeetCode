#ifndef LIST_H
#define LIST_H

struct ListNode {
   int val;
   struct ListNode *next;
};

/**
 * @brief 创建新的ListNode节点
 * @param  val node节点的val值
 * @return struct TreeNode* 新建的节点指针
 */
struct ListNode *newListNode(int val);

/**
 * @brief 创建新的list
 * @param  argc               同main函数
 * @param  argv               同main函数
 * @return struct ListNode *  链表
 */
struct ListNode *newList(int argc, int *argv);

/**
 * @brief 释放list
 * @param  head             list
 */
void freeList(struct ListNode *head);

/**
 * @brief 打印list
 * @param  head             list
 */
void printList(struct ListNode *head);

/**
 * @brief 找链表list的中间节点
 * @param  head             链表头指针
 * @return struct ListNode* 中间节点指针
 */
struct ListNode *findListMid(struct ListNode *head);

/**
 * @brief 反转链表
 * @param  head             链表头
 */
struct ListNode *reverseList(struct ListNode *head);
#endif