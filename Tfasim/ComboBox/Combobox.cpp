#include "Combobox.h"



Combobox::Combobox()
{
	options = { "Option 1", "Option 2", "Option 3", "Option 4", "Option 5" };
	setCursor(100, FALSE);
	paint();

	while (counter++ < 10000)
	{
		if (!ReadConsoleInput(handleIN, irInBuf, 128, &cNumRead))

			fdwMode = ENABLE_WINDOW_INPUT;

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			default:
				break;
			}
		}
	}
	
}


Combobox::~Combobox()
{
}

void Combobox::mouseMove(int _row)
{
	if (printed == 0)
		return;
	for (int i = 0; i < 5; i++)
	{
		setPosition(9, 10 + i);
		if (i == _row - 10)
		{
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		}
		else
		{
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		row = _row - 10;
		cout << options[i];
	}
	setPosition(9, _row);
}

void Combobox::mouseClick(int _y)
{
	if (printed == 0)
		return;
	setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	setPosition(7, 6);
	cout << "You chose: " << options[row];
	showList();
}

void Combobox::showList()
{
	if (printed == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
				setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			else
				setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			setPosition(9, 10 + i);
			cout << options[i];
		}
		printed++;
		row = 0;
		setPosition(9, 10);
	}
	else
	{
		setColor(0);
		for (int j = 0; j < 5; j++)
		{
			setPosition(9, 10 + j);
			for (int a = 0; a < 13; a++)
			{
				setPosition(9 + a, 10 + j);
				cout << " ";
			}
		}
		printed--;
	}
}

void Combobox::paint()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (i == 1 && j == 10)
			{
				setPosition(22, 8);
				cout << "\x7C";
				setPosition(24, 8);
				cout << "\x56";
			}
			if (i == 0 || i == 2)
			{
				setPosition(7 + j, 7 + i);
				if (i == 0 && j == 0)
					cout << "\xDA";
				else if (i == 0 && j == 19)
					cout << "\xBF";
				else if (i == 2 && j == 0)
					cout << "\xC0";
				else if (i == 2 && j == 19)
					cout << "\xD9";
				else
					cout << "\xC4";
			}
			else
			{
				setPosition(7, 7 + i);
				cout << "\xB3";
				setPosition(26, 7 + i);
				cout << "\xB3";
			}
		}
	}
}

VOID Combobox::KeyEventProc(KEY_EVENT_RECORD ker)
{
	if (printed == 0)
		return;
	int x = 0, y = 0;
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		getPosition(x, y);
		if (y == 10)
			setPosition(9, 10);
		else
		{
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			setPosition(9, row + 10);
			cout << options[row];
			--row;
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			setPosition(9, row + 10);
			cout << options[row];
		}

	}
	else if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		getPosition(x, y);
		if (y == 14)
			setPosition(9, 14);
		else
		{
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			setPosition(9, row + 10);
			cout << options[row];
			++row;
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			setPosition(9, row + 10);
			cout << options[row];
		}
	}
	else if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		setPosition(7, 6);
		cout << "You chose: " << options[row];
		showList();
	}
	else if (ker.bKeyDown)
	{
		//Do nothing...
	}
}

VOID Combobox::MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mer.dwMousePosition.Y == 8 && mer.dwMousePosition.X > 22 && mer.dwMousePosition.X < 26)
			showList();
		else if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mer.dwMousePosition.Y > 9 && mer.dwMousePosition.X > 8 && mer.dwMousePosition.X < 17)
			mouseClick(mer.dwMousePosition.Y);
		break;
	case MOUSE_MOVED:
		if (mer.dwMousePosition.Y > 9 && mer.dwMousePosition.Y < 15 && mer.dwMousePosition.X > 8 && mer.dwMousePosition.X < 17)
		{
			mouseMove(mer.dwMousePosition.Y);
		}

		break;
	default:
		//Nothing...
		break;
	}
}