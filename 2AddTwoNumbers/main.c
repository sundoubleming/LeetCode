#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *head)
{
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
    return;
}

struct ListNode *newList(int *vals, int size)
{
    struct ListNode head = {0};
    struct ListNode *p = &head;
    for (int idx = 0; idx < size; ++idx) {
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = vals[idx];
        p = p->next;
    }

    return head.next;
}

#if 0
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode l3 = {0};
    struct ListNode *p = &l3;
    int flag = 0;
    int num = 0;
    while (l1 && l2) {
        p->next = calloc(1, sizeof(struct ListNode));
        p = p->next;
        num = l1->val + l2->val + flag;
        p->val = num % 10;
        flag = num/10;
        l1 = l1->next;
        l2 = l2->next;
    }

    l1 = l1 == NULL ? l2 : l1;
    while (l1) {
        p->next = calloc(1, sizeof(struct ListNode));
        p = p->next;
        num = l1->val + flag;
        p->val = num % 10;
        flag = num / 10;
        l1 = l1->next;
    }

    if (flag) {
        p->next = calloc(1, sizeof(struct ListNode));
        p = p->next;
        p->val = 1;
    }
    return l3.next;
}
#endif

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode *head1 = l1;
    struct ListNode *head2 = l2;
    int flag = 0;
    int num = 0;
    while (l1->next && l2->next) {
        num = l1->val + l2->val + flag;
        l1->val = num % 10;
        flag = num / 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    num = l1->val + l2->val + flag;
    l1->val = num % 10;
    flag = num / 10;
    struct ListNode *l = l1->next ? l1->next : l2->next;
    l1->next = l;
    while (l1->next) {
        num = l1->next->val + flag;
        l1->next->val = num % 10;
        flag = num / 10;
        l1 = l1->next;
    }

    if (flag) {
        l1->next = calloc(1, sizeof(struct ListNode));
        l1->next->val = 1;
    }
    return head1;
}

int main(int argc, char **argv)
{
    int val1[] = {9, 9, 9, 9, 9, 9, 9};
    struct ListNode *l1 = newList(val1, 7);
    int val2[] = {9, 9, 9, 9};
    struct ListNode *l2 = newList(val2, 4);
    printList(l1);
    printList(l2);
    struct ListNode *l3 = addTwoNumbers(l1, l2);
    printList(l3);
    return 0;
}