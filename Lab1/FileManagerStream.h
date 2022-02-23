#pragma once
#include <fstream>
#include "FileManager.h"
class FileManagerStream : public FileManager
{
public:
	FileManagerStream();
	FileManagerStream(string path);
	~FileManagerStream();
	
	string Read();
	void Write(string text);
};

