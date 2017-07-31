#include "Radiolist.h"



Radiolist::Radiolist()
{
	options = { "( ) option 1", "( ) option 2", "( ) option 3", "( ) option 4", "( ) option 5" };
	paint();
	while (counter++ <= 10000)
	{
		// Wait for the events. 

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


Radiolist::~Radiolist()
{
}

void Radiolist::clearAll()
{
	for (int i = 0; i < 5; i++)
	{
		chosen[i] = 0;
		setPosition(8, i + 7);
		cout << " ";
	}
}

void Radiolist::mouseMove(int _row)
{
	for (int i = 0; i < 5; i++)
	{
		setPosition(7, 7 + i);
		if (i == _row - 7)
		{
			setWattr(FOREGROUND_GREEN);
			setColor(wAttr);
		}
		else
		{
			setWattr(FOREGROUND_RED);
			setColor(wAttr);
		}
		row = _row - 7;
		cout << options[i];
		if (chosen[i] == 1) {
			setPosition(8, 7 + i);
			cout << "o";
		}
	}
	setPosition(7, _row);
}

void Radiolist::mouseClick(int _y)
{
	if (chosen[_y - 7] == 0) {
		clearAll();
		setPosition(8, _y);
		cout << "o";
		chosen[_y - 7]++;
	}
	else {
		setPosition(8, _y);
		cout << " ";
		chosen[_y - 7]--;
	}
}

void Radiolist::paint()
{
	for (int i = 0; i < options.size(); i++)
	{
		setPosition(7, i + 7);
		setCursor(100, FALSE);
		if (i == 0)
			setColor(FOREGROUND_GREEN);
		else
			setColor(FOREGROUND_RED);
		cout << options[i];
		setPosition(7, 7);

	}
}

VOID Radiolist::KeyEventProc(KEY_EVENT_RECORD ker)
{
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		getPosition(x, y);
		if (y <= 7)
			setPosition(7, 7);
		else
		{
			setColor(FOREGROUND_RED);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "o";
			}
			--row;
			setColor(FOREGROUND_GREEN);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "o";
			}
		}

	}
	else if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		getPosition(x, y);
		if (y >= 11)
			setPosition(7, 11);
		else
		{
			setColor(FOREGROUND_RED);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "o";
			}
			++row;
			setColor(FOREGROUND_GREEN);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "o";
			}
		}
	}
	else if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		if (chosen[row] == 0) {
			clearAll();
			setPosition(8, row + 7);
			cout << "o";
			chosen[row]++;
		}
		else {
			setPosition(8, row + 7);
			cout << " ";
			chosen[row]--;
		}

	}
	else if (ker.bKeyDown)
	{
		//Do nothing...
	}
}

VOID Radiolist::MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mer.dwMousePosition.Y > 6 && mer.dwMousePosition.Y < 12 && mer.dwMousePosition.X > 6 && mer.dwMousePosition.X < 19)
		{
			mouseClick(mer.dwMousePosition.Y);
		}
		break;
	case MOUSE_MOVED:
		if (mer.dwMousePosition.Y > 6 && mer.dwMousePosition.Y < 12 && mer.dwMousePosition.X > 6 && mer.dwMousePosition.X < 19)
		{
			mouseMove(mer.dwMousePosition.Y);
		}

		break;
	default:
		//Nothing...
		break;
	}
}

