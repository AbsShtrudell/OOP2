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

int* Shop::printProducts(int inPage, int page, bool extendView)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	int* output = new int[inPage];
	int firstElem = (page - 1) * inPage;
	for (int i = firstElem;
		i < ((firstElem + inPage > storage.getEntities().size()) ? storage.getEntities().size() : firstElem + inPage);
		i++)
	{
		output[i - firstElem] = storage.getEntities().at(i).id;
		if(extendView) SetConsoleTextAttribute(Console, 121);
		printf("%i. %-25s    %-22s  %10.2f$", i + 1, storage.getEntities().at(i).product.getName().c_str(),
											Product::typeToString(storage.getEntities().at(i).product.getType()).c_str(),
											storage.getEntities().at(i).product.getPrice());
		if (extendView) SetConsoleTextAttribute(Console, 7);
		cout << endl;
		if (extendView)
		{
			for (auto ft : storage.getEntities().at(i).product.getCharacteristics().getFeaturesList())
			{
				cout << "|"<< setw(31) << left << ft.name << setw(40) << ft.description << endl;
			}
		}

	}
	return output;
}

int* Shop::printCart(int inPage, int page, bool extendView)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	int* output = new int[inPage];
	int firstElem = (page - 1) * inPage;
	for (int i = firstElem;
		i < ((firstElem + inPage > getCart().size()) ? getCart().size() : firstElem + inPage);
		i++)
	{
		output[i - firstElem] = getCart().at(i).id;
		if (extendView) SetConsoleTextAttribute(Console, 121);
		printf("%i. %-25s    %-22s  %10.2f$", i + 1, getCart().at(i).product.getName().c_str(),
											Product::typeToString(getCart().at(i).product.getType()).c_str(),
											getCart().at(i).product.getPrice());
		if (extendView) SetConsoleTextAttribute(Console, 7);
		cout << endl;
		if (extendView)
		{
			for (auto ft : getCart().at(i).product.getCharacteristics().getFeaturesList())
			{
				cout << "|" << setw(31) << left << ft.name << setw(40) << ft.description << endl;
			}
		}
	}

	return output;
}

void Shop::addToCart(int id)
{
	try
	{
		Entity ent = storage.findEnityId(id);
		cart.push_back(ent);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		system("pause");
	}
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

void Shop::clearCart()
{
	cart.clear();
}

void Shop::processOrder(IOrder* order)
{
}

const vector<Entity> Shop::getCart() const
{
	return cart;
}
void Shop::removeEntityFromStorage(int id)
{
	storage.removeEntityId(id);
}

void Shop::editEntityInStorage(Entity ent, int id)
{
	try
	{
		int index = storage.findEnitysIndex(id);
		storage.editEntity(ent, index);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		system("pause");
	}
}

Entity Shop::findEntityInStorage(int id) const
{
	try
	{
		return storage.findEnityId(id);
	}
	catch (exception ex)
	{
		throw(exception(ex.what()));
	}
}

void Shop::addNewEntity(Entity ent)
{
	storage.addEntity(ent);
}

int Shop::countPagesInCart(int inPageItems) const
{
	return countPages(cart, inPageItems);
}

int Shop::countPagesInStorage(int inPageItems) const
{
	return countPages(storage.getEntities(), inPageItems);
}

int Shop::countPages(vector<Entity> ents, int inPageItems) const
{
	if (!(ents.size() % inPageItems)) return ents.size() / inPageItems;
	else return ents.size() / inPageItems + 1;
	return 0;
}

float Shop::countPrice()
{
	float price = 0.f;
	for (size_t i = 0; i < getCart().size(); i++)
	{
		price += getCart().at(i).product.getPrice();
	}
	return price;
}
