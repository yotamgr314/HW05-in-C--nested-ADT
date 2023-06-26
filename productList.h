#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

typedef struct Product* productInstancePTR;

typedef enum
{
	ELECTRONICS,
	CLOTHING,
	BOOKS,
	BEAUTY
}Category;

typedef enum
{
	FAIL,
	SUCSSES,
	MEMEFAIL

}result;


productInstancePTR create_NewProductNode(char* newname, int newprice, Category newCategory);
result insertNewProductNode_end(productInstancePTR* productHead, productInstancePTR newProductToInsert);
void printAllProducts(productInstancePTR productHead);
result insertNewProductNode_start(productInstancePTR* productHead, productInstancePTR productToInsert);

void destroyLinkedList(productInstancePTR* productHead);

result insertNewProductNode_afterkey(productInstancePTR* productHead, char* namekey, productInstancePTR productToInsert);
result removeProductNode(productInstancePTR* productHead, char* name);
result changeCategorybyKey(productInstancePTR* productHead, char* productNamekey, Category newcategory);
double getTotalPrice(productInstancePTR productHead);







#endif


