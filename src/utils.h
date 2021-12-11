#ifndef HARRY_POINTER_UTILS_H
#define HARRY_POINTER_UTILS_H

#include <stdarg.h>
#include <stdio.h>

#include "attributeMap.h"
#include "node.h"

// Function which accumulates given nodes into single HPChildren structure
HPChildren parseChildren(HPNode *node, ...);

void fwriteAttributeMap(FILE *output, HPAttributeMap map);

#endif
