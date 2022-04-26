#pragma once
#include <iomanip>
#include <Windows.h>
#include <iostream>
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
	void removeEntityFromStorage(int id);
	void editEntityInStorage(Entity ent, int id);
	Entity findEntityInStorage(int id) const;
	void addNewEntity(Entity ent);

	int countPagesInCart(int inPageItems) const;
	int countPagesInStorage(int inPageItems) const;

private:
	int countPages(vector<Entity> ents, int inPageItems) const;

	vector<Entity> cart;
	Storage storage;
};

