#include "hpImg.h"

#include <stdlib.h>

HPNode *rawHpImg(HpImgProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", props->class);
    hpSet(&attributes, "style", props->style);
    hpSet(&attributes, "src", props->src);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "img",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpImg = (HPElement) rawHpImg;
