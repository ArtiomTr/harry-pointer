#include "htmlDiv.h"

#include <stdlib.h>

#include "utils.h"

HPNode *hpHtmlDiv(HtmlDivProps *options, HPChildren children) {
    HPAttributeMap map = hpCreateAttributeMap();

    hpSet(&map, "class", options->class);
    hpSet(&map, "style", options->style);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "div",
            .children = children,
            .kind = HP_TAG,
    };

    return node;
}

HPElement htmlDiv = (HPElement) hpHtmlDiv;
