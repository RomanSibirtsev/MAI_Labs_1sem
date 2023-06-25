#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stackbin.h"
#include "stack.h"
#include "tree.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    TreeNode *parent, *left, *right;
    char value;
};

void treeCreate(Tree *tree) {
    tree->root= NULL;
    tree->size = 0;
}

size_t treeSize(Tree *tree) {
    return tree->size;
}

void treeFromPostfix(Tree *tree, Stack *postfix, StackBin *stack) {
    char ch;
    TreeNode **root = &tree->root;
    stackBinPush(stack, *root, 0);
    Pair pair;
    TreeNode *node = NULL;
    TreeNode *parent = NULL;

	while (!stackBinIsEmpty(stack)) {
		pair = stackBinPop(stack);
		parent = pair.node;
		bool isleft = pair.v;
        node = malloc(sizeof(TreeNode));
		node->parent = parent;
		node->value = stackPop(postfix);
        node->left = NULL;
        node->right = NULL;

		if (parent == NULL) {
			*root = node;
		} else if (isleft) {
			parent->left = node;
            tree->size++;
		} else {
			parent->right = node;
            tree->size++;
		}
		if (precedence(node->value) != -1) {
			stackBinPush(stack, node, 1);
			stackBinPush(stack, node, 0);
		}
	}
}

void nodePrint(TreeNode * node, size_t depth) {

    for (size_t i = 0; i < depth; ++i)
        printf(" ");
    printf("%c\n", node->value);
    if (node->left != NULL)
        nodePrint(node->left, depth + 1);
    if (node->right != NULL)
        nodePrint(node->right, depth + 1);

}

void treePrint(Tree * const tree) {
    bool check = treeSize(tree);
    if (!check)
        printf("Tree is empty\n");
    else
        nodePrint(tree->root, 0);

}

void nodeFunc(TreeNode * node) {
    TreeNode *copy = node;
    if (node->value == '/') {
        if (node->right->value == '1') {
            if (node->parent->left == node) {
                node->left->parent = node->parent;
                node->parent->left = node->left;
                copy = node->parent;
                free(node->right);
                free(node);
            } else {
                node->left->parent = node->parent;
                node->parent->right = node->left;
                copy = node->parent;
                free(node->right);
                free(node);
            }
        }
    }
    if (copy != NULL) {
        if (copy->left != NULL)
            nodeFunc(copy->left);
        if (copy->right != NULL)
            nodeFunc(copy->right);
    }

}

bool treeF(Tree *tree) {
    nodeFunc(tree->root);
}

void treeDestroy(Tree *tree)  {
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

int nodeCount(TreeNode *node) {
    if (checkIfOperand(node->value)) {
        return node->value - '0';
    }
    if (node->value == '/') {
        return nodeCount(node->left) / nodeCount(node->right);
    }
    if (node->value == '*') {
        return nodeCount(node->left) * nodeCount(node->right);
    }
    if (node->value == '+') {
        return nodeCount(node->left) + nodeCount(node->right);
    }
    if (node->value == '-') {
        return nodeCount(node->left) - nodeCount(node->right);
    }
}

int treeCount(Tree *tree) {
    return nodeCount(tree->root);
}