#include "app.h"

#include "footer.h"
#include "header.h"

HPNode *AppComponent(ShopInfo *props, HPChildren children) {
    return createHPNode(
            hpDiv,
            ((HpDivProps){.class = "app"}),
            createHPNode(AppHeader,
                         ((AppHeadProps){
                                 .shopTitle = props->shopTitle,
                         }),
                         NULL),
            createHPNode(
                    hpDiv,
                    ((HpDivProps){.class = "content"}),
                    createHPNode(hpMain,
                                 ((HpMainProps){.class = "main centralizer"}),
                                 createHPNodeImpl(hpDiv, &((HpDivProps){.class = "centralizer__container"}), children)),
                    createHPNode(AppFooter,
                                 ((AppFooterProps){
                                         .contactPhone = props->contactPhone,
                                         .contactEmail = props->contactEmail,
                                 }),
                                 NULL)));
}

HPElement App = (HPElement) AppComponent;
