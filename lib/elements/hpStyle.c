#include "hpStyle.h"

#include <stdlib.h>

HPNode *rawHpStyle(HpStyleProps *props, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "style",
            .kind = HP_TAG,
            .children = children,
            .attributes = hpCreateAttributeMap(),
    };

    return node;
}

HPElement hpStyle = (HPElement) rawHpStyle;
