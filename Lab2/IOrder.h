#pragma once

#include <vector>
#include <string>
#include "Entity.h"

using namespace std;

class IOrder
{
public:
	struct Address;

	IOrder(){};
	IOrder(const IOrder& order) : entities(order.entities) {};
	virtual ~IOrder(){};

	virtual bool authorize() = 0;
	virtual void setCart(vector<Entity> ents) = 0;
	virtual const vector<Entity> getCart() const = 0;
	virtual float countPrice() = 0;

protected:
	vector<Entity> entities;

public:
	struct Address
	{
		string city,
			street;
		int house,
			quarter;
	};
};

