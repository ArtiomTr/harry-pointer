#include "input.h"
#include <stdio.h>


int main() {
    ShopInfo sInfo = readUserInput(stdin);
    printf("%s\n", sInfo.shopTitle);
    printf("%d\n", sInfo.productCount);
    for(int i = 0; i < sInfo.productCount; ++i) {
        printf("%s  ", sInfo.products[i].title);
        printf("%d\n", sInfo.products[i].price);
    }

    return 0;
}