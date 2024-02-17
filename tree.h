//
// Created by Stanislav on 17.02.2024.
//

#ifndef UNTITLED28_TREE_H
#define UNTITLED28_TREE_H

#define Tree(stas) tree_init(stas)
typedef struct Tree{
    int value;
    int count;
    struct Tree* left;
    struct Tree* right;

    void (*add_node)(struct Tree* tree, int value);
    void (*print)(struct Tree* tree);
    int* (*get)(struct Tree* tree, int value);
    void (*clear)(struct Tree* tree);
} Tree;

struct Tree* tree_init(int value);
#endif //UNTITLED28_TREE_H
