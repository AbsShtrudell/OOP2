#pragma once

class Item;
class ItemList;

void MainMenu();

void AddDrugTask(ItemList& items);

void RemoveDrugTask(ItemList& items);

void ChangeDrugTask(ItemList& items);

void ShowDrug(const Item& items);

