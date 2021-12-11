#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

HPChildren parseChildren(HPNode *node, ...) {
    HPNode nodes[1000];
    int count = 0;
    va_list nodeList;
    va_start(nodeList, node);

    for(HPNode *i = node; i != NULL; i = va_arg(nodeList, HPNode *)) {
        nodes[count] = *i;
        count++;
    }
    HPNode *nodesArray = calloc(count, sizeof(HPNode));
    for(int i = 0; i < count; i++) {
        nodesArray[i] = nodes[i];
    }
    HPChildren children = {.count = count, .elements = nodesArray};
    return children;
}

void fwriteAttributeMap(FILE *output, HPAttributeMap map) {
    for(int i = 0; i < map.size; ++i) {
        // TODO: value should be escaped to prevent errors.
        fprintf(output, "%s=\"%s\"", map.keys[i], map.values[i]);

        if(i != map.size - 1) {
            fprintf(output, " ");
        }
    }
}
