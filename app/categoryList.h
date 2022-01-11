#ifndef SHOP_CATEGORY_LIST_H
#define SHOP_CATEGORY_LIST_H

#include "hp.h"
#include "input.h"

typedef struct {
    int categoryCount;
    Category *categories;
} CategoryListProps;

extern HPElement CategoryList;

#endif