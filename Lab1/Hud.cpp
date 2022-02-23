#include "Hud.h"

Hud::Hud()
{
}

Hud::~Hud()
{
}

void Hud::DrawRect(int color, string str)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(Console, &cbsi);

	SetConsoleTextAttribute(Console, color);

	cbsi.dwCursorPosition.X = 0;
	for (int j = 0; j < cbsi.dwMaximumWindowSize.X; j++) {
		cbsi.dwCursorPosition.X++;
		if (j < str.size()) cout << str[j];
		else cout << " ";
	}
	cbsi.dwCursorPosition.Y++;
	cout << endl;
	SetConsoleTextAttribute(Console, 7);
}
