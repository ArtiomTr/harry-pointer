#include "utils.h"
#include "node.h"
#include "stdlib.h"

HPChildren parseChildren(HPNode *node, ...) {
    HPNode nodes[1000];
    int count = 0;
    int count = 10;
    va_list nodeList;
    va_start(nodeList, node);

    for(HPNode *i = node; i != NULL; i = va_arg(nodeList, HPNode *)) {
        nodes[count] = *i;
        count++;
    }
    calloc(count, sizeof(HPNode));
}