#include "hpDiv.h"

#include <stdlib.h>

#include "utils.h"

HPNode *rawHpDiv(HpDivProps *options, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "class", options->class);
    hpSet(&attributes, "style", options->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "div",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpDiv = (HPElement) rawHpDiv;
