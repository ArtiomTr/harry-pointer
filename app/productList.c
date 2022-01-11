#include "productList.h"

#include <malloc.h>

#include "productView.h"

const char productListStyles[] = ".product-list {\n"
                                 "    display: grid;\n"
                                 "    grid-template-columns: 1fr 1fr 1fr;\n"
                                 "    grid-gap: 15px;\n"
                                 "    padding-top: 30px;\n"
                                 "}\n";

HPNode *ProductListComponent(ProductListProps *props, HPChildren children) {
    HPChildren productViews = {
            .elements = calloc(props->productCount, sizeof(HPNode)),
            .count = props->productCount,
    };

    for(int i = 0; i < productViews.count; ++i) {
        productViews.elements[i] = *createHPNode(ProductView, props->products[i], NULL);
    }

    return createHPNode(
            hpDiv,
            ((HpDivProps){}),
            createHPNode(hpStyle, ((HpStyleProps){}), createHPString(productListStyles), createHPString(productStyles)),
            createHPNodeImpl(hpDiv, &((HpDivProps){.class = "product-list"}), productViews));
}

HPElement ProductList = (HPElement) ProductListComponent;