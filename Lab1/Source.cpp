#include <iostream>
#include <conio.h>
#include "FileManagerStream.h"
#include "TextEditor.h"
#include "Hud.h"

using namespace std;

void EditFile();

int main() 
{
	char input;
	bool exit = false;
	
	while (!exit) 
	{
		system("CLS");
		Hud hud;
		hud.DrawRect(121, "[1]EDIT FILE  [2]EXIT");
		input = _getch();
		switch (input) 
		{
		case '1':
			EditFile();
			break;
		case '2':
			exit = true;
		}
	}
}

void EditFile() 
{
	string path;
	cout << "ENTER FILE PATH: \n";
	getline(cin, path);

	system("CLS");

	Hud hud;
	for (auto& c : path) c = toupper(c);
	hud.DrawRect(121, "[^Q]EXITE  [^Z]UNDO  [^X]REDO  OPENED FILE: " + path);

	FileManagerStream fm(path);
	TextEditor txtedit(fm.Read());
	cin >> txtedit;

	fm.Write(txtedit.GetOutput());
	cout << "[^Q] CLOSE FILE. ALL DATA SAVED\nPRESS ANY BUTTON TO CONTINUE...";
	_getch();
}