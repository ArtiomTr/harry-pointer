#ifndef HP_COMPILER_PARSE_FILE_H
#define HP_COMPILER_PARSE_FILE_H

#include <stdio.h>

#include "attributeMap.h"
#include "dynamicArray.h"

typedef struct {
    long beginLine;
    long beginColumn;
    long endLine;
    long endColumn;
    char *tagName;

    HPAttributeMap map;
    DynamicArray children;
} TagInfo;

void parseFile(FILE *input);

#endif
