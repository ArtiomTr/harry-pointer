#ifndef HARRY_POINTER_HTML_DIV_H
#define HARRY_POINTER_HTML_DIV_H

#include "node.h"

typedef struct {
    char *class;
    char *style;
} HtmlDivProps;

extern HPElement htmlDiv;

#endif
