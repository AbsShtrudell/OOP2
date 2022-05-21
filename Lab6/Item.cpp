#include "Item.h"

Item::Item()
{
}

Item::Item(std::string_view name, std::string_view type, int amount)
	: id(0), name(name), type(type), amount(amount)
{
}

Item::Item(const Item& other) : id(other.id), name(other.name), type(other.type), amount(other.amount)
{
}

auto Item::GetID() const -> int
{
	return id;
}

auto Item::GetName() const -> std::string_view
{
	return name;
}

auto Item::GetType() const -> std::string_view
{
	return type;
}

auto Item::GetAmount() const -> int
{
	return amount;
}

void Item::SetID(int newID)
{
	id = newID;
}

void Item::SetName(std::string_view newName)
{
	name = newName;
}

void Item::SetType(std::string_view newType)
{
	type = newType;
}

void Item::SetAmount(int newAmount)
{
	amount = newAmount;
}