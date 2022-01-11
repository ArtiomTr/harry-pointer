#include "hpSpan.h"

#include <stdlib.h>

HPNode *rawHpSpan(HpSpanProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "span",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpSpan = (HPElement) rawHpSpan;
