#include "createHPNode.h"
#include "htmlDiv.h"
#include "renderer.h"
#include <stdlib.h>

int main() {
    FILE *out = fopen("index.html", "w");

    renderToFile(out,
                 createHPNode(htmlDiv,
                              ((HtmlDivProps){.class = "hello", .style = "asdf"}),
                              createHPNode(htmlDiv, ((HtmlDivProps){.class = "asdf"}), NULL),
                              createHPNode(htmlDiv, ((HtmlDivProps){}), NULL)));

    fclose(out);

    return 0;
}