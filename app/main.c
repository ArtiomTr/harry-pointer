#include "hp.h"

#include <stdlib.h>

#include "app.h"

int main() {
    ShopInfo info = readUserInput(stdin);

    FILE *out = fopen("index.html", "w");

    renderToFile(out, createHPNode(App, info, NULL));

    fclose(out);

    return 0;
}