#include "Storage.h"

Storage::Storage()
{
	try
	{
		loadStorage("../Lab2/Storage.xml");
	}
	catch (const exception& ex)
	{
		ex.what();
	}
}

Storage::Storage(vector<Entity> entities)
{
	for (auto const& ent : entities)
	{
		addEntity(ent);
	}
}

Storage::Storage(Entity entity)
{
	addEntity(entity);
}

Storage::Storage(const Storage & storage)
{
	this->entities = storage.entities;
}

Storage::~Storage()
{
}

void Storage::loadStorage(string path)
{
	XMLDocument* doc = new XMLDocument();

	if (doc->LoadFile(path.c_str()) == XMLError::XML_SUCCESS)
	{
		Entity* ent;
		XMLElement* pRootElement = doc->RootElement();

		if (pRootElement != NULL)
		{
			XMLElement* pEntities = pRootElement->FirstChildElement("Entities");
			if (pEntities != NULL)
			{
				XMLElement* pEntity = pEntities->FirstChildElement("Entity");
				if (pEntity != NULL)
				{
					while (pEntity != NULL)
					{
						ent = new Entity();
						XMLElement* pId = pEntity->FirstChildElement("Id");
						ent->id = stoi(pId->GetText());
						XMLElement* pStore = pEntity->FirstChildElement("Store");
						ent->store = stoi(pStore->GetText());
						XMLElement* pName = pEntity->FirstChildElement("Name");
						ent->product.setName(pName->GetText());
						XMLElement* pPrice = pEntity->FirstChildElement("Price");
						ent->product.setPrice(stof(pPrice->GetText()));
						XMLElement* pType = pEntity->FirstChildElement("Type");
						ent->product.setType(Product::stringToType(pType->GetText()));
						XMLElement* pFeatures = pEntity->FirstChildElement("Features");
						if (pFeatures != NULL)
						{
							XMLElement* pFeature = pFeatures->FirstChildElement("Feature");
							if (pFeature != NULL)
							{
								while (pFeature != NULL)
								{
									XMLElement* pFName = pFeature->FirstChildElement("Name");

									if (pName != NULL)
									{
										XMLElement* pDescription = pFeature->FirstChildElement("Description");

										if (pDescription != NULL)
										{
											ent->product.addCharFeature({ pFName->GetText(), pDescription->GetText() });
										}
									}
									pFeature = pFeature->NextSiblingElement("Feature");
								}
							}
						}
						this->addEntity(*ent);
						pEntity = pEntity->NextSiblingElement("Entity");
						delete ent;
					}
				}
			}
		}
	}
	else throw(exception("WARNING!!! CAN'T LOAD STORAGE"));
}

const vector<Entity> Storage::getEntities() const
{
	return entities;
}

void Storage::addEntity(Entity ent)
{
	entities.push_back(ent);
}

bool Storage::removeEntityLast()
{
	if (entities.size() == 0) return false;

	entities.pop_back();
	return true;
}

bool Storage::removeEntityId(int id)
{
	for (int i = 0; i < entities.size();i++)
		if (entities.at(i).id == id)
		{
			entities.erase(entities.begin() + i);
			return true;
		}
	return false;
}

bool Storage::removeEntityIndex(vector<Entity>::iterator it)
{
	if (entities.size() == 0 || it > entities.end()) return false;

	entities.erase(it);
	return true;
}

bool Storage::editEntity(Entity ent, size_t index)
{
	if (entities.size() == 0 || index > entities.size()) return false;

	entities.at(index) = ent;
	return true;
}

bool Storage::isEntityAvaliable(size_t index) const
{
	if (entities.size() == 0 || index > entities.size()) return false;

	if (entities.at(index).store > 0) return true;
	else return false;
}

Entity Storage::findEnityId(int id) const
{
	for (auto entity : entities)
		if (entity.id == id) return entity;
	throw(exception("CAN'T FIND ENTITY WITH THIS ID"));
}

int Storage::findEnityIndex(int id) const
{
	for (int i = 0; i < entities.size(); i++)
		if (entities.at(i).id == id) return i;
	return -1;
}

Entity Storage::findEnityName(string name) const
{
	for (auto entity : entities)
		if (entity.product.getName() == name) return entity;
	throw(exception("CAN'T FIND ENTITY WITH THIS NAME"));
}

//void Storage::removeEntityStore(int id)
//{
//	Entity* ent = findEnityId(id);
//	if (ent->store >= 1) ent->store--;
//
//}

void Storage::setEntities(vector<Entity> ents)
{
	entities = ents;
}
