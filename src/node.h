#ifndef HARRY_POINTER_NODE_H
#define HARRY_POINTER_NODE_H

// Kind of node describes how it should be rendered.
typedef enum {
    // Node should be rendered as tag, e.g. div -> <div></div>
    HP_TAG,
    // Node should be rendered as string
    HP_STRING_LITERAL,
} HPNodeKind;

struct HPNode;

// This structure holds array of HPNode.
typedef struct {
    // Size of "elements" array.
    int count;
    struct HPNode *elements;
} HPChildren;

// This structure holds information about node.
typedef struct HPNode {
    // Node identifier. Used for rendering.
    char *name;
    // Describes how node should be rendered.
    HPNodeKind kind;
    // The children of node.
    HPChildren children;
} HPNode;

// The element is function, that takes properties and returns HPNode*
typedef HPNode *(*HPElement)(void *props, ...);

HPNode *createHPNodeImpl(HPElement element, void *props, ...);

#define createHPNode(element, propType, props, children...)                                                            \
    createHPNodeImpl(element, &((propType) props), children, NULL)

#endif
