#include "Label.h"

Label::Label()
{
}

Label::Label(string str) : Component()
{
	setPosition(15, 5);
	setCursor(100, FALSE);
	myString = str;
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

			default:
				break;
			}
		}
	}
}

Label::~Label()
{
}

void Label::paint()
{
	cout << myString;
}

VOID Label::KeyEventProc(KEY_EVENT_RECORD ker)
{
	if (ker.bKeyDown)
	{
		//Do nothing...
	}
}

VOID Label::MouseEventProc(MOUSE_EVENT_RECORD mer)
{

}