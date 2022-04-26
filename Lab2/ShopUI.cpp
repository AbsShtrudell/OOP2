#include "ShopUI.h"

ShopUI::ShopUI()
{
}

ShopUI::~ShopUI()
{
}

void ShopUI::start()
{
	showCatalog();
}

void ShopUI::showCatalog()
{
	bool exit = false;
	bool extendview = false;
	char choice;
	int page = 1;
	int* ids;
	while (!exit)
	{
		system("CLS");
		hud.setTextColor(121); 
		cout << "CATALOG PAGE " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]ADD TO CART | [E]EXTEND | [C]CART " << shop.getCart().size() << " | [A]ADMIN | [B]BACK ";
		hud.fillStr();
		hud.setTextColor(7);
		cout << endl << endl;
		ids = shop.printProducts(inPageItems, page, extendview);
		cout << endl;
		choice = _getch();
		switch (choice)
		{
		case 'a': case 'A':
			adminWindow();
			break;
		case 'z': case 'Z':
			if (page > 1) page--;
			break;
		case 'x': case 'X':
			if (page < shop.countPagesInStorage(inPageItems)) page++;
			break;
		case 'b': case 'B':
			exit = true;
			break;
		case 'e': case 'E':
			extendview = !extendview;
			break;
		case 'c': case 'C':
			showCart();
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

void ShopUI::showCart()
{
	bool exit = false;
	bool extendview = false;
	char choice;
	int page = 1;
	int* ids;
	while (!exit)
	{
		system("CLS");
		hud.setTextColor(121);
		cout << "CART PAGE " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]REMOVE FROM CART | [E]EXTEND | [O]ORDER | [B]BACK";
		hud.fillStr();
		hud.setTextColor(7);
		cout << endl << endl;
		ids = shop.printCart(inPageItems, page, extendview);
		cout << endl;
		choice = _getch();
		switch (choice)
		{
		case 'z': case 'Z':
			if (page > 1) page--;
			break;
		case 'x': case 'X':
			if (page < shop.countPagesInCart(inPageItems)) page++;
			break;
		case'b': case'B':
			exit = true;
			break;
		case 'e': case 'E':
			extendview = !extendview;
			break;
		case 'o': case 'O':
			orderWindow();
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

void ShopUI::adminWindow()
{
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
		hud.setTextColor(121);
		cout << "ADMIN WINDOW " << page << "  | [X]NEXT PAGE | [Z]PREVIUS PAGE | [0..9]" << modestr << " | [E]EXTEND | [A]ADD NEW | [C]CHANGE MODE | [B]BACK ";
		hud.fillStr();
		hud.setTextColor(7);
		cout << endl << endl;
		ids = shop.printProducts(10, page, extendview);
		cout << endl;
		choice = _getch();
		switch (choice)
		{
		case 'a': case 'A':
			try
			{
				addNewEntity();
			}
			catch (exception ex)
			{
				hud.setTextColor(9);
				cout << "WARNING!!!" << ex.what();
				hud.setTextColor(7);
				_getch();
			}
			break;
		case 'z': case 'Z':
			if (page > 1) page--;
			break;
		case 'x': case 'X':
			if(page < shop.countPagesInStorage(inPageItems)) page++;
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
			interactAdmin(ids[9], editmode);
			break;
		case '1':
			interactAdmin(ids[0], editmode);
			break;
		case '2':
			interactAdmin(ids[1], editmode);
			break;
		case '3':
			interactAdmin(ids[2], editmode);
			break;
		case '4':
			interactAdmin(ids[3], editmode);
			break;
		case '5':
			interactAdmin(ids[4], editmode);
			break;
		case '6':
			interactAdmin(ids[5], editmode);
			break;
		case '7':
			interactAdmin(ids[6], editmode);
			break;
		case '8':
			interactAdmin(ids[7], editmode);
			break;
		case '9':
			interactAdmin(ids[8], editmode);
			break;
		}
	}
}

Entity ShopUI::entityEditWindow(Entity ent)
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
		hud.setTextColor(121);
		cout << "EDIT WINDOW   | [1]ID | [2]NAME | [3]PRICE | [4]TYPE | [B]BACK";
		hud.fillStr();
		hud.setTextColor(7);
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

void ShopUI::addNewEntity()
{
	Entity ent;
	string inputstr;
	float inputprice;
	system("CLS");
	hud.setTextColor(121);
	cout << "EDIT PAGE";
	hud.fillStr();
	hud.setTextColor(7);
	cout << endl << endl;
	cout << "ENTER ID: ";
	if (!(cin >> ent.id))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw(exception("NEW ENTITY CREATION FAILED"));
	}
	cin.clear();
	cin.ignore();
	cout << "ENTER NAME: ";
	getline(cin, inputstr);
	ent.product.setName(inputstr);
	cout << "ENTER PRICE: ";
	if (!(cin >> inputprice))
	{
		cin.clear();
		while (cin.get() != '\n');
		throw(exception("NEW ENTITY CREATION FAILED"));
	}
	cin.clear();
	cin.ignore();
	ent.product.setPrice(inputprice);
	cout << "ENTER TYPE: ";
	getline(cin, inputstr);
	ent.product.setType(Product::stringToType(inputstr));
	shop.addNewEntity(ent);
}

void ShopUI::orderWindow()
{
	int maxPages = shop.countPagesInCart(inPageItems);
	system("CLS");
	cout << "ORDER HAS BEEN PROCESSED! THANK YOU FOR CHOSING US!\n\n";
	for(int i = 0; i < maxPages; i++) 
		shop.printCart(inPageItems, i+1, false);

	cout << endl << "Total Price: " << shop.countPrice() << '$';
	_getch();
	shop.clearCart();
}

void ShopUI::interactAdmin(int id, bool editmode)
{
	if (editmode)
	{
		Entity ent;
		try
		{
			ent = shop.findEntityInStorage(id);
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
			system("pause");
			return;
		}
		shop.editEntityInStorage(entityEditWindow(ent), id);
	}
	else shop.removeEntityFromStorage(id);
}