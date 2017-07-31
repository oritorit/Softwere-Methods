#pragma once

#include "../IControl.h"

class TextBox: public IControl
{
protected:
	//string myString;
public:
	TextBox();
	TextBox(int _width);
	~TextBox();
	//void SetValue(string value);
	//string GetValue();
	string getType();
	virtual int getWidth();
	virtual int getHeight();
	virtual void Show();
	virtual void Hide();
	virtual bool Isvisible();
	virtual void SetForeground(ForegroundColor color);
	virtual void SetBackground(BackgroundColor color);
	virtual void SetBorder(BorderType _border);
	virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker);
	virtual bool canGetFocus();
};

