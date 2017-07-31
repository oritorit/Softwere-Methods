#include "Label.h"


Label::Label()
{
}

Label::Label(int _width, string value)
{
	this->width = _width;
	myString = value;
	border = BorderType::None;
}

Label::Label(int _width)
{
	this->width = _width;
}

Label::~Label()
{
}

string Label::getType()
{
	return "Label";
}

void Label::SetValue(string value)
{
	myString = value;
}

void Label::Show()
{
	TextBox::Show();
	//_graphics.write(myString);
}

void Label::Hide()
{
}

bool Label::Isvisible()
{
	return this->visible;
}

void Label::setWidth(int width)
{
	this->width = width;
}

void Label::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType Label::getBorder()
{
	return this->border;
}

void Label::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	//Do Nothing...
}

void Label::keyPress(KEY_EVENT_RECORD ker)
{
	//Do Nothing...
}

bool Label::canGetFocus()
{
	return false;
}
