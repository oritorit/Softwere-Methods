#pragma once

#include "../IControl.h"

class Container: public IControl
{
protected:
	vector<IControl*> controllers;
public:
	Container();
	~Container();
	virtual void addControl(IControl &control, int _left, int _top) = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	virtual void SetForeground(ForegroundColor color) = 0;
	virtual void SetBackground(BackgroundColor color) = 0;
	virtual void SetBorder(BorderType border) = 0;
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer) = 0;
	virtual void keyPress(KEY_EVENT_RECORD ker) = 0;
	virtual bool canGetFocus() = 0;
};

