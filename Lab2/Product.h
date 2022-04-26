#pragma once

#include <string>
#include <vector>

using namespace std;

class Product
{
public:
	enum class Type
	{
		None,
		Phone,
		TV,
		Headphones,
		Monitor,
		Video_card,
		Mother_board,
		Vacuum_cleaner,
		Hairdryer
	};

	class Characteristics
	{
	public:
		struct feature;

		Characteristics();
		Characteristics(feature ft);
		Characteristics(vector<feature> fts);
		Characteristics(const Characteristics& ch);
		~Characteristics();

		const vector<feature> getFeaturesList() const;
		void addFeture(feature ft);
		bool removeFeatureLast();
		bool removeFeatureIndex(vector<feature>::iterator ft_it);
		bool editFeature(feature ft, size_t index);

	private:
		vector<feature> featuresList;

	public:
		struct feature
		{
			string name;
			string description;
		};
	};

	Product();
	Product(const Product& pr);
	~Product();

	void setPrice(float new_price);
	void setName(string new_name);
	void setCharacteristics(Characteristics new_ch);
	void setType(Type new_type);

	const float getPrice() const;
	const string getName() const;
	const Characteristics getCharacteristics() const;
	const Type getType() const;

	static Type stringToType(string str);
	static string typeToString(Type tp);

	void addCharFeature(Characteristics::feature ft);
	bool removeCharFeatureLast();
	bool removeCharFeatureIndex(vector<Characteristics::feature>::iterator ft_it);
	bool editCharFeature(Characteristics::feature ft, size_t index);

private:
	float price;
	string name;
	Characteristics ch;
	Type type;
};

