#pragma once

#include "../Container/Container.h"

class Panel: public Container
{
protected:
	
	
public:
	Panel();
	Panel(int _height, int _width);
	~Panel();
	virtual string getType();
	virtual int getWidth();
	virtual int getHeight();
	virtual void addControl(IControl & control, int _left, int _top);
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

	virtual void getAllControls(vector<IControl*> &v);
};

