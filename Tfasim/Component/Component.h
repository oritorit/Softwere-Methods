#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

#ifndef _COMP
#define _COMP


#pragma once
class Component
{
public:
	Component();
	~Component();
	int x = 0, y = 0, counter = 0;
	DWORD wAttr, cNumRead, fdwMode, i;;
	INPUT_RECORD irInBuf[128];
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	CONSOLE_CURSOR_INFO cci;
	HANDLE handleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE handleIN = GetStdHandle(STD_INPUT_HANDLE);
	void setWattr(DWORD _word);
	void setCursor(DWORD size, bool b);
	void setColor(int color);
	void setPosition(SHORT _x, SHORT _y);
	void getPosition(int &x, int &y);
	virtual void paint() = 0;
	virtual VOID KeyEventProc(KEY_EVENT_RECORD ker) = 0;
	virtual VOID MouseEventProc(MOUSE_EVENT_RECORD mer) = 0;
};

#endif