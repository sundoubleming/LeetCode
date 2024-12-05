#include <stdio.h>
#include "tree.h"
#include <string.h>
#include <stdlib.h>

struct TreeNode* connect(struct TreeNode* root)
{
	if (root == NULL)
        return NULL;
    int layer = 0;
    root->next = NULL;
    struct TreeNode *start = root;
    
    while (start) {
        struct TreeNode *cur = start;
        start = cur->left;
        if (start == NULL)
            continue;

        while (cur) {
            cur->left->next = cur->right;
            if (cur->next)
               cur->right->next = cur->next->left;
            cur = cur->next;
        }
    }
    return root;
}

int main(int argc, char **argv)
{
   struct TreeNode *root = buildTree(argc, argv);
   root = connect(root);
   return 0;
}