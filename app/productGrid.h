#ifndef SHOP_PRODUCT_GRID_H
#define SHOP_PRODUCT_GRID_H

#include "hp.h"
#include "input.h"

typedef struct {
    int productCount;
    Product *products;
} ProductGridProps;

extern HPElement ProductGrid;

#endif
