#ifndef USER_H
#define USER_H
#include "shoppingCart.h"

typedef struct user* userInstancePTR;


userInstancePTR userCreate(char* userNewName);

result insertUser_end(userInstancePTR* userHead, userInstancePTR userToInsert);

result userDisplay(userInstancePTR userHead);

result insertCartToUser(userInstancePTR* userInstance, shoppingCartInstancePTR cartInstance);

result insertProductToUserCart(userInstancePTR* userInstance, productInstancePTR productToInsert);




#endif