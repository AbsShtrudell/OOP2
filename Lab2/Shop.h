#pragma once
#include <iomanip>
#include "../Lab1/Hud.h"
#include "Storage.h"
#include "SimpleOrder.h"

class Shop
{
public:
	Shop();
	Shop(const Shop& shop);
	~Shop();

	int* printProducts(int inPage, int page, bool extendView);
	int* printCart(int inPage, int page, bool extendView);
	void addToCart(int id);
	void removeFromCart(int id);
	void clearCart();
	void processOrder(IOrder* order);
	float countPrice();
	const vector<Entity> getCart() const;

private:
	vector<Entity> cart;
	Storage storage;
};

