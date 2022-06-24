#pragma once

class Item;
class ItemList;

void MainMenu();

void AddItemTask(ItemList& items);

void RemoveItemTask(ItemList& items);

void ChangeItemTask(ItemList& items);

void ShowItem(const Item& items);

