#include "Shop.h"

Shop::Shop()
{
}

Shop::Shop(const Shop& shop) : storage(shop.storage)
{
}

Shop::~Shop()
{
}

void Shop::printProducts(int inPage, int page)
{
	//if (page * inPage < storage.getEntities().size())
	{
		int firstElem = page == 1? 0: page * inPage - 1;
		for (int i = firstElem;
			i < ((firstElem + inPage > storage.getEntities().size()) ? firstElem + inPage : storage.getEntities().size()); i++)
			printf(" |%i. %s", i, storage.getEntities().at(i).product.getName().c_str());
	}
}

void Shop::addToCart(int id)
{
	cart.push_back(storage.findEnity(id));
}

void Shop::removeFromCart(int id)
{
	for (size_t i = 0; i < cart.size(); i++)
		if (cart.at(i).id == id)
		{
			cart.erase(cart.begin() + i);
			break;
		}
}

void Shop::processOrder(SimpleOrder orderorder)
{
}

