#include "renderer.h"

#include "utils.h"

int renderToFile(FILE *output, HPNode *node) {
    if(node->kind == HP_TAG) {
        fprintf(output, "<%s ", node->name);
        fwriteAttributeMap(output, node->attributes);
        fprintf(output, ">\n");

        for(int i = 0; i < node->children.count; ++i) {
            renderToFile(output, &(node->children.elements[i]));
        }

        fprintf(output, "</%s>\n", node->name);
    } else {
        // TODO: implement this
    }

    return 0;
}