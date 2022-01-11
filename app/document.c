#include "document.h"

const char fontUrl[] = "https://fonts.googleapis.com/css2?family=Poppins:wght@200;400;700&display=swap";
const char globalStyle[] = "* {\n"
                           "    font-family: \"Poppins\", sans-serif;\n"
                           "}\n"
                           "html,\n"
                           "body {\n"
                           "    padding: 0;\n"
                           "    margin: 0;\n"
                           "}\n"
                           ".app {\n"
                           "    min-height: 100vh;\n"
                           "    max-height: 100vh;\n"
                           "    display: flex;\n"
                           "    flex-direction: column;\n"
                           "}\n"
                           ".content {\n"
                           "    flex: 1;\n"
                           "    display: flex;\n"
                           "    flex-direction: column;\n"
                           "    overflow-y: auto;\n"
                           "}\n"
                           ".main {\n"
                           "    flex: 1;\n"
                           "}\n"
                           ".header {\n"
                           "    top: 0;\n"
                           "    position: sticky;\n"
                           "    border-bottom: 2px solid #cdcdcd;\n"
                           "    padding: 10px 0;\n"
                           "}\n"
                           ".footer {\n"
                           "    border-top: 2px solid #cdcdcd;\n"
                           "    padding: 10px 0;\n"
                           "}\n"
                           ".header__container {\n"
                           "    display: flex;\n"
                           "    align-items: center;\n"
                           "    color: black;\n"
                           "    text-decoration: none;\n"
                           "}\n"
                           ".centralizer {\n"
                           "    display: flex;\n"
                           "    justify-content: center;\n"
                           "}\n"
                           ".centralizer__container {\n"
                           "    width: 600px;\n"
                           "    max-width: 600px;\n"
                           "    padding: 0 10px;\n"
                           "}\n"
                           ".logo,\n"
                           ".logo::before,\n"
                           ".logo::after {\n"
                           "    content: \" \";\n"
                           "    min-width: 1rem;\n"
                           "    max-width: 1rem;\n"
                           "    min-height: 1rem;\n"
                           "    max-height: 1rem;\n"
                           "}\n"
                           ".logo {\n"
                           "    margin-right: 10px;\n"
                           "}\n"
                           ".logo::before,\n"
                           ".logo::after {\n"
                           "    position: absolute;\n"
                           "    transform-origin: center;\n"
                           "    background-color: black;\n"
                           "    transform: rotate(45deg);\n"
                           "}\n"
                           ".logo::after {\n"
                           "    min-width: 0.5rem;\n"
                           "    max-width: 0.5rem;\n"
                           "    min-height: 0.5rem;\n"
                           "    max-height: 0.5rem;\n"
                           "    background-color: white;\n"
                           "    transform: rotate(45deg) translate(0.35rem, 0);\n"
                           "}\n"
                           ".powered-by {\n"
                           "    padding: 3px 5px;\n"
                           "    font-size: 10px;\n"
                           "    background-color: #101010;\n"
                           "    color: #fff;\n"
                           "    border-radius: 5px;\n"
                           "}";

HPNode *DocumentComponent(DocumentProps *props, HPChildren children) {
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
                                              .crossOrigin = "anonymous",
                                      }),
                                      NULL),
                         createHPNode(hpLink,
                                      ((HpLinkProps){
                                              .rel = "stylesheet",
                                              .href = (char *) fontUrl,
                                      }),
                                      NULL),
                         createHPNode(hpTitle, ((HpTitleProps){}), createHPString(props->title)),
                         createHPNode(hpStyle, ((HpStyleProps){}), createHPString(globalStyle))),
            createHPNodeImpl(hpBody, &((HpBodyProps){}), children));
}

HPElement Document = (HPElement) DocumentComponent;
