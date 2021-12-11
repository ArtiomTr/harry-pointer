#include "productItem.h"

#include <stdlib.h>

HPNode *ProductItemComponent(ProductItemProps *props, HPChildren children) {
    char *stringWithPrice = calloc(sizeof(char), 100);

    sprintf(stringWithPrice, "Price: %d $", props->item.price);

    return createHPNode(
            hpDiv,
            ((HpDivProps){.class = "product"}),
            createHPNode(hpDiv, ((HpDivProps){.class = "product__title"}), createHPString(props->item.title)),
            createHPNode(hpDiv, ((HpDivProps){.class = "product__info"}), createHPString(stringWithPrice)));
}

HPElement ProductItem = (HPElement) ProductItemComponent;
