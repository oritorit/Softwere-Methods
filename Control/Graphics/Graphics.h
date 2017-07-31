#pragma once

#include <string>
#include <Windows.h>

using namespace std;


enum class BorderType { Single, Double, None };
enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White };
enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };

class Graphics
{
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void resetColor();
	void moveTo(int x, int y);
	void getPosition(COORD& c);
	void setBackground(BackgroundColor color);
	void setForeground(ForegroundColor color);
	void write(string s);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(int x, int y, wstring s);
	void setCursorVisibility(bool isVisible);
	BackgroundColor getBackground();
	ForegroundColor getForground();
	void inverseAtt();
	BackgroundColor convertToColorBack(ForegroundColor forColor);
	ForegroundColor convertToColorFor(BackgroundColor backColor);
private:
	HANDLE _console;
	ForegroundColor _foreground;
	BackgroundColor _background;

	void updateConsoleAttributes();
};

bool isInside(int x, int y, int left, int top, int width, int height);
