#include "productList.h"
#include "shoppingCart.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct shoppingCart
{
	
	productInstancePTR products;
	//shoppingCartInstancePTR next;
	struct shoppingCart* next;
};

shoppingCartInstancePTR createShoppingCart()
{
	shoppingCartInstancePTR newShoppingCartNode = (shoppingCartInstancePTR)malloc(sizeof(struct shoppingCart));
	if (newShoppingCartNode == NULL)
	{
		return NULL;
	}
	
	newShoppingCartNode->products = NULL;
	newShoppingCartNode->next = NULL;
	return newShoppingCartNode;
}

result insertShoppingCartNode_end(shoppingCartInstancePTR* shoppingCartInstancehead, shoppingCartInstancePTR newCartInstance)
{
	shoppingCartInstancePTR curr = *shoppingCartInstancehead;
	if (curr == NULL)
	{
		*shoppingCartInstancehead = newCartInstance;
		return SUCSSES;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newCartInstance;
	return SUCSSES;
}

void displayShoppingCarts(shoppingCartInstancePTR head)
{
	if (head == NULL)
	{
		printf("**THE USER HAS NO CART**\n");
		return;
	}
	
	shoppingCartInstancePTR curr = head;
	while (curr != NULL)
	{
		
		printAllProducts(curr->products);
		calculateTotalPrice(curr);
		printf("\n");
		curr = curr->next;
	}
	return;
}

//result insertProductToCart(shoppingCartInstancePTR* cartInstance, productInstancePTR productToInsert)
//{
//	shoppingCartInstancePTR curr = *cartInstance;
//	if(*cartInstance == NULL)
//	{
//		printf("The ShoppingCart is NULL");
//		return FAIL;
//	}
//	
//	if (insertNewProductNode_end(&curr->products, productToInsert) == SUCSSES)
//	{
//		return SUCSSES;
//		printf("** NEW PRODUCT HAS BEEN ADDED SUCCESFULLY TO THE CART**");
//	}
//	return FAIL;
//	
//}


result insertProductToCart(shoppingCartInstancePTR* cartInstance, productInstancePTR productToInsert)
{
	
	if (*cartInstance == NULL)
	{
		printf("The ShoppingCart is NULL");
		return FAIL;
	}

	if (insertNewProductNode_end(&(*cartInstance)->products, productToInsert) == SUCSSES)
	{
		return SUCSSES;
		printf("** NEW PRODUCT HAS BEEN ADDED SUCCESFULLY TO THE CART**");
	}
	return FAIL;

}






result removeProductFromCart(shoppingCartInstancePTR* head, char* productNameKey)
{
	shoppingCartInstancePTR curr = *head;

	if (removeProductNode(&curr->products, productNameKey) == SUCSSES)
	{
		return SUCSSES;
	}
	return FAIL;
}

void calculateTotalPrice(shoppingCartInstancePTR shoppingCart)
{
	
	shoppingCartInstancePTR curr = shoppingCart;
	double CartTotalPrice = 0;
	
	CartTotalPrice = getTotalPrice(curr->products);
	printf("This user Cart total price : %f", CartTotalPrice);
	
	return;
}
void displayProductsForaCart(shoppingCartInstancePTR cartToDisplay)
{
	printAllProducts(cartToDisplay->products);

}















