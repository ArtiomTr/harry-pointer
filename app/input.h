#ifndef HARRY_POINTER_INPUT_H
#define HARRY_POINTER_INPUT_H

#include <stdio.h>

typedef struct {
    char title[31];
    char description[101];
    char image[101];
    double price;
} Product;

typedef struct {
    char title[31];
    char description[101];
    int productCount;
    char image[101];
    Product *products;
} Category;

typedef struct {
    char shopTitle[31];
    char contactPhone[31];
    char contactEmail[31];
    int categoryCount;
    Category *categories;
} ShopInfo;

ShopInfo readUserInput(FILE *file);

#endif
