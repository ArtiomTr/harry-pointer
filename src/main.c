#include "node.h"
#include "utils.c"
#include "utils.h"
#include <stdio.h>


HPNode node1 = {.name = "Blabla", .kind = 8};
int main() {
    HPChildren children = parseChildren(&node1);

    return 0;
}