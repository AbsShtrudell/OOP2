#include "ItemList.h"
#include <iostream>
#include <iomanip>

ItemList::ItemList()
{
}

void ItemList::Add(std::string_view name, std::string_view type, int amount)
{
	auto ptr = std::make_shared<Item>(name, type, amount);

	if (!sortedItems.empty())
		ptr->SetID(sortedItems.top()->GetID() + 1);

	items.push(ptr);
	sortedItems.push(ptr);
}

void ItemList::Remove(int id)
{
	Items temp;

	while (!sortedItems.empty())
	{
		sortedItems.pop();
	}

	while (!items.empty())
	{
		if (items.top()->GetID() == id)
		{
			items.pop();

			if (items.empty())
				break;
		}

		temp.push(items.top());
		items.pop();
	}

	while (!temp.empty())
	{
		items.push(temp.top());
		sortedItems.push(temp.top());
		temp.pop();
	}



}

auto ItemList::Get(int id) -> std::optional<std::shared_ptr<Item>>
{
	Items temp;

	std::optional<std::shared_ptr<Item>> result = {};

	while (!items.empty())
	{
		if (items.top()->GetID() == id)
		{
			result = items.top();
			break;
		}

		temp.push(items.top());
		items.pop();
	}

	while (!temp.empty())
	{
		items.push(temp.top());
		temp.pop();
	}

	return result;
}

void ItemList::ShowInConsole()
{
	const int width = 25;
	Items temp;

	std::cout << std::left;

	std::cout << std::setw(width) << "ÈÄ" << std::setw(width) << "Íàçâàíèå" << std::setw(width) << "Òèï" << std::setw(width) << "Êîëè÷åñòâî" << std::endl;

	while (!items.empty())
	{
		std::cout << std::setw(width) << items.top()->GetID() << std::setw(width) << items.top()->GetName() << std::setw(width) << items.top()->GetType() << std::setw(width) << items.top()->GetAmount() << std::endl;

		temp.push(items.top());
		items.pop();
	}

	while (!temp.empty())
	{
		items.push(temp.top());
		temp.pop();
	}
}