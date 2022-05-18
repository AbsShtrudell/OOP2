#include "UI.h"
#include <string>

void UI::Start(EmployeeManager& empl)
{
	int input;
	bool exit = false;
	while (!exit)
	{
		system("CLS");
		cout << "[A]ADD | [E]EDIT | [R]REMOVE | [V]SAVE | [S]SORT | [B]EXIT\n\n";

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
		case'S': case's':
			Sort(empl);
			break;
		case'B': case 'b':
			exit = true;
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
	system("CLS");
	string name;
	string surename;
	float fee;
	cout << "Enter Name: ";
	getline(cin, name);
	cin.clear();
	while (cin.get() != '\n');
	cout << "Enter Surename: ";
	getline(cin, surename);
	cin.clear();
	while (cin.get() != '\n');
	cout << "Enter Fee: ";
	cin >> fee;
	cin.clear();
	while (cin.get() != '\n');
	empl.Add(fee, name, surename);
}

void UI::Edit(EmployeeManager& empl, int id)
{
	int input;
	bool exit = false;
	string name;
	string surename;
	float fee;
	while (!exit)
	{
		system("CLS");
		cout << "[N]NAME | [S]SURENAME | [F]FEE | [B]BACK\n\n";

		cout << empl[id]->getName() << " " << empl[id]->getSurename() << " "
			<< empl[id]->getFee() << "$" << std::endl;

		input = _getch();
		switch (input)
		{
		case 'N': case'n':
			cin.clear();
			while (cin.get() != '\n');
			cout << "Enter Name: ";
			getline(cin, name);
			empl[id].get()->setName(name);
			cin.clear();
			while (cin.get() != '\n');
			break;
		case'S': case's':
			cin.clear();
			while (cin.get() != '\n');
			cout << "Enter Surename: ";
			getline(cin, surename);
			empl[id].get()->setSurename(surename);
			cin.clear();
			while (cin.get() != '\n');
			break;
		case'F': case'f':
			cin.clear();
			while (cin.get() != '\n');
			cout << "Enter Fee: ";
			cin >> fee;
			empl[id].get()->setFee(fee);
			cin.clear();
			while (cin.get() != '\n');
			break;
		case'B': case'b':
			exit = true;
			break;
		}
	}
}

void UI::Remove(EmployeeManager& empl, int id)
{
	empl.Remove(id);
}

void UI::Sort(EmployeeManager& empl)
{
	int input;
	bool exit = false;
	while (!exit)
	{
		system("CLS");
		cout << "[1]ID ASC | [2]ID DESC | [3]NAME ASC | [4]NAME DESC | [5]SURENAME ASC | [6]SURENAME DESC | [7]FEE ASC | [8]FEE DESC | [9]EXIT\n\n";

		Print(empl);

		input = _getch();
		switch (input)
		{
		case '1':
			empl.Sort(EmployeeManager::ByIDAscendingly);
			break;
		case'2':
			empl.Sort(EmployeeManager::ByIDDescendingly);
			break;
		case'3':
			empl.Sort(EmployeeManager::ByNameAscendingly);
			break;
		case'4':
			empl.Sort(EmployeeManager::ByNameDescendingly);
			break;
		case'5':
			empl.Sort(EmployeeManager::BySureNameAscendingly);
			break;
		case'6':
			empl.Sort(EmployeeManager::BySureNameDescendingly);
			break;
		case'7':
			empl.Sort(EmployeeManager::ByFeeAscendingly);
			break;
		case'8':
			empl.Sort(EmployeeManager::ByFeeDescendingly);
			break;
		case'9':
			exit = true;
			break;
		}
	}
}
