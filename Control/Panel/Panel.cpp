#include "Panel.h"

Panel::Panel()
{
}

Panel::Panel(int _height, int _width)
{
	this->height = _height;
	this->width = _width;
}


Panel::~Panel()
{
}

string Panel::getType()
{
	return "Panel";
}

int Panel::getWidth()
{
	return this->width;
}

int Panel::getHeight()
{
	return this->height;
}

void Panel::addControl(IControl & control, int _left, int _top)
{
	control.setLeft(_left);
	control.setTop(_top);
	controllers.push_back(&control);
}

void Panel::Show()
{
	IControl::Show();
	for (int i = 0; i < controllers.size(); i++)
	{
		if(controllers[i]->getVisible() == true)
			controllers[i]->Show();
	}
	IControl* tmp = &IControl::getFocus();
	if(tmp->getType() == "TextBox")
		_graphics.moveTo(tmp->getLeft() + tmp->GetValue().size(), tmp->getTop() + 1);
	else
		_graphics.moveTo(tmp->getLeft() + 1, tmp->getTop() + 1); 
}

void Panel::Hide()
{
}

bool Panel::Isvisible()
{
	return this->visible;
}

void Panel::SetForeground(ForegroundColor color)
{
}

void Panel::SetBackground(BackgroundColor color)
{
}

void Panel::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType Panel::getBorder()
{
	return this->border;
}

void Panel::mouseEvent(MOUSE_EVENT_RECORD mer)
{
}

void Panel::keyPress(KEY_EVENT_RECORD ker)
{
}

bool Panel::canGetFocus()
{
	return false;
}

void Panel::getAllControls(vector<IControl*>& v)
{
	for (int i = 0; i < controllers.size(); i++)
	{
		v.push_back(controllers[i]);
	}
}


