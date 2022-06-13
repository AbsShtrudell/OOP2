#include "Menus.h"
#include "ItemList.h"
#include "UserInput.h"

void MainMenu()
{
	ItemList items;
	int choice;

	items.Add("Вещь1", "тип", 2);
	items.Add("Вещь2", "тип", 5);

	while (true)
	{
		INPUT
		(
			system("cls");
		std::cout
			<< "1. Показать\n"
			<< "2. Добавить\n"
			<< "3. Убрать\n"
			<< "4. Изменить\n"
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
			AddItemTask(items);
			break;
		case 3:
			RemoveItemTask(items);
			break;
		case 4:
			ChangeItemTask(items);
			break;
		case 0:
			return;
		}
	}

}

void AddItemTask(ItemList& items)
{
	std::string name, type;
	int amount;

	std::cout << "Введите название: ";
	std::getline(std::cin, name);

	std::cout << "Введите тип: ";
	std::getline(std::cin, type);

	INPUT_CONDITION
	(
		std::cout << "Введите количество: ",
		amount,
		amount >= 0
	);

	items.Add(name, type, amount);
}

void RemoveItemTask(ItemList& items)
{
	int id;

	INPUT
	(
		system("cls");
	std::cout << "Введите ID предмета: ",
		id
		);

	items.Remove(id);
}

void ChangeItemTask(ItemList& items)
{
	int choice;

	INPUT
	(
		system("cls");
	std::cout << "Введите ID предмета: ",
		choice
		);

	auto item = items.Get(choice);

	if (!item.has_value())
	{
		std::cout << "Òàêîãî ëåêàðñòâà íåò\n";
		std::cin.get();
		return;
	}
	else while (true)
	{
		std::string temp;

		INPUT
		(
			system("cls");
		ShowItem(*item.value());
		std::cout
			<< "1. Èçìåíèòü íàçâàíèå\n"
			<< "2. Èçìåíèòü òèï\n"
			<< "3. Èçìåíèòü êîëè÷åñòâî\n"
			<< "0. Âûõîä\n",
			choice
			);

		system("cls");

		switch (choice)
		{
		case 1:
			std::cout << "Ââåäèòå íàçâàíèå: ";
			std::getline(std::cin, temp);

			item.value()->SetName(temp);

			break;
		case 2:
			std::cout << "Ââåäèòå òèï: ";
			std::getline(std::cin, temp);

			item.value()->SetType(temp);

			break;
		case 3:
			INPUT_CONDITION
			(
				system("cls");
			std::cout << "Ââåäèòå êîëè÷åñòâî: ",
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

void ShowItem(const Item& item)
{
	std::cout
		<< "ÈÄ: " << item.GetID() << std::endl
		<< "Íàçâàíèå: " << item.GetName() << std::endl
		<< "Òèï: " << item.GetType() << std::endl
		<< "Êîëè÷åñòâî: " << item.GetType() << std::endl << std::endl;
}
