#include <iostream>
#include <conio.h>
#include "../Lab1/Hud.h"
#include "Shop.h"

void showCatalog(Shop& shop);
void showCart(Shop& shop);
void Order();

int main()
{
	Shop shop;
    showCatalog(shop);			
}

void showCatalog(Shop& shop)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

	bool exit = false;
	bool extendview = false;
	char choice;
	int page = 1;
	int* ids;
	while (!exit)
	{
		system("CLS");
		SetConsoleTextAttribute(Console, 121);
		cout << "CATALOG PAGE " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]ADD TO CART | [E]EXTEND | [C]CART " << shop.getCart().size() << " | [B]BACK ";
		Hud::fillstr(Console);
		SetConsoleTextAttribute(Console, 7);
		cout << endl << endl;
		ids = shop.printProducts(10, page, extendview);
		choice = _getch();
		switch (choice)
		{
		case 'z': case 'Z':
			if (page > 1) page--;
			break;
		case 'x': case 'X':
			page++;
			break;
		case 'b': case 'B':
			exit = true;
			break;
		case 'e': case 'E':
			extendview = !extendview;
			break;
		case 'c': case 'C':
			showCart(shop);
			break;
		case '0':
			shop.addToCart(ids[9]);
			break;
		case '1':
			shop.addToCart(ids[0]);
			break;
		case '2':
			shop.addToCart(ids[1]);
			break;
		case '3':
			shop.addToCart(ids[2]);
			break;
		case '4':
			shop.addToCart(ids[3]);
			break;
		case '5':
			shop.addToCart(ids[4]);
			break;
		case '6':
			shop.addToCart(ids[5]);
			break;
		case '7':
			shop.addToCart(ids[6]);
			break;
		case '8':
			shop.addToCart(ids[7]);
			break;
		case '9':
			shop.addToCart(ids[8]);
			break;
		}
	}
}

void showCart(Shop& shop)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

	bool exit = false;
	bool extendview = false;
	char choice;
	int page = 1;
	int* ids;
	while (!exit)
	{
		system("CLS");
		SetConsoleTextAttribute(Console, 121);
		cout << "CART PAGE " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]REMOVE FROM CART | [E]EXTEND | [O]ORDER | [B]BACK";
		Hud::fillstr(Console);
		SetConsoleTextAttribute(Console, 7);
		cout << endl << endl;
		ids = shop.printCart(10, page, extendview);
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
		case 'e': case 'E':
			extendview = !extendview;
			break;
		case 'o': case 'O':

		case '0':
			shop.removeFromCart(ids[9]);
			break;
		case '1':
			shop.removeFromCart(ids[0]);
			break;
		case '2':
			shop.removeFromCart(ids[1]);
			break;
		case '3':
			shop.removeFromCart(ids[2]);
			break;
		case '4':
			shop.removeFromCart(ids[3]);
			break;
		case '5':
			shop.removeFromCart(ids[4]);
			break;
		case '6':
			shop.removeFromCart(ids[5]);
			break;
		case '7':
			shop.removeFromCart(ids[6]);
			break;
		case '8':
			shop.removeFromCart(ids[7]);
			break;
		case '9':
			shop.removeFromCart(ids[8]);
			break;
		}
	}
}

void Order()
{

}