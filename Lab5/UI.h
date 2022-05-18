#pragma once
#include <conio.h>
#include <fstream>
#include "EmployeeManager.h"

class UI
{
public:

	void Start(class EmployeeManager& empl);
	void Save(class EmployeeManager& empl);
	void Print(class EmployeeManager& empl);
	void Add(class EmployeeManager& empl);
	void Edit(class EmployeeManager& empl, int id);
	void Remove(class EmployeeManager& empl, int id);
	void Sort(EmployeeManager& empl);
};

