#include "hpHtml.h"

#include <stdlib.h>

HPNode *rawHpHtml(HpHtmlProps *props, HPChildren children) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "lang", props->lang);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "html",
            .children = children,
            .kind = HP_TAG,
            .attributes = attributes,
    };

    return node;
}

HPElement hpHtml = (HPElement) rawHpHtml;