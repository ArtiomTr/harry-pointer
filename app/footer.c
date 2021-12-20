#include "footer.h"

#include <stdlib.h>

HPNode *AppFooterComponent(AppFooterProps *props, HPChildren *children) {
    char *emailHref = calloc(sizeof(char), 100);

    sprintf(emailHref, "mailto:%s", props->contactEmail);

    return createHPNode(hpFooter,
                        ((HpFooterProps){}),
                        createHPNode(hpDiv,
                                     ((HpDivProps){.class = "footer__container"}),
                                     createHPNode(hpDiv,
                                                  ((HpDivProps){}),
                                                  createHPString("Email for help: "),
                                                  createHPNode(hpA,
                                                               ((HpAProps){.href = emailHref}),
                                                               createHPString(props->contactEmail))),

                                     createHPNode(hpDiv,
                                                  ((HpDivProps){}),
                                                  createHPString("Phone: "),
                                                  createHPString(props->contactPhone))));
}

HPElement AppFooter = (HPElement) AppFooterComponent;
