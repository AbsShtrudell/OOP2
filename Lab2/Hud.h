#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class Hud
{
private:
	HANDLE HConsole;
public:
	Hud();
	~Hud();

	void drawRect(int color, string str);
	void fillStr();
	void setTextColor(int color);
};

