#include "SimpleOrder.h"

bool SimpleOrder::authorize()
{
	return true;
}

void SimpleOrder::setCart(vector<Entity> ents)
{
	entities = ents;
}

const vector<Entity> SimpleOrder::getCart() const
{
	return entities;
}


float SimpleOrder::countPrice()
{
	float price = 0.f;
	for (size_t i = 0; i < getCart().size(); i++)
	{
		price += getCart().at(i).product.getPrice();
	}
	return price;
}