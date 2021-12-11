#include "hpHeader.h"

#include <stdlib.h>

HPNode *rawHpHeader(HpHeaderProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "header",
            .kind = HP_TAG,
            .attributes = attributes,
            .children = children,
    };

    return node;
}

HPElement hpHeader = (HPElement) rawHpHeader;
