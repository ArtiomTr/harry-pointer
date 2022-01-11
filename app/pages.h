#ifndef SHOP_PAGES_H
#define SHOP_PAGES_H

#include "hp.h"
#include "input.h"

extern HPElement CategoryListPage;

typedef struct {
    ShopInfo shopInfo;
    Category category;
} CategoryPageProps;

extern HPElement CategoryPage;

#endif
