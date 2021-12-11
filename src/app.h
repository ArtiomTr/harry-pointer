#ifndef SHOP_APP_H
#define SHOP_APP_H

#include "hp.h"
#include "input.h"

typedef struct {
    char *shopTitle;
    int productCount;
    Product *products;
} AppProps;

extern HPElement App;

#endif
