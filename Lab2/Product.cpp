#include "Product.h"

Product::Characteristics::Characteristics()
{

}

Product::Characteristics::Characteristics(feature ft)
{
	addFeture(ft);
}

Product::Characteristics::Characteristics(vector<feature> fts)
{
	for (auto const& ft: fts)
	{
		addFeture(ft);
	}
}

Product::Characteristics::Characteristics(const Characteristics& ch)
{
	featuresList = ch.getFeaturesList();
}

Product::Characteristics::~Characteristics()
{
}

const vector<Product::Characteristics::feature> Product::Characteristics::getFeaturesList() const
{
	return featuresList;
}

void Product::Characteristics::addFeture(feature ft)
{
	featuresList.push_back(ft);
}

bool Product::Characteristics::removeFeatureLast()
{
	if (featuresList.size() == 0) return false;

	featuresList.pop_back();
	return true;
}

bool Product::Characteristics::removeFeatureIndex(vector<feature>::iterator ft_it)
{
	if (featuresList.size() == 0 || ft_it > featuresList.end()) return false;

	featuresList.erase(ft_it);
	return true;
}

bool Product::Characteristics::editFeature(feature ft, size_t index)
{
	if (featuresList.size() == 0 || index > featuresList.size()) return false;

	featuresList.at(index) = ft;
	return true;
}

Product::Product()
{
	price = -1.f;
	type = Type::None;
}

Product::Product(const Product& pr)
{
	this->price = pr.price;
	this->name = pr.name;
	this->ch = pr.ch;
	this->type = pr.type;
}

Product::~Product()
{
}

void Product::setPrice(float new_price)
{
	if (new_price >= 0.f) price = new_price;
}

void Product::setName(string new_name)
{
	name = new_name;
}

void Product::setCharacteristics(Characteristics new_ch)
{
	ch = new_ch;
}

void Product::setType(Type new_type)
{
	type = new_type;
}

const float Product::getPrice() const
{
	return price;
}

const string Product::getName() const
{
	return name;
}

 const Product::Characteristics Product::getCharacteristics() const
{
	return ch;
}

const Product::Type Product::getType() const
{
	return type;
}

Product::Type Product::stringToType(string str)
{
	Type tp;

	if (str == "Phone") tp = Type::Phone;
	else if (str == "TV") tp = Type::TV;
	else if (str == "Headphones") tp = Type::Headphones;
	else if (str == "Monitor") tp = Type::Monitor;
	else if (str == "Video_card") tp = Type::Video_card;
	else if (str == "Mother_board") tp = Type::Mother_board;
	else if (str == "Vacuum_cleaner") tp = Type::Vacuum_cleaner;
	else if (str == "Hairdryer") tp = Type::Hairdryer;
	else tp = Type::None;


	return tp;
}

string Product::typeToString(Product::Type tp)
{
	string str;
	if (tp == Type::Phone) str = "Phone";
	else if (tp == Type::TV) str = "TV";
	else if (tp == Type::Headphones) str = "Headphones";
	else if (tp == Type::Monitor) str = "Monitor";
	else if (tp == Type::Video_card) str = "Video_card";
	else if (tp == Type::Mother_board) str = "Mother_board";
	else if (tp == Type::Vacuum_cleaner) str = "Vacuum_cleaner";
	else if (tp == Type::Hairdryer) str = "Hairdryer";
	else str = "None";


	return str;
}

void Product::addCharFeature(Characteristics::feature ft)
{
	ch.addFeture(ft);
}

bool Product::removeCharFeatureLast()
{
	return ch.removeFeatureLast();
}

bool Product::removeCharFeatureIndex(vector<Characteristics::feature>::iterator ft_it)
{
	return ch.removeFeatureIndex(ft_it);
}

bool Product::editCharFeature(Characteristics::feature ft, size_t index)
{
	return ch.editFeature(ft, index);
}
