#include "TextEditor.h"
void MoveConsoleCursor(int steps)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(Console, &cbsi);

	if (steps < 0)
	{
		for (int i = steps; i != 0; i++)
		{
			if (cbsi.dwCursorPosition.X - 1 < 0)
			{
				cbsi.dwCursorPosition.Y--;
				cbsi.dwCursorPosition.X = cbsi.dwSize.X - 1;
			}
			else cbsi.dwCursorPosition.X--;
		}
	}
	else
	{
		for (int i = steps; i != 0; i--)
		{
			if (cbsi.dwCursorPosition.X + 1 > cbsi.dwSize.X - 1)
			{
				cbsi.dwCursorPosition.Y++;
				cbsi.dwCursorPosition.X = 0;
			}
			else cbsi.dwCursorPosition.X++;
		}
	}

	SetConsoleCursorPosition(Console, { cbsi.dwCursorPosition.X , cbsi.dwCursorPosition.Y });
}

void MoveString(String_s str)							//Moves printed string to the right
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(Console, &cbsi);

	while (!str.isEnd())
	{
		cout << str.getCursor()->symbol;
		str.MoveCursor(1);
	}

	SetConsoleCursorPosition(Console, cbsi.dwCursorPosition);
}

void ClearLastCharacter(String_s str)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(Console, &cbsi);

	int counter = 0;
	while (str.MoveCursor(1)) counter++;

	MoveConsoleCursor(counter - 1);
	cout << ' ';

	SetConsoleCursorPosition(Console, cbsi.dwCursorPosition);
}

istream& operator>>(istream& in, TextEditor& textline)
{
	cout << textline._str;
	String_s str(textline._str.c_str());
	ActivityLog log;

	int input, ex, steps;

	while (true)
	{
		if (_kbhit()) //Chek if was input
		{
			input = _getch();

			if (input && input != 224) //chek for special symbols
			{
				switch (input)
				{
				case 9:							//TAB
					break;
				case 8:							//Backspace
					ClearLastCharacter(str);
					if(str.getCursor()->back != NULL)log.AddActivity({ BackSpace, str.getCursor()->back->symbol});
					str.RemoveSymbol_c();
					cout << '\b';
					MoveString(str);
					break;
				case 13:						//Enter
					/*cout << '\n';
					str.AddSymbol_c('\n');
					break;*/
					break;
				case 17:						//Ctrl+Q
					cout << endl;
					textline._str = str.ToString();
					return in;
				case 24:						//Ctrl+X
					if (!log.isUndoEmpty())
					{
						Activity act = log.GetLastUndoActivity();
						while (act.type != Print && act.type != BackSpace && !log.isUndoEmpty())
						{
							steps = str.MoveCursor(act.value);
							MoveConsoleCursor(steps);
							act = log.GetLastActivity();
						}
						if (act.type == Print)
						{
							cout << (char)act.value;
							MoveString(str);
							str.AddSymbol_c(act.value);	
						}
						else
						{
							ClearLastCharacter(str);
							str.RemoveSymbol_c();
							cout << '\b';
							MoveString(str);
						}
					}
					break;
				case 26:						//Ctrl+Z
					if (!log.isEmpty())
					{
						Activity act = log.GetLastActivity();
						while (act.type != Print && act.type != BackSpace && !log.isEmpty())
						{
							steps = str.MoveCursor(-1 * act.value);
							MoveConsoleCursor(steps);
							act = log.GetLastActivity();
						}
						if (act.type == Print)
						{
							ClearLastCharacter(str);
							str.RemoveSymbol_c();
							cout << '\b';
							MoveString(str);
						}
						else
						{
							cout << (char)act.value;
							MoveString(str);
							str.AddSymbol_c(act.value);
						}
					}
					break;
				default:
					cout << (char)input;
					log.AddActivity({ Print, input });
					MoveString(str);
					str.AddSymbol_c(input);
					break;
				}
			}
			else
			{
				switch (ex = _getch())
				{
				case 75:										//left arrow
					steps = str.MoveCursor(-1);
					log.AddActivity({ MoveCursor, steps });
					MoveConsoleCursor(steps);

					break;
				case 77:										//right arrow
					steps = str.MoveCursor(1);
					log.AddActivity({ MoveCursor, steps });
					MoveConsoleCursor(steps);
					break;
				}
			}
		}
	}
	return in;
}

TextEditor::TextEditor()
{
}

TextEditor::TextEditor(string str)
{
	_str = str;
}

TextEditor::~TextEditor()
{
}

string TextEditor::GetOutput()
{
	return _str;
}
