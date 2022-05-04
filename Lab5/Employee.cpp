#include "Employee.h"

Employee::Employee(float fee, std::string name, std::string surename)
{
	_fee = fee;
	_name = name;
	_surename = surename;
}

Employee::~Employee()
{
}

int Employee::getID() const
{
	return _id;
}

std::string Employee::getName() const
{
	return _name;
}

std::string Employee::getSurename() const
{
	return _surename;
}

float Employee::getFee() const
{
	return _fee;
}

void Employee::setID(int id)
{
	_id = id;
}

void Employee::setName(std::string name)
{
	_name = name;
}

void Employee::setSurename(std::string surename)
{
	_surename = surename;
}

void Employee::setFee(float fee)
{
	_fee = fee;
}
