#include "hpH2.h"

#include <stdlib.h>

HPNode *rawHpH2(HpH2Props *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "h2",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpH2 = (HPElement) rawHpH2;
