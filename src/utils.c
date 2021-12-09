#include "utils.h"
#include "node.h"
#include "stdlib.h"

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
