#pragma once
#include <string>
#include "SmartPointer.h"

using namespace std;

class FileManager
{
private:
	string _path;
public:

	virtual ~FileManager() {};

	virtual string GetPath() { return _path; }
	virtual void SetPath(string path) { _path = path; }

	virtual string Read() = 0;
	virtual void Write(string text) = 0;
};

