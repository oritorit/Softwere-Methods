#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "Graphics\Graphics.h"

using namespace std;


class IControl
{
protected:
	int width, height = 3, left, top;
	string myString;
	bool visible = true;
	static IControl* focus;
	//bool isFocusable;
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
	COORD coord;
	BorderType border = BorderType::Single;
	ForegroundColor foreground = ForegroundColor::White;
	BackgroundColor background = BackgroundColor::Black;
public:
	IControl(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	~IControl();
	void printBorder(int height, int width, int left, int top, BorderType type);
	void SetValue(string value);
	string GetValue();
	virtual string getType()=0;
	virtual void setLeft(int _left);
	virtual void setTop(int _top);
	virtual int getLeft();
	virtual int getTop();
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void Show();
	virtual void Hide() = 0;
	virtual void SetForeground(ForegroundColor color) = 0;
	virtual void SetBackground(BackgroundColor color) = 0;
	virtual void SetBorder(BorderType _border) = 0;
	virtual BorderType getBorder() = 0;
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer) = 0;
	virtual void keyPress(KEY_EVENT_RECORD ker) = 0;
	virtual bool getVisible();
	virtual void setVisible(bool);
	virtual void getAllControls(vector<IControl*> &v);
	virtual bool canGetFocus() = 0;
	static void setFocus(IControl& control);
	static IControl& getFocus();

	void cleanSpace();
	void invertColors();
};
