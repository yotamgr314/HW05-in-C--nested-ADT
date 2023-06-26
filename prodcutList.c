#include "productList.h"
#include <string.h>
#include <stdio.h>


struct Product
{
	char* name;
	double price;
	Category category;
	/*productInstancePTR next;*/
	struct Product* next;

};

productInstancePTR create_NewProductNode(char* newname, int newprice, Category newCategory)
{
	productInstancePTR newProductNode = (productInstancePTR)malloc(sizeof(struct Product));
	if (newProductNode == NULL)
	{
		return NULL;
	}
	newProductNode->name = (char*)malloc(strlen(newname) + 1);
	if (newProductNode->name == NULL)
	{
		free(newProductNode);
		return NULL;
	}
	// initilize the node.		
	strcpy(newProductNode->name, newname);
	newProductNode->price = newprice;
	newProductNode->category = newCategory;
	newProductNode->next = NULL;
	return newProductNode;
}




result insertNewProductNode_end(productInstancePTR* productHead, productInstancePTR newProductToInsert)
{
	if (*productHead == NULL)
	{
		*productHead = newProductToInsert;
		return SUCSSES;
	}
	productInstancePTR curr = *productHead;// derefrencing the head pointer so i can assign the value stored at the memory location pointed to by productHead to runner
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newProductToInsert;
	return SUCSSES;
}


void printAllProducts(productInstancePTR productHead)
{
	if (productHead == NULL)
	{
		printf("**THE USER CART CONTAINS 0 PRODUCTS**\n");
		return;
	}

	productInstancePTR curr = productHead;
	printf("**THE USER CART CONTAINS THE FOLLOWING PRDOCUTS**\n");
	while (curr != NULL)
	{
		printf("The product name is: %s\n", curr->name);
		switch (curr->category)
		{
		case (ELECTRONICS):
			printf("The product Category is : Electornics\n");
			break;
		case(CLOTHING):
			printf("The prodcut category is : CLOTHING\n");
			break;
		case(BOOKS):
			printf("The product catergory is : BOOKS\n");
			break;
		case(BEAUTY):
			printf("The product catergory is : BEAUTY\n");
			break;
		default:
			printf("**INVALID PRODUCT CATEGORY\n");

		}
		printf("The product price is :%f", curr->price);
		printf("\n");
		curr = curr->next;
	}
	printf("\n");
		
	
}

void destroyLinkedList(productInstancePTR* productHead)
{
	productInstancePTR curr = *productHead;
	while (curr != NULL)
	{

		productInstancePTR toRemove = curr;
		curr = curr->next;
		free(toRemove->name);
		free(toRemove);
	}
	printf("**LINKED LIST REMOVED SUCCESSFULLY**\n\n");
	*productHead = NULL;
	return;
}


result insertNewProductNode_start(productInstancePTR* productHead, productInstancePTR productToInsert)
{
	if (*productHead == NULL) // if the list is empty then head = productToInsert.
	{	
		*productHead = productToInsert;
		/*setToNULL(&productHead);*/
		
		return SUCSSES;
	}

	productToInsert->next = *productHead; // prodcutToInsert now points to our prodcutHead of the list. (note: thats still aint updating our head in the main.c)
	*productHead = productToInsert;		// derefrencing our productHead of the list to points to the newly productToInsert.
										// note: thats ok becuse in the previous line we set the newly productToInsert->next to point to our prodcutHead of the list. 
										// now we have a new head which is the newly prodcutToInsert && he points to the previous prodcutHead of the list.
	/*setToNULL(&productHead);*/
	return SUCSSES;
	
	
}


result insertNewProductNode_afterkey(productInstancePTR* productHead, char* namekey, productInstancePTR productToInsert)
{
	productInstancePTR curr = *productHead;
	
	while (curr != NULL)
	{
		if (strcmp(curr->name, namekey) == 0)
		{
			productToInsert->next = curr->next;
			curr->next = productToInsert;
			return SUCSSES;
		}
		curr = curr->next;
	}
	return FAIL;

}


result removeProductNode(productInstancePTR* productHead, char* name)
{
	productInstancePTR curr = *productHead;

	if (curr == NULL) // if linkedlist is empty

	{
		return FAIL;
	}

	
	if (strcmp(curr->name, name) == 0) // If head node itself holds the name to be deleted
	{
		productInstancePTR toRemove = curr;
		*productHead = curr->next;
		free(toRemove->name);
		free(toRemove);
		return SUCSSES;
	}

	
	while (curr->next != NULL) // Search for the name to be deleted, keep track of the previous node
	{
		if (strcmp(curr->next->name, name) == 0)
		{
			productInstancePTR toRemove = curr->next;
			curr->next = curr->next->next;
			free(toRemove->name);
			free(toRemove);
			return SUCSSES;
		}
		curr = curr->next;

	}
	return FAIL;
}

result changeCategorybyKey(productInstancePTR* productHead, char* productNamekey, Category newcategory)
{
	productInstancePTR curr = *productHead;
	while (curr != NULL)
	{
		if (strcmp(curr->name, productNamekey) == 0)
		{
			curr->category = newcategory;
			
			return SUCSSES;
		}
		curr = curr->next;
	}
	return FAIL;
}

double getTotalPrice(productInstancePTR productHead)
{
	productInstancePTR curr = productHead;
	double prodcutsListPrice = 0;
	while (curr != NULL)
	{
		prodcutsListPrice = prodcutsListPrice + curr->price;
		curr = curr->next;
	}
	return prodcutsListPrice;
}
