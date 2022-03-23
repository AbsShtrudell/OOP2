#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include "tinyxml2.h"
#include "Entity.h"

using namespace std;
using namespace tinyxml2;
class Storage
{
public:
	Storage();
	Storage(vector<Entity> entities);
	Storage(Entity entity);
	Storage(const Storage & storage);
	~Storage();

	void loadStorage(string path);

	const vector<Entity> getEntities() const;
	void setEntities(vector<Entity> ents);
	void addEntity(Entity ent);
	bool removeEntityLast();
	bool removeEntityIndex(vector<Entity>::iterator it);
	bool editEntity(Entity ent, size_t index);
	bool isEntityAvaliable(size_t index) const;
	Entity findEnityId(int id) const;
	Entity findEnityName(string name) const;

	//void removeEntityStore(int id);

private:
	vector<Entity> entities;
};

class StorageException : exception {};

