//
// Created by Stanislav on 17.02.2024.
//

// Добавить ячейку в дерево
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include "tree.h"

void tree_add_node(struct Tree* tree, int value);
void tree_print(struct Tree* tree);
int* tree_get(struct Tree* tree, int value);
void tree_clear(struct Tree* tree);

// Создать ячейку дерева
struct Tree* tree_init(int value){
    struct Tree* result = malloc(sizeof(struct Tree));
    result->value = value;
    result->count = 1;
    result->left = nullptr;
    result->right = nullptr;
    result->add_node = tree_add_node;
    result->print = tree_print;
    result->get = tree_get;
    result->clear = tree_clear;
#ifdef debug
    printf("Дерево успешно создалось\n");
#endif
    return result;
}

// Добавить ячейку в дерево
void tree_add_node(struct Tree* tree, int value){
    if(tree->value == value){
        tree->count++;
#ifdef debug
        printf("Элемент добавился в существующую ячейку дерева\n");
#endif
        return;
    }
    if(tree->value < value){
        if(tree->left == nullptr){
            tree->left = tree_init(value);
        }
#ifdef debug
        printf("Элемент добавился слева дерева\n");
#endif
        tree_add_node(tree->left, value);
    }
    if(tree->value > value){
        if(tree->right == nullptr){
            tree->right = tree_init(value);
        }
#ifdef debug
        printf("Элемент добавился справа дерева\n");
#endif
        tree_add_node(tree->right, value);
    }
}

void tree_print(struct Tree* tree){
    if (tree == nullptr)
        return;
    tree_print(tree->left);
    printf("%d\t", tree->value);
    tree_print(tree->right);
}

int* tree_get(struct Tree* tree, int value){
    if(tree == nullptr) {
        printf("Элемент не найден\n");
        return nullptr;
    }
    if(tree->value == value) {
        if(tree->count == 0){
            printf("Элемент не найден\n");
            return nullptr;
        }
        tree->count--;
        return &(tree->value);
    }
    if(tree->value < value){
        return tree_get(tree->left, value);
    }
    if(tree->value > value){
        return tree_get(tree->right, value);
    }
}

void tree_clear(struct Tree* tree){
    if(tree == nullptr)
        return;
    tree_clear(tree->left);
    tree_clear(tree->right);
    free(tree);
}