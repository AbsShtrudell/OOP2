#pragma once
#include "IOrder.h"

class SimpleOrder : protected IOrder
{
public:
	virtual bool authorize() override;
	virtual void setCart(vector<Entity> ents) override;
	virtual const vector<Entity> getCart() const override;
	virtual float countPrice() override;
};

