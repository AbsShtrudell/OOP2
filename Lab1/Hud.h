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

	static void DrawRect(int color, string str);
	static void fillstr(HANDLE Console);
};

