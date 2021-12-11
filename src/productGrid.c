#include "productGrid.h"

#include <stdlib.h>

#include "productItem.h"

HPNode *ProductGridComponent(ProductGridProps *props, HPChildren children) {
    HPNode *node = createHPNode(hpDiv, ((HpDivProps){.class = "product-grid"}), NULL);

    HPChildren products = {
            .count = props->productCount,
            .elements = calloc(sizeof(HPNode), props->productCount),
    };

    for(int i = 0; i < props->productCount; ++i) {
        products.elements[i] = *(createHPNode(ProductItem, ((ProductItemProps){.item = props->products[i]}), NULL));
    }

    node->children = products;

    return node;
}

HPElement ProductGrid = (HPElement) ProductGridComponent;
