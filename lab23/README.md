# Отчет по лабораторной работе №1 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «31» мая 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Отчет сдан___ «1» июня 2023 г., ___итоговая оценка___ 
Подпись преподавателя: ________________ 

## 1. Тема

Динамические структуры данных. Обработка деревьев

## 2. Цель работы

Научиться работать с деревьями

## 3. Задание

Составить программу на языке СИ для построения и обработки упорядоченного двоичного дерева, содержащего узлы типа float. Основные функции работы с деревьями реализовать в виде универсальных процедур или функций. После того, как дерево создано, его обработка должна производиться в режиме текстового меню со следующими действиями.

- добавление нового узла

- текстовая визуализация дерева

- удаление узла 

- вычисление значения некоторой функции от дерева

## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения
Двоичное дерево поиска было реализовано с помощью динамических структур. Каждая вершина представляла собой структуру, содержащую значение узла и указатели на родителя, левого и правого детей

## 7. Сценарий выполнения работы

main.c
```c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {

    Tree tree;

    while (1) {
        printf(
                "0 - create tree\n"
                "1 - add node\n"
                "2 - print tree\n"
                "3 - delete node\n"
                "4 - check symmetric\n"
                "5 - preorder\n"
                "6 - inorder\n"
                "7 - postorder\n"
                "8 - treeClear\n"
                "9 - end program\n"
               );

        int key;
        scanf("%d", &key);

        if (key == 0)
            treeCreate(&tree);
        else if (key == 1) {
            printf("enter value\n");
            int val;
            scanf("%d", &val);
            treeInsert(&tree, val);
        }
        else if (key == 2)
            treePrint(&tree);
        else if (key == 3) {
            printf("enter value\n");
            int val2;
            scanf("%d", &val2);
            treeErase(&tree, val2);
        }
        else if (key == 4)
            printf("%d\n", treeCheckSym(&tree));
        else if (key == 9) {
            treeClear(&tree);
            break;
        }
        else if (key == 5)
            treePreorder(&tree);
        else if (key == 6)
            treeInorder(&tree);
        else if (key == 7)
            treePostorder(&tree);
         else if (key == 8)
            treeClear(&tree);
    }

    return 0;
}
```
tree.h
```c
#ifndef TREE_H
#define TREE_H


#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

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

void treePrint();

bool treeCheckSym(Tree * tree);

bool treeIsSymmetric(TreeNode * left, TreeNode * right);

void treePreorder(Tree *tree);

void treeInorder(Tree *tree);

void treePostorder(Tree *tree);

#endif //TREE_H
```
tree.c
```c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    TreeNode *parent, *left, *right;
    int value;
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
```
## 8. Распечатка протокола
```bash
    0 - create tree
    1 - add node
    2 - print tree
    3 - delete node
    4 - check symmetric
    5 - preorder
    6 - inorder
    7 - postorder
    8 - treeClear
    9 - end program
    0
    1
    enter value
    6
    1
    enter value
    5
    1
    enter value
    7
    2
    6
     5
     7
    4
    1
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата     | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ |----------| ------ | ------ | ------ | ------ |
| 1 | дом. | 31.05.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева

Подпись студента _________________