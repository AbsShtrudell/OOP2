#pragma once
#include <stack>
#include <queue>
#include <vector>
#include <memory>
#include <optional>
#include "Item.h"
#include <functional>

class ItemList
{
private:
	std::function<bool(const std::shared_ptr<Item>& p1, const std::shared_ptr<Item>& p2)> func = [](const std::shared_ptr<Item>& p1, const std::shared_ptr<Item>& p2) { return p1->GetID() < p2->GetID(); };

	using Items = std::stack<std::shared_ptr<Item>, std::vector<std::shared_ptr<Item>>>;
	using SortedItems = std::priority_queue < std::shared_ptr<Item>, std::vector<std::shared_ptr<Item>>, decltype(func)>;

	Items items;
	SortedItems sortedItems;

public:

	ItemList();

	void Add(std::string_view name, std::string_view type, int amount);
	void Remove(int id);
	auto Get(int id)->std::optional<std::shared_ptr<Item>>;

	void ShowInConsole();
};


