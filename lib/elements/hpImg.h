#ifndef HARRY_POINTER_ELEMENT_IMG_H
#define HARRY_POINTER_ELEMENT_IMG_H

#include "../node.h"

typedef struct {
    char *class;
    char *style;
    char *src;
} HpImgProps;

extern HPElement hpImg;

#endif
