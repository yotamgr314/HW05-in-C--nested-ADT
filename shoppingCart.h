#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "productList.h"

typedef struct shoppingCart* shoppingCartInstancePTR;





shoppingCartInstancePTR createShoppingCart();

result insertShoppingCartNode_end(shoppingCartInstancePTR* head, shoppingCartInstancePTR newCartInstance);

void displayShoppingCarts(shoppingCartInstancePTR head);

result insertProductToCart(shoppingCartInstancePTR* cartInstance, productInstancePTR productToInsert);

result removeProductFromCart(shoppingCartInstancePTR* head, char* productNameKey);


void calculateTotalPrice(shoppingCartInstancePTR shoppingCart);

void displayProductsForaCart(shoppingCartInstancePTR cartToDisplay);







#endif