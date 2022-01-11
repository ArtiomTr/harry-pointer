#include "pages.h"

#include "app.h"
#include "categoryList.h"
#include "document.h"
#include "productList.h"

HPNode *CategoryListPageComponent(ShopInfo *info, HPChildren *children) {
    return createHPNode(Document,
                        ((DocumentProps){
                                .title = info->shopTitle,
                        }),
                        createHPNode(App,
                                     *info,
                                     createHPNode(CategoryList,
                                                  ((CategoryListProps){
                                                          .categoryCount = info->categoryCount,
                                                          .categories = info->categories,
                                                  }),
                                                  NULL)));
}

HPElement CategoryListPage = (HPElement) CategoryListPageComponent;

const char categoryPageStyle[] = ".category-header {\n"
                                 "    height: 200px;\n"
                                 "    position: relative;\n"
                                 "}\n"
                                 ".category-header > img {\n"
                                 "    width: 100%;\n"
                                 "    height: 100%;\n"
                                 "    object-fit: cover;\n"
                                 "}\n"
                                 ".category-header__title {\n"
                                 "    position: absolute;\n"
                                 "    bottom: 0;\n"
                                 "    left: 15px;\n"
                                 "    color: white;\n"
                                 "    text-shadow: 1px 1px 1px black;\n"
                                 "}";

HPNode *CategoryPageComponent(CategoryPageProps *props, HPChildren *children) {
    return createHPNode(
            Document,
            ((DocumentProps){
                    .title = props->shopInfo.shopTitle,
            }),
            createHPNode(App,
                         props->shopInfo,
                         createHPNode(hpStyle, ((HpStyleProps){}), createHPString(categoryPageStyle)),
                         createHPNode(hpDiv,
                                      ((HpDivProps){.class = "category-header"}),
                                      createHPNode(hpImg, ((HpImgProps){.src = props->category.image}), NULL),
                                      createHPNode(hpH2,
                                                   ((HpH2Props){.class = "category-header__title"}),
                                                   createHPString(props->category.title))),
                         createHPNode(ProductList,
                                      ((ProductListProps){.products = props->category.products,
                                                          .productCount = props->category.productCount}),
                                      NULL)));
}

HPElement CategoryPage = (HPElement) CategoryPageComponent;
