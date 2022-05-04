#pragma once
#include <iostream>

class Employee
{
public:

	Employee(float fee, std::string name, std::string surename);
	~Employee();

	int getID() const;
	std::string getName() const;
	std::string getSurename() const;
	float getFee() const;

	void setID(int id);
	void setName(std::string name);
	void setSurename(std::string surename);
	void setFee(float fee);

private:
	
	int _id;
	std::string _name;
	std::string _surename;
	float _fee;
};

