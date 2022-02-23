#include "String_s.h"

String_s::String_s()
{
	begin = new stack;
	end = new stack;
	cursor = new stack;

	begin->symbol = ' ';
	begin->back = nullptr;
	begin->next = end;

	end->back = begin;
	end->next = NULL;
	end->symbol = '\0';

	cursor = begin;
}

String_s::String_s(const char* str)
{
	begin = new stack;
	end = new stack;
	cursor = new stack;

	begin->symbol = ' ';
	begin->back = nullptr;
	begin->next = end;

	end->back = begin;
	end->next = NULL;
	end->symbol = '\0';

	cursor = begin;

	for (int i = 0; str[i] != '\0'; i++) AddSymbol_c(str[i]);
}

String_s::String_s(String_s& str)
{
	begin = new stack;
	end = new stack;
	cursor = new stack;

	begin->symbol = ' ';
	begin->back = nullptr;
	begin->next = end;

	end->back = begin;
	end->next = NULL;
	end->symbol = '\0';

	cursor = begin;

	stack* buf = str.begin;

	while (buf->next->symbol != '\0')
	{
		AddSymbol_c(buf->symbol);
		buf = buf->next;
	}

	int counter = 0;
	buf = str.cursor;
	while (str.MoveCursor(1))counter--;
	MoveCursor(counter);
	str.cursor = buf;
}

String_s::~String_s()
{
	stack* buf;
	cursor = begin;
	
	while (cursor != NULL)
	{
		buf = cursor;
		cursor = cursor->next;
		delete buf;
	}
}

String_s::stack* String_s::getCursor() const
{
	return cursor;
}

String_s::stack* String_s::getBegin() const
{
	return begin;
}

String_s::stack* String_s::getEnd() const
{
	return end;
}

String_s::stack* String_s::CreateElement(char symbol)
{
	stack* newelem = new stack;
	newelem->back = nullptr;
	newelem->next = nullptr;
	newelem->symbol = symbol;

	return newelem;
}

void String_s::AddSymbol_c(char symbol)
{
	stack* newelem = CreateElement(symbol);
	newelem->back = cursor->back;
	newelem->next = cursor;
	cursor->back = newelem;
	if (newelem->back != NULL) newelem->back->next = newelem;
	else begin = newelem;
	return;
}

void String_s::AddSymbol_b(char symbol)
{
	stack* newelem = CreateElement(symbol);
	newelem->back = NULL;
	newelem->next = begin;
	begin->back = newelem;
	if (cursor == begin) cursor = newelem;
	begin = newelem;
	return;
}

void String_s::AddSymbol_e(char symbol)
{
	stack* newelem = CreateElement(symbol);
	newelem->back = end->back;
	newelem->next = end;
	end->back = newelem;
	return;
}

void String_s::RemoveSymbol_c()
{
	if (cursor->back == NULL) return;

	stack* buf = cursor->back;

	cursor->back = buf->back;
	if(buf->back != NULL) buf->back->next = cursor;
	else begin = cursor;

	buf->back = NULL;
	buf->next = NULL;

	delete buf;

	return;
}

void String_s::RemoveSymbol_b()
{
	if (begin->next == end) return;

	stack* buf = nullptr;

	begin->next->back = NULL;
	buf = begin->next;

	if (cursor == begin) cursor = buf;

	begin->next = NULL;

	delete begin;

	begin = buf;

	return;
}

void String_s::RemoveSymbol_e()
{
	if (end->back == begin) return;

	stack* buf = end->back->back;

	end->back->back = buf->back;
	if(buf->back != NULL) buf->back->next = end->back;

	if (cursor == buf)
	{
		if (buf->back == NULL)
		{
			cursor = end->back;
			begin = cursor;
		}
		else cursor = buf->back;
	}

	buf->back = NULL;
	buf->next = NULL;

	delete buf;

	return;
}

int String_s::MoveCursor(int steps)
{
	int finalsteps = 0;
	if (steps == 0) return finalsteps;
	if(steps < 0)
		for (int i = steps; i != 0; i++)
		{
			if (cursor->back != NULL)
			{
				cursor = cursor->back;
				finalsteps--;
			}
			else return finalsteps;
		}
	else 
		for (int i = steps; i != 0; i--)
		{
			if (cursor->next->symbol != '\0')
			{
				cursor = cursor->next;
				finalsteps++;
			}
			else return finalsteps;
		}
	return finalsteps;
}

bool String_s::isEnd()
{
	if (cursor->next == end) return true;
	else return false;
}

string String_s::ToString()
{
	string output;
	stack* buf = cursor;
	cursor = begin;
	while (!isEnd())
	{
		output += cursor->symbol;
		MoveCursor(1);
	}
	cursor = buf;
	return output;
}

ostream& operator<<(ostream& out, const String_s& str)
{
	String_s::stack* buf = str.begin;
	while (buf->symbol != '\0')
	{
		out << buf->symbol;
		buf = buf->next;
	}
	return out;
}
