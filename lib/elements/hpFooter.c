#include "hpFooter.h"

#include <stdlib.h>

HPNode *rawHpFooter(HpFooterProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "footer",
            .kind = HP_TAG,
            .attributes = attributes,
            .children = children,
    };

    return node;
}

HPElement hpFooter = (HPElement) rawHpFooter;
