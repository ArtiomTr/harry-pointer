#include "categoryList.h"

#include <malloc.h>

#include "category.h"

const char categoryListStyles[] = ".category-grid {\n"
                                  "    padding-top: 30px;\n"
                                  "    display: grid;\n"
                                  "    grid-template-columns: auto auto;\n"
                                  "    grid-gap: 10px;\n"
                                  "}\n";

HPNode *CategoryListComponent(CategoryListProps *props, HPChildren *children) {
    HPChildren categoryViews = {
            .count = props->categoryCount,
            .elements = calloc(props->categoryCount, sizeof(HPNode)),
    };

    for(int i = 0; i < props->categoryCount; ++i) {
        categoryViews.elements[i] = *createHPNode(CategoryView, props->categories[i], NULL);
    }

    return createHPNode(hpDiv,
                        ((HpDivProps){}),
                        createHPNode(hpStyle,
                                     ((HpStyleProps){}),
                                     createHPString(categoryListStyles),
                                     createHPString(categoryStyles)),
                        createHPNodeImpl(hpDiv, &((HpDivProps){.class = "category-grid"}), categoryViews));
}

HPElement CategoryList = (HPElement) CategoryListComponent;