#include "hp.h"

#include <stdlib.h>

#include "app.h"
#include "input.h"

int main() {
    ShopInfo info = readUserInput(stdin);
    FILE *out = fopen("index.html", "w");

    renderToFile(out,
                 createHPNode(App,
                              ((AppProps){
                                      .shopTitle = info.shopTitle,
                                      .productCount = info.productCount,
                                      .products = info.products,
                              }),
                              NULL));

    fclose(out);

    return 0;
}