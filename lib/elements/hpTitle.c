#include "hpTitle.h"

#include <stdlib.h>

HPNode *rawHpTitle(HpTitleProps *props, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "title",
            .children = children,
            .kind = HP_TAG,
            .attributes = hpCreateAttributeMap(),
    };

    return node;
}

HPElement hpTitle = (HPElement) rawHpTitle;
