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
		cout << ex.what();
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

void Shop::processOrder(IOrder* order)
{
}

const vector<Entity> Shop::getCart() const
{
	return cart;
}

Storage& Shop::getStorage()
{
	return storage;
}

