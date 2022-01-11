#include "productView.h"

#include "input.h"

#include <malloc.h>

const char productStyles[] = ".product {\n"
                             "\n"
                             "}\n"
                             ".product__image {\n"
                             "    width: 100%;\n"
                             "    height: 200px;\n"
                             "    object-fit: contain;\n"
                             "}\n"
                             ".product__price {\n"
                             "    color: #595959;\n"
                             "    font-weight: bold;\n"
                             "}\n";

HPNode *ProductViewComponent(Product *props, HPChildren children) {
    char *priceStr = calloc(32, sizeof(char));

    sprintf(priceStr, "%.2lf &euro;", props->price);

    return createHPNode(hpDiv,
                        (HpDivProps){.class = "product"},
                        createHPNode(hpImg, ((HpImgProps){.class = "product__image", .src = props->image}), NULL),
                        createHPNode(hpH2, ((HpH2Props){}), createHPString(props->title)),
                        createHPNode(hpP, ((HpPProps){}), createHPString(props->description)),
                        createHPNode(hpSpan, ((HpSpanProps){.class = "product__price"}), createHPString(priceStr)));
}

HPElement ProductView = (HPElement) ProductViewComponent;
