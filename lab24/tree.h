#ifndef TREE_H
#define TREE_H


#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>


#include "stackbin.h"
#include "stack.h"

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

void treeClear(Tree *tree);
void treeCreate(Tree *tree);
void treeDestroy(Tree *tree);
void treePrint(Tree *tree);
void treeFromPostfix(Tree *tree, Stack *postfix, StackBin *stack);
void treeDelOnes(Tree *tree);
bool treeF(Tree *tree);
#endif //TREE_H
