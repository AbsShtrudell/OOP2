#include <iostream>
#include <conio.h>
#include "../Lab1/Hud.h"
#include "Shop.h"

void showCatalog(Shop& shop);
void showCart(Shop& shop);
void Admin(Shop& shop);
Entity EditWindow(Entity ent);

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
		cout << "CATALOG PAGE " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]ADD TO CART | [E]EXTEND | [C]CART " << shop.getCart().size() << " | [A]ADMIN | [B]BACK ";
		Hud::fillstr(Console);
		SetConsoleTextAttribute(Console, 7);
		cout << endl << endl;
		ids = shop.printProducts(10, page, extendview);
		choice = _getch();
		switch (choice)
		{
		case 'a': case 'A':
			Admin(shop);
			break;
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
			Order(shop);
			break;
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

void Order(Shop& shop)
{
	system("CLS");
	cout << "ORDER HAS BEEN PROCESSED! THANK YOU FOR CHOSING US!\n";
	shop.printCart(10, 1, false);
	shop.printCart(10, 2, false);

	cout << endl << "Price: " << shop.countPrice() << '$';
	_getch();
	shop.clearCart();
void Admin(Shop& shop)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

	bool exit = false;
	bool editmode = true;
	bool extendview = false;
	char choice;
	int page = 1;
	int* ids;
	string modestr = "EDIT";
	while (!exit)
	{
		system("CLS");
		SetConsoleTextAttribute(Console, 121);
		cout << "ADMIN PAGE " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]" << modestr << " | [E]EXTEND | [A]ADD NEW | [C]CHANGE MODE | [B]BACK ";
		Hud::fillstr(Console);
		SetConsoleTextAttribute(Console, 7);
		cout << endl << endl;
		ids = shop.printProducts(10, page, extendview);
		choice = _getch();
		switch (choice)
		{
		case 'a': case 'A':
			break;
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
			if (editmode)
			{
				modestr = "REMOVE";
				editmode = !editmode;
			}
			else
			{
				modestr = "EDIT";
				editmode = !editmode;
			}
			break;
		case '0':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[9])), shop.getStorage().findEnityIndex(ids[9]));
			else shop.getStorage().removeEntityId(ids[9]);
			break;
		case '1':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[0])), shop.getStorage().findEnityIndex(ids[0]));
			else shop.getStorage().removeEntityId(ids[0]);
			break;
		case '2':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[1])), shop.getStorage().findEnityIndex(ids[1]));
			else shop.getStorage().removeEntityId(ids[1]);
			break;
		case '3':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[2])), shop.getStorage().findEnityIndex(ids[2]));
			else shop.getStorage().removeEntityId(ids[2]);
			break;
		case '4':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[3])), shop.getStorage().findEnityIndex(ids[3]));
			else shop.getStorage().removeEntityId(ids[3]);
			break;
		case '5':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[4])), shop.getStorage().findEnityIndex(ids[4]));
			else shop.getStorage().removeEntityId(ids[4]);
			break;
		case '6':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[5])), shop.getStorage().findEnityIndex(ids[5]));
			else shop.getStorage().removeEntityId(ids[5]);
			break;
		case '7':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[6])), shop.getStorage().findEnityIndex(ids[6]));
			else shop.getStorage().removeEntityId(ids[6]);
			break;
		case '8':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[7])), shop.getStorage().findEnityIndex(ids[7]));
			else shop.getStorage().removeEntityId(ids[7]);
			break;
		case '9':
			if (editmode)shop.getStorage().editEntity(EditWindow(shop.getStorage().findEnityId(ids[8])), shop.getStorage().findEnityIndex(ids[8]));
			else shop.getStorage().removeEntityId(ids[8]);
			break;
		}
	}
}

Entity EditWindow(Entity ent)
{
	bool exit = false;
	bool editmode = true;
	bool extendview = false;
	char choice;
	string inputstr = " ";
	float inputprice;
	while (!exit)
	{
		system("CLS");
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Console, 121);
		cout << "EDIT PAGE  | [1]ID | [2]NAME | [3]PRICE | [4]TYPE | [B]BACK";
		Hud::fillstr(Console);
		SetConsoleTextAttribute(Console, 7);
		cout << endl << endl;
		choice = _getch();
		switch (choice)
		{
		case 'b': case 'B':
			exit = true;
			break;
		case '1':
			cout << "OLD ID: " << ent.id << endl;
			cout << "NEW ID: ";
			cin >> ent.id;
			break;
		case '2':
			cout << "OLD NAME: " << ent.product.getName() << endl;
			cout << "NEW NAME: ";
			getline(cin, inputstr);
			ent.product.setName(inputstr);
			break;
		case '3':
			cout << "OLD PRICE: " << ent.product.getPrice() << endl;
			cout << "NEW PRICE: ";
			cin >> inputprice;
			ent.product.setPrice(inputprice);
			break;
		case '4':
			cout << "OLD TYPE: " << Product::typeToString(ent.product.getType()) << endl;
			cout << "NEW TYPE: ";
			getline(cin, inputstr);
			ent.product.setType(Product::stringToType(inputstr));
			break;
		}
	}
	return ent;
}