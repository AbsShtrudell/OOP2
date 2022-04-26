#pragma once
#include "Shop.h"
#include <iostream>
#include <conio.h>
#include "Hud.h"

class ShopUI
{
public:
	ShopUI();
	~ShopUI();

	void start();
	void showCatalog();
	void showCart();
	void adminWindow();
	Entity entityEditWindow(Entity ent);
	void addNewEntity();
	void orderWindow();
	void interactAdmin(int id, bool editmode);

private:
	Shop shop;
	Hud hud;
	int inPageItems = 10;
};

