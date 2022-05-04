#include "UI.h"
#include "EmployeeManager.h"


void UI::Start(EmployeeManager& empl)
{
	int input;
	bool exit = false;
	while (!exit)
	{
		cout << "[A]ADD | [E]EDIT | [R]REMOVE | [V]SAVE\n\n";

		Print(empl);

		input = _getch();
		switch (input)
		{
		case 'A': case'a':
			Add(empl);
			break;
		case'E': case'e':
			cout << "\nEnter ID: ";
			cin >> input;
			Edit(empl, input);
			break;
		case'R': case'r':
			cout << "\nEnter ID: ";
			cin >> input;
			Remove(empl, input);
			break;
		case'V': case'v':
			Save(empl);
			break;
		}
	}
}

void UI::Save(EmployeeManager& empl)
{
	ofstream file;
	file.open("test.txt");

	for (const auto& e : empl)
	{
		file << e->getID() << " " << e->getName() << " " << e->getSurename() << " "
			<< e->getFee() << std::endl;
	}

	file.close();
}

void UI::Print(EmployeeManager& empl)
{
	for (const auto& e : empl)
	{
		cout << e->getID() << ". " << e->getName() << " " << e->getSurename() << " "
			<< e->getFee() << "$" << std::endl;
	}
}

void UI::Add(EmployeeManager& empl)
{
}

void UI::Edit(EmployeeManager& empl, int id)
{
}

void UI::Remove(EmployeeManager& empl, int id)
{
}
