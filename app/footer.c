#include "footer.h"

#include <stdlib.h>

HPNode *AppFooterComponent(AppFooterProps *props, HPChildren *children) {
    char *emailHref = calloc(sizeof(char), 100);

    sprintf(emailHref, "mailto:%s", props->contactEmail);

    return createHPNode(hpFooter,
                        ((HpFooterProps){.class = "footer centralizer"}),
                        createHPNode(hpDiv,
                                     ((HpDivProps){.class = "footer__container centralizer__container"}),
                                     createHPNode(hpDiv,
                                                  ((HpDivProps){}),
                                                  createHPString("Email for help: "),
                                                  createHPNode(hpA,
                                                               ((HpAProps){.href = emailHref}),
                                                               createHPString(props->contactEmail))),

                                     createHPNode(hpDiv,
                                                  ((HpDivProps){}),
                                                  createHPString("Phone: "),
                                                  createHPString(props->contactPhone)),
                                     createHPNode(hpSpan,
                                                  ((HpSpanProps){.class = "powered-by"}),
                                                  createHPString("Powered by harry-pointer"))));
}

HPElement AppFooter = (HPElement) AppFooterComponent;
