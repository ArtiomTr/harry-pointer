#ifndef HP_COMPILER_PARSE_FILE_H
#define HP_COMPILER_PARSE_FILE_H

#include <stdio.h>
#include "attributeMap.h"

typedef struct {
    long begin;
    long end;
    char *tagName;
    HPAttributeMap map;
} TagInfo;

void parseFile(FILE *input);

#endif
