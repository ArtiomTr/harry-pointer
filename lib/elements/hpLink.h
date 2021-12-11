#ifndef HARRY_POINTER_ELEMENT_LINK_H
#define HARRY_POINTER_ELEMENT_LINK_H

#include "../node.h"

typedef struct {
    char *rel;
    char *href;
    char *crossOrigin;
} HpLinkProps;

extern HPElement hpLink;

#endif
