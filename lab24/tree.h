#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct Node Node;

typedef struct {
    Node *root;
    size_t size;
} Tree;

bool treeContains(const Tree *tree, int value);

bool treeIsEmpty(const Tree * tree);

void treeCreate(Tree *tree);

int treeErase(Tree * const tree, int value);

int treeInsertValue(Tree * const tree, int value);

int treeInsertOperator(Tree * const tree, int value);

int treeInsertVariable(Tree * const tree, int value);

int treeGet(const Tree *tree, size_t index, int *value);

int treeSet(Tree *tree, size_t index, int value);

size_t treeSize(const Tree *tree);

void treeDestroy(Tree *tree);

void treePrint(Tree *tree);

double parseNumber(char** str);

#endif //TREE_H