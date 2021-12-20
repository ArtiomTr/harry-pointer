#ifndef HARRY_POINTER_INPUT_H
#define HARRY_POINTER_INPUT_H

#include <stdio.h>

typedef struct {
    char *title;
    int price;
} Product;

typedef struct {
    char *shopTitle;
    int productCount;
    Product *products;
} ShopInfo;

ShopInfo readUserInput(FILE *file);

#endif
