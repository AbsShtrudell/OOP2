#include "EmployeeManager.h"
#include <algorithm>

EmployeeManager::EmployeeManager()
{
}

EmployeeManager::~EmployeeManager()
{
}

void EmployeeManager::Add(float fee, string name, string surename)
{
	auto newEmployee = std::make_shared<Employee>(fee, name, surename);
	CalculateID(*newEmployee);

	bankEmployees[newEmployee->getID()] = newEmployee;
	sortedEmployees.push_back(newEmployee);
}

void EmployeeManager::Remove(int id)
{
	bankEmployees.erase(id);

	auto it = std::find_if(sortedEmployees.begin(), sortedEmployees.end(), [id](const std::shared_ptr<Employee>& e) { return e->getID() == id; });

	if (it != sortedEmployees.end())
		sortedEmployees.erase(it);
}

bool EmployeeManager::Contains(int id) const
{
	for (int i = 0; i < bankEmployees.size(); i++)
	{
		if (bankEmployees.at(i).get()->getID() == id)
			return true;
	}
	return false;
}

void EmployeeManager::Sort(const function<bool(const shared_ptr<Employee>&, const shared_ptr<Employee>&)> criteria)
{
	sort(sortedEmployees.begin(), sortedEmployees.end(), criteria);
}

void EmployeeManager::CalculateID(Employee& employee)
{
	if (bankEmployees.empty())
		return;

	auto it = bankEmployees.end();
	--it;

	employee.setID(it->first + 1);
}

auto EmployeeManager::begin() -> list<shared_ptr<Employee>>::iterator
{
	return sortedEmployees.begin();
}

auto EmployeeManager::begin() const -> list<shared_ptr<Employee>>::const_iterator
{
	return sortedEmployees.begin();
}

auto EmployeeManager::end() -> list<shared_ptr<Employee>>::iterator
{
	return sortedEmployees.end();
}

auto EmployeeManager::end() const -> list<shared_ptr<Employee>>::const_iterator
{
	return sortedEmployees.end();
}

auto EmployeeManager::operator[](int id) -> shared_ptr<Employee>&
{
	return bankEmployees[id];
}

auto EmployeeManager::operator[](int id) const -> const shared_ptr<Employee>&
{
	return bankEmployees.at(id);
}

static bool ByIDAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getID() < e2->getID();
}

static bool ByIDDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getID() > e2->getID();
}

static bool ByNameAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getName()[0] < e2->getName()[0];
}

static bool ByNameDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getName()[0] > e2->getName()[0];
}

static bool BySureNameAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getSurename()[0] < e2->getSurename()[0];
}

static bool BySureNameDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getSurename()[0] > e2->getSurename()[0];
}

static bool ByFeeAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getFee() < e2->getFee();
}

static bool ByFeeDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2)
{
	return e1->getFee() > e2->getFee();
}
