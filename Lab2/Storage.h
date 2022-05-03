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
	void saveStorage(string path);

	const vector<Entity> getEntities() const;
	void setEntities(vector<Entity> ents);
	void addEntity(Entity ent);
	bool removeEntityLast();
	bool removeEntityId(int id);
	bool removeEntityIndex(vector<Entity>::iterator it);
	bool editEntity(Entity ent, size_t index);
	Entity findEnityId(int id) const;
	Entity findEnityName(string name) const;
	int findEnitysIndex(int id) const;

private:
	vector<Entity> entities;
};

class StorageException : public exception 
{
public:
	StorageException(char* str) : exception(str){}
private:
};

