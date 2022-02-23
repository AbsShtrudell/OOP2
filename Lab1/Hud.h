#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class Hud
{
private:
	HANDLE hConsole;
public:
	Hud();
	~Hud();

	void DrawRect(int color, string str);
};

