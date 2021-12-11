#include "renderer.h"

#include "utils.h"

int renderSingleNode(FILE *output, HPNode *node) {
    if(node->kind == HP_TAG) {
        fprintf(output, "<%s ", node->name);
        fwriteAttributeMap(output, node->attributes);
        fprintf(output, ">\n");

        for(int i = 0; i < node->children.count; ++i) {
            renderSingleNode(output, &(node->children.elements[i]));
        }

        fprintf(output, "</%s>\n", node->name);
    } else {
        fprintf(output, "%s\n", hpGetValue(&(node->attributes), "value"));
    }

    return 0;
}

int renderToFile(FILE *output, HPNode *node) {
    fprintf(output, "<!DOCTYPE html>\n");

    return renderSingleNode(output, node);
}