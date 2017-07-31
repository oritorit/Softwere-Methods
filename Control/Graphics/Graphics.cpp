#include "Graphics.h"

Graphics::Graphics(DWORD stdHandle)
	: _console(GetStdHandle(stdHandle)), _background(BackgroundColor::Black), _foreground(ForegroundColor::White)
{
	updateConsoleAttributes();
}

void Graphics::clearScreen()
{
	DWORD d;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(_console, &csbi);
	auto size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputAttribute(_console, csbi.wAttributes, size, { 0, 0 }, &d);
	FillConsoleOutputCharacter(_console, L' ', size, { 0, 0 }, &d);
}

void Graphics::resetColor()
{
	_foreground = ForegroundColor::White;
	_background = BackgroundColor::Black;
	updateConsoleAttributes();
}

void Graphics::moveTo(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(_console, c);
}

void Graphics::getPosition(COORD & c)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(_console, &csbi)) {
		c.X = csbi.dwCursorPosition.X;
		c.Y = csbi.dwCursorPosition.Y;
	}
}

void Graphics::setBackground(BackgroundColor color)
{
	_background = color;
	updateConsoleAttributes();
}

void Graphics::setForeground(ForegroundColor color)
{
	_foreground = color;
	updateConsoleAttributes();
}

void Graphics::write(string s)
{
	WriteConsoleA(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(wstring s)
{
	WriteConsoleW(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(int x, int y, string s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::write(int x, int y, wstring s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::setCursorVisibility(bool isVisible)
{
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(_console, &cci);
	cci.bVisible = isVisible;
	SetConsoleCursorInfo(_console, &cci);
}

BackgroundColor Graphics::getBackground()
{
	return _background;
}

ForegroundColor Graphics::getForground()
{
	return _foreground;
}

void Graphics::inverseAtt()
{
	ForegroundColor tmpFor = getForground();
	BackgroundColor tmpBack = getBackground();
	setForeground(convertToColorFor(tmpBack));
	setBackground(convertToColorBack(tmpFor));
}

BackgroundColor Graphics::convertToColorBack(ForegroundColor forColor)
{
	BackgroundColor color = BackgroundColor::White;
	switch (forColor)
	{
	case ForegroundColor::Black:	color = BackgroundColor::Black; break;
	case ForegroundColor::Blue:		color = BackgroundColor::Blue; break;
	case ForegroundColor::Green:	color = BackgroundColor::Green; break;
	case ForegroundColor::Red:		color = BackgroundColor::Red; break;
	case ForegroundColor::Purple:	color = BackgroundColor::Purple; break;
	case ForegroundColor::White:	color = BackgroundColor::White; break;
	}
	return color;
}

ForegroundColor Graphics::convertToColorFor(BackgroundColor backColor)
{
	ForegroundColor color = ForegroundColor::Black;
	switch (backColor)
	{
	case BackgroundColor::Black:	color = ForegroundColor::Black; break;
	case BackgroundColor::Blue:		color = ForegroundColor::Blue; break;
	case BackgroundColor::Green:	color = ForegroundColor::Green; break;
	case BackgroundColor::Red:		color = ForegroundColor::Red; break;
	case BackgroundColor::Purple:	color = ForegroundColor::Purple; break;
	case BackgroundColor::White:	color = ForegroundColor::White; break;
	}
	return color;
}

void Graphics::updateConsoleAttributes()
{
	DWORD attributes = 0;

	switch (_foreground)
	{
	case ForegroundColor::Black:	break;
	case ForegroundColor::Blue:		attributes |= FOREGROUND_BLUE; break;
	case ForegroundColor::Green:	attributes |= FOREGROUND_GREEN; break;
	case ForegroundColor::Red:		attributes |= FOREGROUND_RED; break;
	case ForegroundColor::Teal:		attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
	case ForegroundColor::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
	case ForegroundColor::Yellow:	attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break;
	case ForegroundColor::White:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
	}

	switch (_background)
	{
	case BackgroundColor::Black:	break;
	case BackgroundColor::Blue:		attributes |= BACKGROUND_BLUE; break;
	case BackgroundColor::Green:	attributes |= BACKGROUND_GREEN; break;
	case BackgroundColor::Red:		attributes |= BACKGROUND_RED; break;
	case BackgroundColor::Teal:		attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
	case BackgroundColor::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
	case BackgroundColor::Yellow:	attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break;
	case BackgroundColor::White:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
	}

	SetConsoleTextAttribute(_console, attributes);
}

bool isInside(int x, int y, int left, int top, int width, int height)
{
	x -= left;
	y -= top;
	return x >= 0 && y >= 0 && x < width && y < height;
}