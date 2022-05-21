#include "Menus.h"
#include "ItemList.h"
#include "UserInput.h"

void MainMenu()
{
	ItemList items;
	int choice;

	items.Add("ÀÖÖ Ëîíã", "Ìóêîëèòè÷åñêîå ñðåäñòâî", 2);
	items.Add("Àíçèáåë", "Àíòèñåïòèê", 5);

	while (true)
	{
		INPUT
		(
			system("cls");
		std::cout
			<< "1. Ïîêàçàòü ëåêàðñòâà\n"
			<< "2. Äîáàâèòü ëåêàðñòâî\n"
			<< "3. Óäàëèòü ëåêàðñòâî\n"
			<< "4. Èçìåíèòü ëåêàðñòâî\n"
			<< "0. Âûõîä\n",
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

	std::cout << "Ââåäèòå íàçâàíèå: ";
	std::getline(std::cin, name);

	std::cout << "Ââåäèòå òèï: ";
	std::getline(std::cin, type);

	INPUT_CONDITION
	(
		std::cout << "Ââåäèòå êîëè÷åñòâî: ",
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
	std::cout << "Ââåäèòå ÈÄ ëåêàðñòâà: ",
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
	std::cout << "Ââåäèòå ÈÄ ëåêàðñòâà: ",
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
		ShowDrug(*item.value());
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

void ShowDrug(const Item& item)
{
	std::cout
		<< "ÈÄ: " << item.GetID() << std::endl
		<< "Íàçâàíèå: " << item.GetName() << std::endl
		<< "Òèï: " << item.GetType() << std::endl
		<< "Êîëè÷åñòâî: " << item.GetType() << std::endl << std::endl;
}
