#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "stack.h"
#include "stackbin.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    TreeNode *parent, *left, *right;
    char value;
};

void treeClear(Tree * const tree) {
    TreeNode *node = tree->root;
    TreeNode *root = tree->root;
    while (root->left != NULL || root->right != NULL) {
        if (node->left != NULL)
            node = node->left;
        else if (node->right != NULL)
            node = node->right;
        else {
            if (node->parent->left == node) {
                node = node->parent;
                free(node->left);
                node->left = NULL;
                --tree->size;
            }
            else if (node->parent->right == node) {
                node = node->parent;
                free(node->right);
                node->right = NULL;
                --tree->size;
            }
        }
    }
    free(root);
    tree->root = NULL;
    --tree->size;
}

bool treeContains(const Tree * const tree, const int value) {
    TreeNode *node = tree->root;
    while (node != NULL) {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
        else
            return true;
    }
    return false;
}

void treeCreate(Tree * const tree) {
    tree->root = NULL;
    tree->size = 0;
}

int treeErase(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            break;
    }
    if (node == NULL)
        return EINVAL;

    assert(node->value == value);
    if (node->left != NULL && node->right != NULL) {
        int * const value = &node->value;
        ptr = &node->right;
        node = node->right;
        while (node->left != NULL) {
            ptr = &node->left;
            node = node->left;
        }
        *value = node->value;
    }
    if (node->left != NULL) {
        assert(node->right == NULL);
        *ptr = node->left;
        node->left->parent = node->parent;
    } else if (node->right != NULL) {
        assert(node->left == NULL);
        *ptr = node->right;
        node->right->parent = node->parent;
    } else
        *ptr = NULL;
    free(node);
    --tree->size;
}

int treeInsert(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            return EINVAL;
    }
    *ptr = malloc(sizeof(TreeNode));
    if (*ptr == NULL)
        return errno;
    ++tree->size;
    (*ptr)->parent = node;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    (*ptr)->value = value;
    return 0;
}

bool treeIsEmpty(const Tree * const tree) {
    return tree->size == 0;
}

size_t treeSize(const Tree * const tree) {
    return tree->size;
}

void treeDestroy(Tree * const tree) {
    treeClear(tree);
}

void nodePrint(TreeNode * node, size_t depth) {

    for (size_t i = 0; i < depth; ++i)
        printf(" ");
    printf("%d\n", node->value);
    if (node->left != NULL)
        nodePrint(node->left, depth + 1);
    if (node->right != NULL)
        nodePrint(node->right, depth + 1);

}

void treePrint(Tree * const tree) {
    bool check = treeIsEmpty(tree);
    if (check)
        printf("Tree is empty\n");
    else
        nodePrint(tree->root, 0);

}

bool treeIsSymmetric(TreeNode * left, TreeNode * right){
    //printf("%d %d \n", left->value, right->value);
    if (left == NULL && right == NULL)
        return true;
    else if (left != NULL && right != NULL)
        return treeIsSymmetric(left->left, right->right) && treeIsSymmetric(left->right, right->left);
    else
        return false;
}

bool treeCheckSym(Tree * tree) {
    TreeNode *node = tree->root;
    if (node == NULL)
        return true;
    return treeIsSymmetric(node->left, node->right);
}

void treePreorder(Tree* tree) {
    size_t size = treeSize(tree), i = 0;
    TreeNode* stack[size];
    stack[0] = NULL;
    TreeNode *root = tree->root;
    TreeNode *node;

    if (root == NULL)
        return;

    stack[i] = root;
    while (stack[0] != NULL) {
        node = stack[i];
        stack[i] = NULL;
        --i;
        printf("%d ", node->value);
        if (node->right != NULL){
            ++i;
            stack[i] = node->right;
        }
        if (node->left != NULL) {
            ++i;
            stack[i] = node->left;
        }
    }
    printf("\n");
}

void treeInorder(Tree* tree) {
    TreeNode* node = tree->root;

    TreeNode* last = NULL;
    while (node != NULL) {
        if (last == node->parent) {
            if (node->left != NULL) {
                last = node;
                node = node->left;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->left) {
            printf("%d ", node->value);

            if (node->right != NULL) {
                last = node;
                node = node->right;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->right) {
            last = node;
            node = node->parent;
        }
    }
    printf("\n");
}

void treePostorder(Tree* tree) {
    TreeNode* node = tree->root;

    TreeNode* last = NULL;
    while (node != NULL) {
        if (last == node->parent) {
            if (node->right != NULL) {
                last = node;
                node = node->right;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->right) {
            printf("%d ", node->value);

            if (node->left!= NULL) {
                last = node;
                node = node->left;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->left) {
            last = node;
            node = node->parent;
        }
    }
    printf("\n");
}
