#define _CRTDBG_MAP_ALLOC
#include "productList.h"
#include "shoppingCart.h"
#include "user.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{

    shoppingCartInstancePTR shoppingCartHead = NULL; // thats the head of the shoppingCartList.

    shoppingCartInstancePTR ShoppingCart1 = createShoppingCart("yotam"); // the constructor.
    shoppingCartInstancePTR ShoppingCart2 = createShoppingCart("nadav"); // the constructor.

    

    productInstancePTR product1 = create_NewProductNode("computer", 40, ELECTRONICS); // creating a new product instance.
    productInstancePTR product2 = create_NewProductNode("Shirt", 40, BEAUTY); // creating a new product instance.



    userInstancePTR userHead = NULL;

    userInstancePTR user1 = userCreate("yotam");
    userInstancePTR user2 = userCreate("nadav");
    insertUser_end(&userHead, user1);
    insertUser_end(&userHead, user2);
    userDisplay(userHead);

    insertCartToUser(&user1, ShoppingCart2);
    insertProductToUserCart(&user1, product1);
    userDisplay(userHead);

    userDisplay(userHead);
    _CrtDumpMemoryLeaks();
    return 0;
}









                                                   //FORMER MAIN.C I DID DURING THE CREATION OF EACH ADT (TO CHECK THEY ARE ACTULLY WORKING.) IN THIS NESTED ADT PROGRAM 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------









//int main()
//{
//    productInstancePTR productHead = NULL; // thats the head of the productsList
//
//    productInstancePTR product1 = create_NewProductNode("yotam", 40, ELECTRONICS);
//    productInstancePTR product2 = create_NewProductNode("nadav", 40, CLOTHING);
//    productInstancePTR product3 = create_NewProductNode("daniela", 40, BOOKS);
//    productInstancePTR product4 = create_NewProductNode("shosh", 25, BEAUTY);
//    productInstancePTR product5 = create_NewProductNode("debby", 25, BEAUTY);
//
//    insertNewProductNode_start(&productHead, product1);
//    insertNewProductNode_end(&productHead, product2);
//    insertNewProductNode_end(&productHead, product3);
//    insertNewProductNode_end(&productHead, product4);
//    insertNewProductNode_end(&productHead, product5);
//
//
//    printAllProducts(productHead);
//    printf("\n");
// 
//    printAllProducts(productHead);
//    removeProductNode(&productHead, "shosh");
//    printAllProducts(productHead);
//    removeProductNode(&productHead, "yotam");
//    printAllProducts(productHead);
//
//    destroyLinkedList(&productHead);
//    printAllProducts(productHead);
//    
//   
//    _CrtDumpMemoryLeaks();
//    return 0;
//}




//int main()
//{
//
//    shoppingCartInstancePTR shoppingCartHead = NULL; // thats the head of the shoppingCartList.
//
//    shoppingCartInstancePTR ShoppingCart1 = createShoppingCart("yotam"); // the constructor.
//    shoppingCartInstancePTR ShoppingCart2 = createShoppingCart("nadav"); // the constructor.
//
//    insertShoppingCartNode_end(&shoppingCartHead, ShoppingCart1); // inserting this new Node.
//    insertShoppingCartNode_end(&shoppingCartHead, ShoppingCart2); // inserting this new Node.
//
//
//    productInstancePTR product1 = create_NewProductNode("computer", 40, ELECTRONICS); // creating a new product instance.
//    productInstancePTR product2 = create_NewProductNode("Shirt", 40, BEAUTY); // creating a new product instance.
//
//    insertProductToCart(&ShoppingCart1, product1);
//    insertProductToCart(&ShoppingCart2, product2);
//    displayShoppingCarts(shoppingCartHead);
//    
//
//    _CrtDumpMemoryLeaks();
//    return 0;
//}






//int main()
//{
//    userInstancePTR userHead = NULL;
//
//    userInstancePTR user1 = userCreate("yotam");
//    userInstancePTR user2 = userCreate("nadav");
//
//    insertUser_end(&userHead, user1);
//    insertUser_end(&userHead, user2);
//    userDisplay(userHead);
//    
//    shoppingCartInstancePTR ShoppingCart1 = createShoppingCart("yotam"); // the constructor.
//
//   /* result insertCartToUser(&user1, ShoppingCart1);*/
//
//    //shoppingCartInstancePTR ShoppingCart2 = createShoppingCart("nadav"); // the constructor.
//
//    //insertShoppingCartNode_end(&shoppingCartHead, ShoppingCart1); // inserting this new Node.
//    //insertShoppingCartNode_end(&shoppingCartHead, ShoppingCart2); // inserting this new Node.
//
//
//    //productInstancePTR product1 = create_NewProductNode("computer", 40, ELECTRONICS); // creating a new product instance.
//    //productInstancePTR product2 = create_NewProductNode("Shirt", 40, BEAUTY); // creating a new product instance.
//
//    //insertProductToCart(&ShoppingCart1, product1);
//    //insertProductToCart(&ShoppingCart2, product2);
//    //displayShoppingCarts(shoppingCartHead);
//
//
//
//
//    //insertCartToUser(&user1, ShoppingCart2);
//    //userDisplay(userHead);
//    _CrtDumpMemoryLeaks();
//    return 0;
//}












