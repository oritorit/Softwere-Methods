#include "Textbox.h"



Textbox::Textbox()
{
	paint();
	while (counter++ <= 10000)
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


Textbox::~Textbox()
{
}

void Textbox::paint()
{
	setWattr(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	setColor(wAttr);
	setWattr(cbi.wAttributes | BACKGROUND_RED);
	setColor(wAttr);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (i == 0 || i == 2)
			{
				setPosition(7 + j, 7 + i);
				if (i == 0 && j == 0)
					cout << "\xC9";
				else if (i == 0 && j == 19)
					cout << "\xBB";
				else if (i == 2 && j == 0)
					cout << "\xC8";
				else if (i == 2 && j == 19)
					cout << "\xBC";
				else
					cout << "\xCD";
			}
			else
			{
				setPosition(7, 7 + i);
				cout << "\xBA";
				setPosition(26, 7 + i);
				cout << "\xBA";
			}
		}

	}
	setPosition(8, 8);
	setWattr(cbi.wAttributes &  ~(BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY));
	setColor(wAttr);
}

VOID Textbox::KeyEventProc(KEY_EVENT_RECORD ker)
{
	int x = 0, y = 0, a, b;
	if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		//nothing...
	}
	else if (GetAsyncKeyState(VK_BACK) != 0)
	{
		getPosition(x, y);
		a = x;
		b = y;
		if (x <= 8)
			setPosition(8, 8);
		else
		{
			cout << "\b" << " " << "\b";
			myString.erase(x - 9, 1);
			setPosition(8, 8);
			for (int j = 0; j < 18; j++)
			{
				setPosition(8 + j, 8);
				cout << " ";
			}
			setPosition(8, 8);
			cout << myString;
			setPosition(a - 1, b);
		}


	}
	else if (GetAsyncKeyState(VK_LEFT) != 0)
	{
		getPosition(x, y);
		if (x <= 8)
			setPosition(8, 8);
		else
			setPosition(--x, y);
	}
	else if (GetAsyncKeyState(VK_RIGHT) != 0)
	{
		getPosition(x, y);
		if (x >= 25)
			setPosition(25, 8);
		else
			setPosition(++x, y);
	}
	else if (ker.bKeyDown)
	{
		getPosition(x, y);
		if (x >= 26)
		{
			setPosition(25, 8);
			myString.pop_back();
		}
	
		myString += ker.uChar.AsciiChar;
		cout << ker.uChar.AsciiChar;
	}

}


VOID Textbox::MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mer.dwMousePosition.Y == 8 && mer.dwMousePosition.X > 7 && mer.dwMousePosition.X < 26)
		{
			setPosition(mer.dwMousePosition.X, 8);
		}
		break;
	default:
		//Nothing...
		break;
	}
}

