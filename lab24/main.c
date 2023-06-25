#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "stack.h"
#include "stackbin.h"

#define MAX_SIZE 100

void exptostack(Stack *stack, char *expression) {
	int i = 0;
	char c = expression[i];
	while(c != '\0') {
		stackPush(stack, c);
		c = expression[++i];
	}
}

int main() {
	char expression[MAX_SIZE];
	Stack stack, res;
	StackBin s;
	Tree tree;
	treeCreate(&tree);
	stackBinCreate(&s);
	stackCreate(&stack);
	stackCreate(&res);

	printf("enter expression\n");
	scanf("%s", expression);
	//printf("%s\n", expression);
	toPostfix(&stack, expression);
	exptostack(&res, expression);
	treeFromPostfix(&tree, &res, &s);
	treePrint(&tree);
	printf("\n");
	treeF(&tree);
	treePrint(&tree);
	printf("\n");
	printf("count = %d\n", treeCount(&tree));


	treeDestroy(&tree);
	stackDestroy(&stack);
	stackDestroy(&res);
	stackBinDestroy(&s);

    return 0;
}