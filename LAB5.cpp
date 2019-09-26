// Lab5: Thiet ke, thuc hien va su dung bang bam 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 1009 
#define NULL_ITEM -1
#define DELETED_ITEM -2
#define STAN_ITEM -3
#define ITEM_NAME_SIZE 32

#define SUCCESS 0
#define INSERT_ALREADY_EXIST -1
#define TABLE_FULL -2
#define SELECT_NO_ROW -3
#define DELETE_NO_ROW -4
#define UPDATE_NO_ROW -5

// Mot san pham gom co 3 truong: code ,label, price
typedef struct{
	int itemCode;
	char itemName[ITEM_NAME_SIZE];
	float itemPrice;
	struct Item *next;
} item;

item table[TABLE_SIZE];

// Ham khoi tao gia tri ban dau 
void init() 
{
	int i;
	for (i=0;i<TABLE_SIZE;i++) table[i].itemCode = NULL_ITEM;
}


// 1.Thuc hien ham hashkey
int hashkey(int itemCode, int nbTry)
{
	int h1 = itemCode % TABLE_SIZE;    //  Ham bam su dung pp chia , dung so du : h(k) = k mod m: k la khoa , m la kich thuoc bang[TABLE_SIZE]
	int h2 = 1 + (itemCode %(TABLE_SIZE - 1));
	return (h1 + nbTry *h2) % TABLE_SIZE; 
}	

// 2. Thuc hien ham chen Insertion
int insertItem(int itemCode, char* itemName, int itemPrice)
{
	int i = 0;     // So lan thu tim kiem i = 0
	int key = hashkey(itemCode,i);  // 
	while (i < TABLE_SIZE && table[key].itemCode != NULL_ITEM) // So lan thu tim kiem nho hon kich thuoc bang bam va table[key].itemCode khac null_item 
	{
		if (table[key].itemCode == itemCode) return INSERT_ALREADY_EXIST;   // item vua o trong bang thi tra ve vua ton tai
		i++;        // tang bien i them 1
		key = hashkey(itemCode,i);   //lay lai ket qua 
	}
	
	if (table[key].itemCode == NULL_ITEM)   //bang rong , chua co trong bang 
	{
		table[key].itemCode = itemCode;
		table[key].itemPrice = itemPrice;
		strcpy(table[key].itemName, itemName);  // gan cho chuoi 
		return SUCCESS;    // Neu vua chen thanh cong thi tra ve sucess
	} 
	else 
	{
		return TABLE_FULL;   // Neu bang day thi tra ve bang full
	}
}

// 3. Thuc hien ham xoa Deletion
int deleteItem(int itemCode)
{
	int i = 0;
	int key = hashkey(itemCode,i);
	while (i < TABLE_SIZE && table[key].itemCode != itemCode) 
	{
		i++;
		key = hashkey(itemCode,i);   // lay lai hash key 

	}
	
	if (table[key].itemCode == itemCode)  //
	{
		table[key].itemCode = NULL_ITEM;
		return SUCCESS;   // neu da xoa thanh cong thi ham tra ve sucess
	}

	return DELETE_NO_ROW;  // neu khong ton tai thi tra ve delete_no_row
}

// 4. Thuc hien ham hien thi ra man hinh 
void dumpItem()	
{	
	int i=0;
	for (i=0; i<TABLE_SIZE; i++)
	{
		if (table[i].itemCode != NULL_ITEM)
		{
			printf("The product code is : %d \n", table[i].itemCode);
			printf("The wording is : %s \n", table[i].itemName);
			printf("The price is : %f \n", table[i].itemPrice);
			printf("The index in the hash table is : %d \n", i);
			printf("\n\n\n");
		}
	}
}

// 5. Thuc hien ham lay gia cua mot san pham 
float getPrice (int itemCode)
{
	int i = 0;
	int key = hashkey(itemCode,i);
	while (i < TABLE_SIZE && table[key].itemCode != itemCode) 
	{
		i++;
		key = hashkey(itemCode,i);
	}
	if (table[key].itemCode == itemCode)
	{
		return table[key].itemPrice;   // co thi tra ve gia cua item can tim
	return SELECT_NO_ROW;  // khong co thi select_no_row
	}
}

//6. Thuc hien ham update cua mot san pham
int updateItem( int itemCode, char* itemName, float itemPrice)
{
	int i = 0;
	int key = hashkey(itemCode,i);
	while (i < TABLE_SIZE && table[key].itemCode != itemCode) 
	{
		i++;
		key = hashkey(itemCode,i);
	}
	if (table[key].itemCode == itemCode)
	{
		table[key].itemCode = itemCode;
		strcpy(table[i].itemName, itemName);
		table[key].itemPrice = itemPrice;
		return SUCCESS;
	}
	return UPDATE_NO_ROW;
}

int main(){
	init();
	
	insertItem(10001, "Sugar", 50000);  // Them vao
	insertItem(10002, "Salt", 7500);
	insertItem(10003, "Rice", 15000);
	insertItem(10004, "Fish source", 30000);
	insertItem(10005, " Salt", 35000);
	
	deleteItem(10005);   // Xoa item 1005

	dumpItem();  // display
	
	printf("Price of 10001: %f\n", getPrice(10001));
	return 0;
}







