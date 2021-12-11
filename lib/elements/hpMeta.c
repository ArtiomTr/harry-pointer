#include "hpMeta.h"

#include <stdlib.h>

HPNode *rawHpMeta(HpMetaProps *props, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "charset", props->charset);

    *node = (HPNode){
            .name = "meta",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpMeta = (HPElement) rawHpMeta;
