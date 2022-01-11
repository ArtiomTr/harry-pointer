#include "header.h"

HPNode *AppHeaderComponent(AppHeadProps *props, HPChildren children) {
    return createHPNode(
            hpHeader,
            ((HpHeaderProps){.class = "header centralizer"}),
            createHPNode(hpA,
                         ((HpAProps){.href = "index.html", .class = "header__container centralizer__container"}),
                         createHPNode(hpDiv, ((HpDivProps){.class = "logo"}), NULL),
                         createHPNode(hpDiv, ((HpDivProps){}), createHPString(props->shopTitle))));
}

HPElement AppHeader = (HPElement) AppHeaderComponent;
