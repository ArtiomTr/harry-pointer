#ifndef HARRY_POINTER_RENDERER_H
#define HARRY_POINTER_RENDERER_H

#include "node.h"

#include <stdio.h>

// Function, which renders HPNode and writes output to the specified file.
// Returns status code, 0 if everything ok and error code otherwise.
int renderToFile(FILE *output, HPNode *node);

#endif
