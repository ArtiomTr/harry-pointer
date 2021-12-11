#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void stringifyAttributeMap(char *input, HPAttributeMap map) {
    for(int i = 0; i < map.size; ++i) {
        strcat(input, map.keys[i]);
        strcat(input, "=\"");
        // TODO: value should be escaped to prevent errors.
        strcat(input, map.values[i]);
        strcat(input, "\"");

        if(i != map.size - 1) {
            strcat(input, " ");
        }
    }
}
