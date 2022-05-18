#pragma once
#include <map>
#include <list>
#include <functional>
#include <algorithm>
#include "Employee.h"

using namespace std;

class EmployeeManager
{
public:

	EmployeeManager();
	~EmployeeManager();

	void Add(float fee, string name, string surename);
	void Remove(int id);
	bool Contains(int id) const;
	void Sort(const function<bool(const shared_ptr<Employee>&, const shared_ptr<Employee>&)> criteria);
	void CalculateID(Employee& worker);

	auto begin()->list<shared_ptr<Employee>>::iterator;
	auto begin() const->list<shared_ptr<Employee>>::const_iterator;
	auto end()->list<shared_ptr<Employee>>::iterator;
	auto end() const->list<shared_ptr<Employee>>::const_iterator;

	auto operator[](int id)->shared_ptr<Employee>&;
	auto operator[](int id) const -> const shared_ptr<Employee>&;

	static bool ByIDAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool ByIDDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool ByNameAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool ByNameDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool BySureNameAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool BySureNameDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool ByFeeAscendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);
	static bool ByFeeDescendingly(const shared_ptr<Employee>& e1, const shared_ptr<Employee>& e2);

private:
	map<int, shared_ptr<Employee>> bankEmployees;
	list<shared_ptr<Employee>> sortedEmployees;
};

