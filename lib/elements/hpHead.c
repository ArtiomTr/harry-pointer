#include "hpHead.h"

#include <stdlib.h>

HPNode *rawHpHead(HpHeadProps *props, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "head",
            .children = children,
            .kind = HP_TAG,
            .attributes = hpCreateAttributeMap(),
    };

    return node;
}

HPElement hpHead = (HPElement) rawHpHead;
