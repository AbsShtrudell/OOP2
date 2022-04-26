#include "Hud.h"

Hud::Hud()
{
	HConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Hud::~Hud()
{
}

void Hud::fillStr()
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(HConsole, &cbsi);
	for (int j = cbsi.dwCursorPosition.X; j < cbsi.dwMaximumWindowSize.X; j++) {
		cout << " ";
		cbsi.dwCursorPosition.X++;
	}
}

void Hud::setTextColor(int color)
{
	SetConsoleTextAttribute(HConsole, color);
}

void Hud::drawRect(int color, string str)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(HConsole, &cbsi);

	SetConsoleTextAttribute(HConsole, color);

	cbsi.dwCursorPosition.X = 0;
	for (int j = 0; j < cbsi.dwMaximumWindowSize.X; j++) {
		if (j < str.size()) cout << str[j];
		else cout << " ";
		cbsi.dwCursorPosition.X++;
	}
	cbsi.dwCursorPosition.Y++;
	cout << endl;
	SetConsoleTextAttribute(HConsole, 7);
}
