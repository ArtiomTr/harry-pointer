#ifndef HARRY_POINTER_UTILS_H
#define HARRY_POINTER_UTILS_H

#include <stdarg.h>

#include "node.h"

// Function, which takes va_list as first argument and reads all following HPNode* elements till finds NULL.
HPChildren parseChildren(va_list list);

#endif
