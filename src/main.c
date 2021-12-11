#include "hp.h"
#include <stdlib.h>

int main() {
    FILE *out = fopen("index.html", "w");

    renderToFile(out,
                 createHPNode(hpDiv,
                              ((HpDivProps){.class = "hello", .style = "asdf"}),
                              createHPNode(hpDiv, ((HpDivProps){.class = "asdf"}), NULL),
                              createHPNode(hpDiv, ((HpDivProps){}), createHPString("Some string"))));

    fclose(out);

    return 0;
}