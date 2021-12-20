#include "hpA.h"

#include <stdlib.h>

HPNode *rawHpA(HpAProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);
    hpSet(&attributes, "href", props->href);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "a",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpA = (HPElement) rawHpA;
