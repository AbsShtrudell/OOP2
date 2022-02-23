#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>

#include "String_s.h"
#include "ActivityLog.h"

using namespace std;

class TextEditor
{
private:
	string _str; //output string

public:
	TextEditor();
	TextEditor(string str);
	~TextEditor();

	string GetOutput();

	friend istream& operator>> (istream& s, TextEditor& textline);
};