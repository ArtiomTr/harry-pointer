#include "hpBody.h"

#include <stdlib.h>

HPNode *rawHpBody(HpBodyProps *options, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "body",
            .children = children,
            .kind = HP_TAG,
            .attributes = hpCreateAttributeMap(),
    };

    return node;
}

HPElement hpBody = (HPElement) rawHpBody;
