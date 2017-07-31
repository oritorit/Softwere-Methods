#pragma once

#include "../Label/Label.h"


class Button;

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};
class Button : public Label
{


 MouseListener *listener;

public:
	Button();
	Button(int _width);
	~Button();
	virtual bool Isvisible();
	virtual string getType();
	void SetValue(string value);
	void AddListener(MouseListener &listener);
	void setWidth(int width);
	virtual void Hide();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual bool canGetFocus();
};

