#ifndef HARRY_POINTER_CREATE_HP_NODE_H
#define HARRY_POINTER_CREATE_HP_NODE_H

#include "node.h"
#include "utils.h"

HPNode *createHPNodeImpl(HPElement element, void *props, HPChildren);

#define createHPNode(element, props, children...) createHPNodeImpl(element, &(props), parseChildren(children, NULL))

#endif
