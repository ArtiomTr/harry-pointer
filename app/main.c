#include "hp.h"

#include <stdlib.h>

#include "input.h"
#include "pages.h"
#include "utils.h"

void generatePage(char *filePath, HPNode *node) {
    FILE *out = fopen(filePath, "w");

    renderToFile(out, node);

    fclose(out);
}

int main() {
    ShopInfo info = readUserInput(stdin);

    generatePage("index.html", createHPNode(CategoryListPage, info, NULL));

    for(int i = 0; i < info.categoryCount; ++i) {
        char *categoryPagePath = getPageFromSentence(info.categories[i].title);
        generatePage(categoryPagePath,
                     createHPNode(CategoryPage,
                                  ((CategoryPageProps){.shopInfo = info, .category = info.categories[i]}),
                                  NULL));
        free(categoryPagePath);
    }

    return 0;
}