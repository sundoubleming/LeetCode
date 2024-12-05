#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void inputOprs(int **oprs, int oprCnt)
{
   for (int idx = 0; idx < oprCnt; ++idx)
   {
      oprs[idx] = malloc(sizeof(int) * 3);
      scanf("%d", &(oprs[idx][0]));
      scanf("%d", &(oprs[idx][1]));
      scanf("%d", &(oprs[idx][2]));
   }
   return;
}

void outputOprs(int **oprs, int oprCnt)
{
   for (int idx = 0; idx < oprCnt; ++idx)
   {
      printf("%d ", oprs[idx][0]);
      printf("%d ", oprs[idx][1]);
      printf("%d\n", oprs[idx][2]);
   }
   return;
}

struct listNode
{
   int key;
   int val;
   struct listNode *pre;
   struct listNode *next;
};

typedef struct listNode listNode;

//删除时直接删除第一个
int delNode(listNode *head)
{
   listNode *node = head->next;
   // 链表中只有一个head节点
   if (node == head)
      return -1;
   head->next = node->next;
   node->next->pre = head;

   int key = node->key;
   free(node);
   return key;
}

listNode *newNode(int key, int val)
{
   listNode *tmp = malloc(sizeof(listNode));
   tmp->key = key;
   tmp->val = val;
   tmp->pre = NULL;
   tmp->next = NULL;
   return tmp;
}

// 新增的时候直接新增在尾
void addNode(listNode *head, listNode *node)
{
   listNode *tail = head->pre;
   node->pre = tail; 
   node->next = head;
   tail->next = node;
   head->pre = node;
   return;
}

// 更新的时候直接把更新的node放在尾
void updateList(listNode *head, listNode *node)
{
   // 先把node中链表里删除
   listNode *pre = node->pre;
   listNode *next = node->next;
   pre->next = next;
   next->pre = pre;

   addNode(head, node);
   return;
}

void setOpr(int key, int val, listNode *hash[], int k, listNode *head, int *size)
{
   // 先检查key是否已经在链表中
   if (hash[key])
   {
      listNode *node = hash[key];
      node->val = val;
      updateList(head, node);
   }
   else
   {
      if (*size >= k)
         hash[delNode(head)] = NULL;
      else
         ++(*size);

      listNode *node = newNode(key, val);
      addNode(head, node);
      hash[key] = node;
   }
   return;
}

void getOpr(int key, listNode *hash[], listNode *head, int *ret, int *idx)
{
   if (hash[key])
   {
      updateList(head, hash[key]);
      ret[*idx] = head->pre->val;
   }
   else
      ret[*idx] = -1;

   ++(*idx);
   return;
}

int* LRU(int** operators, int operatorsRowLen, int* operatorsColLen, int k, int* returnSize)
{
   int *ret = malloc(sizeof(int) * operatorsRowLen);
   memset(ret, 0, sizeof(int) * operatorsRowLen);

   listNode *hash[operatorsRowLen];
   memset(hash, 0, sizeof(listNode *) * operatorsRowLen);

   listNode *head = malloc(sizeof(listNode));
   head->pre = head;
   head->next = head;

   int size = 0;
   *returnSize = 0;
   for (int idx = 0; idx < operatorsRowLen; ++idx)
   {
      if (operators[idx][0] == 1)
         setOpr(operators[idx][1], operators[idx][2], hash, k, head, &size);
      else
         getOpr(operators[idx][1], hash, head, ret, returnSize);
   }
   return ret;
}

int main(int argc, char **argv)
{
   int oprCnt = atoi(argv[1]);
   int **oprs = malloc(sizeof(int *) * oprCnt);
   inputOprs(oprs, oprCnt);
   printf("============output oprs start=================\n");
   outputOprs(oprs, oprCnt);
   printf("=============output oprs end==================\n");

   int retSize = 0;
   int *ret = LRU(oprs, oprCnt, NULL, atoi(argv[2]), &retSize);
   for (int idx = 0; idx < retSize; ++idx)
      printf("%d ", ret[idx]);
   printf("\n");
   return 0;
}