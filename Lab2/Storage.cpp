#include "Storage.h"

Storage::Storage()
{
	loadStorage("Storage.xml");
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
	XMLDocument doc;
	doc.LoadFile(path.c_str());
	Entity* ent;
	XMLElement* pRootElement = doc.RootElement();
	
	if (pRootElement != NULL)
	{
		XMLElement* pEntities = pRootElement->FirstChildElement("Entities");
		if (pEntities != NULL)
		{
			XMLElement* pEntity = pEntities->FirstChildElement("Entity");
			if (pEntity != NULL)
			{
				while (pEntity)
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
						XMLElement* pFeature = pEntity->FirstChildElement("Feature");
						if (pFeature != NULL)
						{
							while (pFeature)
							{
								XMLElement* pFName = pEntity->FirstChildElement("Name");

								XMLElement* pDescription = pEntity->FirstChildElement("Description");

								ent->product.getEditableCharacteristics().addFeture({ pFName->GetText(), pDescription->GetText() });
								pFeature = pFeatures->NextSiblingElement("Feature");
							}
						}
					}
					pEntity = pEntities->NextSiblingElement("Entity");
					delete ent;
				}
			}
		}
	}

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

Entity Storage::findEnity(int id)
{
	for (auto entity : entities)
		if (entity.id == id) return entity;
}

void Storage::setEntities(vector<Entity> ents)
{
	entities = ents;
}
