#include "IControl.h"

IControl* IControl::focus = 0;

IControl::IControl(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
	_graphics.setCursorVisibility(false);
}

IControl::~IControl()
{
}

void IControl::printBorder(int height, int width, int left, int top, BorderType type)
{
	string topLeft, topRight, bottomLeft, bottomRight, vertical, horizontal;
	switch (type)
	{
	case BorderType::Single:
		topLeft = '\xDA'; topRight = '\xBF'; bottomLeft = '\xC0'; bottomRight = '\xD9'; vertical = '\xB3'; horizontal = '\xC4';
		break;

	case BorderType::Double:
		topLeft = '\xC9'; topRight = '\xBB'; bottomLeft = '\xC8'; bottomRight = '\xBC'; vertical = '\xBA'; horizontal = '\xCD';
		break;

	case BorderType::None:
		_graphics.moveTo(left, top);
		return;
		break;
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
			{
				_graphics.moveTo(left + j, top + i);
				if (i == 0 && j == 0)_graphics.write(topLeft) ;
				else if (i == 0 && j == width - 1) _graphics.write(topRight);
				else if (i == height - 1 && j == 0) _graphics.write(bottomLeft);
				else if (i == height - 1 && j == width - 1) _graphics.write(bottomRight);
				else _graphics.write(horizontal);
			}
			else
			{
				_graphics.moveTo(left, top + i);
				_graphics.write(vertical);
				_graphics.moveTo(left + width - 1, top + i);
				_graphics.write(vertical);
			}
		}
	}
	_graphics.moveTo(left + 1, top + 1);
}

void IControl::SetValue(string value)
{
	this->myString = value;
}

string IControl::GetValue()
{
	return this->myString;
}


void IControl::setLeft(int _left)
{
	this->left = _left;
}

void IControl::setTop(int _top)
{
	this->top = _top;
}

int IControl::getLeft()
{
	return this->left;
}

int IControl::getTop()
{
	return this->top;
}

void IControl::Show()
{
	_graphics.resetColor();
	for (int i = 0; i < this->height; i++)
	{
		_graphics.moveTo(this->left , this->top + i);
		for (int j = 0; j < this->width; j++) {
			_graphics.write(" ");
		}
	}
	_graphics.setForeground(this->foreground);
	_graphics.setBackground(this->background);
	this->printBorder(height, width, left, top, border);
}

bool IControl::getVisible()
{
	return this->visible;
}

void IControl::setVisible(bool value)
{
	this->visible = value;
}

void IControl::getAllControls(vector<IControl*>& v)
{
	v.push_back(this);
}

void IControl::setFocus(IControl & control)
{
	if (focus != NULL) {
		focus->SetForeground(ForegroundColor::White);
		focus->SetBackground(BackgroundColor::Black);
		focus->Show();
	}
	
	if (control.getType() == "TextBox")
	{
		control._graphics.setCursorVisibility(true);
	}
	else
		control._graphics.setCursorVisibility(false);
	//control._graphics.resetColor();
	focus = &control;
	focus->invertColors();
	focus->Show();
	/*if (focus->getType() == "textbox")
		focus->_graphics.moveTo(focus->getLeft() + focus->GetValue().size(), focus->getTop() + 1);
	else
		focus->_graphics.moveTo(focus->getLeft() + 1, focus->getTop() + 1);*/
}

IControl & IControl::getFocus()
{
	return *focus;
}

void IControl::cleanSpace()
{
	_graphics.resetColor();
	for (int i = 0; i < this->height + 2; i++)
	{
		_graphics.moveTo(this->left - 1, this->top + i);
		for (int j = 0; j < this->width+5; j++) {
			_graphics.write(" ");
		}
	}
}

void IControl::invertColors()
{
	this->SetForeground(ForegroundColor::Black);
	this->SetBackground(BackgroundColor::White);
}


