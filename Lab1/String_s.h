#pragma once

#include <iostream>
#include <string.h>

using namespace std;



class String_s
{
	struct stack
	{
		stack* back, * next;
		char symbol;
	};
private:
	stack *begin, *end, *cursor;

	stack* CreateElement(char symbol);
public:

	String_s();
	String_s(const char* str);
	String_s(String_s& str);
	~String_s();

	stack* getCursor() const;
	stack* getBegin() const;
	stack* getEnd() const;

	void AddSymbol_c(char symbol); //Adds symbol to the cursor position, but keeps cursor on the same character
	void AddSymbol_b(char symbol); //Adds symbol to the star position, and makes it new begining
	void AddSymbol_e(char symbol); //Adds symbol per end->back(' ''\0') position
	void RemoveSymbol_c();
	void RemoveSymbol_b();
	void RemoveSymbol_e();

	int MoveCursor(int steps);
	bool isEnd();

	string ToString();
	
	friend ostream& operator << (ostream& out, const String_s& str); 
};

