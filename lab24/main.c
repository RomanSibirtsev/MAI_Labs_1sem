#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "stack.h"
#include "stackbin.h"

int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}

int checkIfOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void fromPostfix(Tree *tree, Stack *postfix, StackBin *stack) {
	char ch;
	while (!stackIsEmpty(stack)) {
		Pair pair;
		pair = stackBinPop(stack);
		TreeNode *parent = pair->TreeNode;
		bool isleft = pair->v;

		TreeNode *node = malloc(sizeof(TreeNode));
		node->parent = parent;
		node->value = stackPop(postfix);

		if (parent == NULL) {
			root = node;
		} else if (isleft) {
			parent->left = node;
		} else {
			parent->right = node;
		}
		if (!checkIfOperand(node->value)) {
			stackBinPush(stack, node, 1);
			if (precedence(node->value) >= 2) {
				stackBinPush(stack, node, 0);
			}
		}
	}
}

int main() {
	Stack stack, res
	StackBin s;
	Tree tree;
	treeCreate(&tree);
	stackBinCreate(&s);
	stackCreate(&stack);
	stackCreate(&res);

	stackBinPush(&s, NULL, 0);
	
	char expression[] = "((a+(b*c))-d)";
  	toPostfix(&stack, expression);

	printf("%s\n", expression);
	int i = 0;
	char c = expression[i];
	while(c != '\0') {
		stackPush(&res, c);
		c = expression[++i];
	}
	fromPostfix(&tree, &res, &s);
	//stackPrint(&res);
	stackDestroy(&stack);
	stackDestroy(&res);


    return 0;
}