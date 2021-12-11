#include "hpLink.h"

#include <stdlib.h>

HPNode *rawHpLink(HpLinkProps *props, HPChildren children) {
    HPNode *node = malloc(sizeof(HPNode));

    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "rel", props->rel);
    hpSet(&attributes, "href", props->href);
    hpSet(&attributes, "crossorigin", props->crossOrigin);

    *node = (HPNode){
            .name = "link",
            .kind = HP_TAG,
            .children = children,
            .attributes = attributes,
    };

    return node;
}

HPElement hpLink = (HPElement) rawHpLink;
