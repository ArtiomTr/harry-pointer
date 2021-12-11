#include "createHPNode.h"
#include "htmlDiv.h"
#include <stdlib.h>

int main() {
    createHPNode(htmlDiv, ((HtmlDivProps){.class = "hello", .style = "asdf"}), NULL);


    return 0;
}