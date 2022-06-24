#include "Menus.h"
#include "ItemList.h"
#include "UserInput.h"

void MainMenu()
{
	ItemList items;
	int choice;

	items.Add("GTX 1660", "Видеокарта", 2);
	items.Add("Philips 19", "Монитор", 5);

	while (true)
	{
		INPUT
		(
			system("cls");
		std::cout
			<< "1. Показать\n"
			<< "2. Добавить\n"
			<< "3. Удалить\n"
			<< "4. Редактировать\n"
			<< "0. Выход\n",
			choice
			);

		system("cls");

		switch (choice)
		{
		case 1:
			items.ShowInConsole();
			std::cin.get();
			break;
		case 2:
			AddDrugTask(items);
			break;
		case 3:
			RemoveDrugTask(items);
			break;
		case 4:
			ChangeDrugTask(items);
			break;
		case 0:
			return;
		}
	}

}

void AddDrugTask(ItemList& items)
{
	std::string name, type;
	int amount;

	std::cout << "Введите название: ";
	std::getline(std::cin, name);

	std::cout << "Введите тип: ";
	std::getline(std::cin, type);

	INPUT_CONDITION
	(
		std::cout << "Введите кол-во: ",
		amount,
		amount >= 0
	);

	items.Add(name, type, amount);
}

void RemoveDrugTask(ItemList& items)
{
	int id;

	INPUT
	(
		system("cls");
	std::cout << "Введите ид: ",
		id
		);

	items.Remove(id);
}

void ChangeDrugTask(ItemList& items)
{
	int choice;

	INPUT
	(
		system("cls");
	std::cout << "Введите ид: ",
		choice
		);

	auto item = items.Get(choice);

	if (!item.has_value())
	{
		std::cout << "Ошибка\n";
		std::cin.get();
		return;
	}
	else while (true)
	{
		std::string temp;

		INPUT
		(
			system("cls");
		ShowDrug(*item.value());
		std::cout
			<< "1. Название\n"
			<< "2. Тип\n"
			<< "3. Кол-во\n"
			<< "0. Выход\n",
			choice
			);

		system("cls");

		switch (choice)
		{
		case 1:
			std::cout << "Введите название: ";
			std::getline(std::cin, temp);

			item.value()->SetName(temp);

			break;
		case 2:
			std::cout << "Введите тип: ";
			std::getline(std::cin, temp);

			item.value()->SetType(temp);

			break;
		case 3:
			INPUT_CONDITION
			(
				system("cls");
			std::cout << "Введите кол-во: ",
				choice,
				choice >= 0
				);

			item.value()->SetAmount(choice);

			break;
		case 0:
			return;
		}
	}
}

void ShowDrug(const Item& item)
{
	std::cout
		<< "ид: " << item.GetID() << std::endl
		<< "название: " << item.GetName() << std::endl
		<< "тип: " << item.GetType() << std::endl
		<< "кол-во: " << item.GetType() << std::endl << std::endl;
}
