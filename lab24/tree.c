#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define VARIABLE_LENGTH (8U)

typedef struct {
    Node *left, *right;
    char op;
} Operator;

typedef union {
    Operator op;
    double value;
    char variable[VARIABLE_LENGTH];
} NodeUnion;

typedef enum {
    OPERATOR,
    VALUE,
    VARIABLE
} NodeType;

struct Node {
    Node *parent;
    NodeUnion nodeUnion;
    NodeType nodeType;
};

void treeCreate(Tree * const tree) {
    tree->root = NULL;
    tree->size = 0;
}

double parseNumber(char** str) {
    char* r;
    double res = strtod(*str, &r);
    *str = r;
    return res;
}


