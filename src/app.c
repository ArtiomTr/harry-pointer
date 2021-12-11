#include "app.h"

#include "header.h"
#include "productGrid.h"

const char fontUrl[] = "https://fonts.googleapis.com/css2?family=Poppins:wght@200;400;700&display=swap";
const char globalStyle[] = "html, body {"
                           "    margin: 0;"
                           "    padding: 0;"
                           "    background-color: #F0F3EC;"
                           "    font-family: Poppins sans-serif;"
                           "}"
                           ".header {"
                           "    position: sticky;"
                           "    top: 0;"
                           "    height: 30px;"
                           "    background-color: #4F6F78;"
                           "    display: flex;"
                           "    justify-content: center;"
                           "    align-items: center;"
                           "}"
                           ".header__container {"
                           "    width: 600px;"
                           "    color: #fff;"
                           "}"
                           ".content-wrapper {"
                           "    margin: 20px 0;"
                           "    display: flex;"
                           "    justify-content: center;"
                           "}"
                           ".content {"
                           "    width: 600px;"
                           "}"
                           ".product-grid {"
                           "    display: grid;"
                           "    grid-template-columns: 1fr 1fr 1fr;"
                           "    grid-gap: 15px;"
                           "}"
                           ".product {"
                           "    border: 1px solid #cdcdcd;"
                           "    background-color: #fff;"
                           "    padding: 10px;"
                           "}"
                           ".product__title {"
                           "    font-size: 20px;"
                           "    font-weight: bold;"
                           "    word-break: break-word;"
                           "}"
                           ".product__info {"
                           "    color: #878787;"
                           "}";

HPNode *AppComponent(AppProps *props, HPChildren children) {
    return createHPNode(
            hpHtml,
            ((HpHtmlProps){.lang = "en"}),
            createHPNode(hpHead,
                         ((HpHeadProps){}),
                         createHPNode(hpMeta, ((HpMetaProps){.charset = "UTF-8"}), NULL),
                         createHPNode(hpLink,
                                      ((HpLinkProps){.rel = "preconnect", .href = "https://fonts.googleapis.com"}),
                                      NULL),
                         createHPNode(hpLink,
                                      ((HpLinkProps){
                                              .rel = "preconnect",
                                              .href = "https://fonts.gstatic.com",
                                              .crossOrigin = "true",
                                      }),
                                      NULL),
                         createHPNode(hpLink,
                                      ((HpLinkProps){
                                              .rel = "stylesheet",
                                              .href = fontUrl,
                                      }),
                                      NULL),
                         createHPNode(hpTitle, ((HpTitleProps){}), createHPString(props->shopTitle)),
                         createHPNode(hpStyle, ((HpStyleProps){}), createHPString(globalStyle))),
            createHPNode(hpBody,
                         ((HpBodyProps){}),
                         createHPNode(AppHeader,
                                      ((AppHeadProps){
                                              .shopTitle = props->shopTitle,
                                      }),
                                      NULL),
                         createHPNode(hpDiv,
                                      ((HpDivProps){.class = "content-wrapper"}),
                                      createHPNode(hpMain,
                                                   ((HpMainProps){.class = "content"}),
                                                   createHPNode(ProductGrid,
                                                                ((ProductGridProps){
                                                                        .productCount = props->productCount,
                                                                        .products = props->products,
                                                                }),
                                                                NULL)))));
}

HPElement App = (HPElement) AppComponent;
