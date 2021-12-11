#include "createHPString.h"

#include <stdlib.h>

HPNode *createHPString(const char *value) {
    HPAttributeMap attributes = hpCreateAttributeMap();

    hpSet(&attributes, "value", (char *) value);

    HPNode *node = malloc(sizeof(HPNode));

    *node = (HPNode){
            .name = "(StringLiteral)",
            .attributes = attributes,
            .children =
                    {
                            .elements = NULL,
                            .count = 0,
                    },
            .kind = HP_STRING_LITERAL,
    };

    return node;
}
