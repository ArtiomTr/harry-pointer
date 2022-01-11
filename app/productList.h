#ifndef SHOP_PRODUCT_LIST_H
#define SHOP_PRODUCT_LIST_H

#include "hp.h"
#include "input.h"

typedef struct {
    Product *products;
    int productCount;
} ProductListProps;

extern HPElement ProductList;

#endif
