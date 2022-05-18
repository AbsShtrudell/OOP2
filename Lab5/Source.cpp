#include "UI.h"

int main()
{
	EmployeeManager emp;
	emp.Add(10, "Jakob", "Jakobich");
	emp.Add(15, "Alexei", "Abramovich");
	emp.Add(14, "Kirill", "Uspenski");
	emp.Add(9, "Albert", "Inshtain");
	UI ui;
	ui.Start(emp);
}