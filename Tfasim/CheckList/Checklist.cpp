#include "Checklist.h"



Checklist::Checklist()
{
	options = { "[ ] option 1", "[ ] option 2", "[ ] option 3", "[ ] option 4", "[ ] option 5" };
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


Checklist::~Checklist()
{
}

void Checklist::paint()
{
	for (int i = 0; i < options.size(); i++)
	{
		setPosition(7, i + 7);
		setCursor(100, FALSE);
		
		if (i == 0)
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		else
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << options[i];
		setPosition(7, 7);
	}
}



VOID Checklist::KeyEventProc(KEY_EVENT_RECORD ker)
{
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		getPosition(x, y);
		if (y <= 7)
			setPosition(7, 7);
		else
		{
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "#";
			}
			--row;
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "#";
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
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "#";
			}
			++row;
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			setPosition(7, row + 7);
			cout << options[row];
			if (chosen[row] == 1) {
				setPosition(8, row + 7);
				cout << "#";
			}
		}
	}
	else if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		if (chosen[row] == 0) {
			setPosition(8, row + 7);
			cout << "#";
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

VOID Checklist::MouseEventProc(MOUSE_EVENT_RECORD mer)
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

void Checklist::mouseMove(int _row)
{
	for (int i = 0; i < 5; i++)
	{
		setPosition(7, 7 + i);
		if (i == _row - 7)
		{
			setColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		}
		else
		{
			setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		row = _row - 7;
		cout << options[i];
		if (chosen[i] == 1) {
			setPosition(8, 7 + i);
			cout << "#";
		}
	}
	setPosition(7, _row);
}

void Checklist:: mouseClick(int _y)
{
	if (chosen[_y - 7] == 0) {
		setPosition(8, _y);
		cout << "#";
		chosen[_y - 7]++;
	}
	else {
		setPosition(8, _y);
		cout << " ";
		chosen[_y - 7]--;
	}
}