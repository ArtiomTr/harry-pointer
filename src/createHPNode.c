#include "createHPNode.h"

HPNode *createHPNodeImpl(HPElement element, void *props, HPChildren children) {
    return element(props, children);
}
