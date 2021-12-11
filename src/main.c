#include "createHPNode.h"
#include "createHPString.h"
#include "htmlDiv.h"
#include "renderer.h"
#include <stdlib.h>

int main() {
    FILE *out = fopen("index.html", "w");

    renderToFile(out,
                 createHPNode(htmlDiv,
                              ((HtmlDivProps){.class = "hello", .style = "asdf"}),
                              createHPNode(htmlDiv, ((HtmlDivProps){.class = "asdf"}), NULL),
                              createHPNode(htmlDiv, ((HtmlDivProps){}), createHPString("Some string"))));

    fclose(out);

    return 0;
}