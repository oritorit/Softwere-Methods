#include "Component.h"



Component::Component()
{
	SetConsoleMode(handleIN, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
}


Component::~Component()
{
}

void Component::setWattr(DWORD _word)
{
	wAttr = _word;
}

void Component::getPosition(int &x, int &y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(handleOUT, &csbi)) {
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;
	}
}

void Component::setCursor(DWORD size, bool b)
{
	cci = { size, b };
	SetConsoleCursorInfo(handleOUT, &cci);
}

void Component::setColor(int _color)
{
	SetConsoleTextAttribute(handleOUT, _color);
	GetConsoleScreenBufferInfo(handleOUT, &cbi);
}

void Component::setPosition(SHORT _x, SHORT _y)
{
	COORD cord = { _x, _y };
	SetConsoleCursorPosition(handleOUT, cord);
}