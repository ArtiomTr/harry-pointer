#include "category.h"

#include "input.h"
#include "utils.h"

char categoryStyles[] = ".category {\n"
                        "    text-decoration: none;\n"
                        "    color: black;\n"
                        "}\n"
                        ".category__image {\n"
                        "    width: 100%;\n"
                        "    height: 200px;\n"
                        "    object-fit: cover;\n"
                        "}\n";

HPNode *CategoryViewComponent(Category *props, HPChildren *children) {
    return createHPNode(hpA,
                        ((HpAProps){.class = "category", .href = getPageFromSentence(props->title)}),
                        createHPNode(hpImg, ((HpImgProps){.class = "category__image", .src = props->image}), NULL),
                        createHPNode(hpH2, ((HpH2Props){}), createHPString(props->title)),
                        createHPNode(hpP, ((HpPProps){}), createHPString(props->description)));
}

HPElement CategoryView = (HPElement) CategoryViewComponent;
