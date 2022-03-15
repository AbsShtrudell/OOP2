#pragma once
#include "Storage.h"
#include "SimpleOrder.h"

class Shop
{
public:
	Shop();
	Shop(const Shop& shop);
	~Shop();

	void printProducts(int inPage, int page);
	void printCart();
	void addToCart(int id);
	void removeFromCart(int id);
	void processOrder(SimpleOrder order);

private:
	vector<Entity> cart;
	SimpleOrder order;
	Storage storage;
};

