#include "hpTitle.h"

#include <stdlib.h>

HPNode *rawHpTitle(HpTitleProps *options, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "meta",
            .children = children,
            .kind = HP_TAG,
            .attributes = hpCreateAttributeMap(),
    };

    return node;
}

HPElement hpTitle = (HPElement) rawHpTitle;
