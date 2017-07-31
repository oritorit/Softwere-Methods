#include "Button.h"

Button::Button()
{
}

Button::Button(int _width) : listener(NULL)
{
	this->width = _width;
	border = BorderType::Single;
}

Button::~Button()
{
}

bool Button::Isvisible()
{
	return this->visible;
}



string Button::getType()
{
	return "Button";
}

void Button::SetValue(string value)
{
	myString = value;
}

void Button::AddListener(MouseListener& listener)
{
	this->listener = &listener;
}

//void Button::AddListener(MouseListener & listener)
//{
//}

void Button::setWidth(int width)
{
	this->width = width;
}


void Button::Hide()
{
}



void Button::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y == top + 1 && x > left && x < left + width)
		{
			this->listener->MousePressed(*this, x, y, true);
		}
		break;
	default:
		//Nothing...
		break;
	}

}

bool Button::canGetFocus()
{
	return false;
}
