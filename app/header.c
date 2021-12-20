#include "header.h"

HPNode *AppHeaderComponent(AppHeadProps *props, HPChildren children) {
    return createHPNode(
            hpHeader,
            ((HpHeaderProps){.class = "header"}),
            createHPNode(hpDiv, ((HpDivProps){.class = "header__container"}), createHPString(props->shopTitle)));
}

HPElement AppHeader = (HPElement) AppHeaderComponent;
