#pragma once

#include "../TextBox/TextBox.h"

class Label: public TextBox
{

public:
	Label();
	Label(int _width, string value);
	Label(int _width);
	~Label();
	virtual string getType();
	void SetValue(string value);
	virtual void Show();
	virtual void Hide();
	virtual bool Isvisible();
	void setWidth(int width);
	//virtual void SetForeground(ForegroundColor color);
	//virtual void SetBackground(BackgroundColor color);
	virtual void SetBorder(BorderType _border);
	virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker);
	virtual bool canGetFocus();
};

