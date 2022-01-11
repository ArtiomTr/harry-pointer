#include "hpP.h"

#include <stdlib.h>

HPNode *rawHpP(HpPProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "p",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpP = (HPElement) rawHpP;
