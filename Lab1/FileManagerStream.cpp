#include "FileManagerStream.h"

FileManagerStream::FileManagerStream()
{
}

FileManagerStream::FileManagerStream(string path)
{
	SetPath(path);
}

FileManagerStream::~FileManagerStream()
{
}

string FileManagerStream::Read()
{
	ifstream file;
	string str;
	file.open(GetPath());

	if (!file)
	{
		ofstream newfile;
		newfile.open(GetPath());
		str = "\0";
		newfile.close();
		return str;
	}

	file >> str;

	file.close();

	return str;
}

void FileManagerStream::Write(string text)
{
	ofstream file(GetPath(), ios_base::trunc);

	file << text;

	file.close();
}
