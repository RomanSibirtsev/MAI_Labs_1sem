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
bool treeContains(const Tree *tree, int value);
void treeCreate(Tree *tree);
int treeErase(Tree * const tree, int value);
int treeInsert(Tree * const tree, int value);
int treeGet(const Tree *tree, size_t index, int *value);
int treeSet(Tree *tree, size_t index, int value);
size_t treeSize(const Tree *tree);
void treeDestroy(Tree *tree);
void treePrint(Tree *tree);
bool treeCheckSym(Tree * tree);
bool treeIsSymmetric(TreeNode * left, TreeNode * right);
void treePreorder(Tree *tree);
void treeInorder(Tree *tree);
void treePostorder(Tree *tree);

#endif //TREE_H
