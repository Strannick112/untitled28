#include <stdio.h>
#include <malloc.h>
#include "tree.h"

//#include
//#define debug
//#ifdef Stas
//#ifndef Stas
//printf("Стас здесь, его подключили\n");
//#endif
//#undef Stas

#define say printf
#define repeat_10 for(int i = 0; i < 10; i++)

int sum(int a, int b);
typedef int (my_func_typedef)(int, int);

int main() {

    my_func_typedef* my_func_ptr = sum;

    system("chcp 65001");
    Tree* tree = Tree(5);

    repeat_10 {
        tree->add_node(tree, i);
    }

    tree->print(tree);

    repeat_10 {
        int* result = tree->get(tree, i);
        if(result != nullptr){
            say("value: %d", *result);
        }
    }

    return 0;
}