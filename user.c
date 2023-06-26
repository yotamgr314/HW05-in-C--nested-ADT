#include "shoppingCart.h"
#include "user.h"
#include <string.h>
#include <stdio.h>
struct user
{
	char* name;
	shoppingCartInstancePTR cart;
	//userInstancePTR next;
	struct user* next;
};



userInstancePTR userCreate(char* userNewName)
{
	userInstancePTR newUser =(userInstancePTR)malloc(sizeof(struct user));
	if (newUser == NULL)
	{
		return NULL;
	}
	newUser->name = (char*)malloc(strlen(userNewName) + 1);
	if (newUser->name == NULL)
	{
		free(newUser);
		return NULL;
	}
	strcpy(newUser->name, userNewName);
	
	newUser->next = NULL;
	newUser->cart = NULL;
	return newUser;
}

result insertUser_end(userInstancePTR* userHead, userInstancePTR userToInsert)
{
	if (userToInsert == NULL)
	{
		printf("the user to insert is NULL DUDE\n");
		return FAIL;
	}
	if (*userHead == NULL)
	{
		*userHead = userToInsert;
		return SUCSSES;
	}
	userInstancePTR curr = *userHead;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = userToInsert;
	return SUCSSES;
}

userDisplay(userInstancePTR userHead)
{
	if (userHead == NULL)
	{
		printf("UserHead is NULL");
		return FAIL;
	}
	userInstancePTR curr = userHead;
	while (curr != NULL)
	{
		printf("The user name is : %s\n",curr->name);
		displayShoppingCarts(userHead->cart);
		printf("\n");
		curr = curr->next;
	}
	return SUCSSES;
}

result insertCartToUser(userInstancePTR* userInstance, shoppingCartInstancePTR cartInstance)
{
	insertShoppingCartNode_end(&(*userInstance)->cart, cartInstance);
	return SUCSSES;
}

result insertProductToUserCart(userInstancePTR* userInstance, productInstancePTR productToInsert) // i could have equaily use the func below. but i wanted to show myself theres another approach 
																								  // diffrecnt than creating a local pointer than defrefrence it.
{
	  insertProductToCart(&(*userInstance)->cart ,productToInsert);

	  return SUCSSES;

}
