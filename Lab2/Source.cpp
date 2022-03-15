#include <iostream>
#include <conio.h>
#include "Shop.h"

void showCatalog(Shop& shop);
void showCart(Shop& shop);

int main()
{
	Shop shop;
	bool exit = false;
	char choice;
	while (!exit)
	{
		system("CLS");

		cout << "1.Show Catalog  2.Show Cart 3.Exit";
		choice = _getch();
		switch (choice)
		{
		case '1':
			showCatalog(shop);
			break;
		case '2':
			showCart(shop);
			break;
		case'3':
			exit = true;
			break;
		}
	}
}

void showCatalog(Shop& shop)
{
	bool exit = false;
	char choice;
	int page = 1;
	while (!exit)
	{
		system("CLS");

		cout << "CATALOG PAGE " << page << "\t| [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]ADD TO CART | [B]BACK\n";
		shop.printProducts(0, 10);
		choice = _getch();
		switch (choice)
		{
		case 'z': case 'Z':
			if (page > 1) page--;
			break;
		case 'x': case 'X':
			page++;
			break;
		case'b': case'B':
			exit = true;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break;
		}
	}
}

void showCart(Shop& shop)
{

}
