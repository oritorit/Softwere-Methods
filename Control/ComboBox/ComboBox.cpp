#include "ComboBox.h"



ComboBox::ComboBox()
{
}

ComboBox::ComboBox(int _width, vector<string> _options)
{
	this->width = _width;
	options.swap(_options);
}


ComboBox::~ComboBox()
{
}

string ComboBox::getType()
{
	return "ComboBox";
}

size_t ComboBox::GetSelectedIndex()
{
	return size_t();
}

void ComboBox::SetSelectedIndex(size_t index)
{
}

void ComboBox::showList()
{

	if (printed == 0)
	{

		for (int i = 0; i < options.size(); i++)
		{
			if (i == 0) {
				_graphics.setBackground(BackgroundColor::White);
				_graphics.setForeground(ForegroundColor::Black);
			}
			else
				_graphics.resetColor();
			_graphics.moveTo(left + 2, top + 3 + i);
			cout << options[i];
		}
		printed++;
		row = 0;
		_graphics.moveTo(left + 2, top + 3);
	}
	else
	{
		_graphics.resetColor();
		/*for (int j = 0; j < 5; j++)
		{
			_graphics.moveTo(left + 2, top + 3 + j);
			for (int a = 13; a > 0; a--)
			{
				_graphics.moveTo(left + 2 + a, top + 2 + j);
				cout << ' ';

			}
			
		}*/
		
		printed--;
	}
}

void ComboBox::mouseMove(int _row)
{
	if (printed == 0)
		return;
	for (int i = 0; i < options.size(); i++)
	{
		_graphics.moveTo(left + 2, top + 3 + i);
		if (i == _row - (top + 3))
		{
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);	
		}
		else
			_graphics.resetColor();
		row = _row - (top + 3);
		cout << options[i];
	}
	_graphics.moveTo(left + 2, _row);
}

void ComboBox::mouseClick(int _y)
{
	if (printed == 0)
		return;
	_graphics.resetColor();
	_graphics.moveTo(left + 1, top + 1);
	for (int i = 0; i < width - 6; i++)
		_graphics.write(" ");
	_graphics.moveTo(left + 1, top + 1);
	cout << options[row];
	this->SetValue(options[row]);
	showList();
}

int ComboBox::getWidth()
{
	return this->width;
}

int ComboBox::getHeight()
{
	return this->height;
}

void ComboBox::Show()
{
	IControl::Show();
	_graphics.moveTo(left + width - 5, top + 1);
	cout << "\xB3";
	_graphics.moveTo(left + width - 3, top + 1);
	cout << "\x56";
	_graphics.moveTo(left + 1, top + 1);
	_graphics.write(this->myString);

}

void ComboBox::Hide()
{
}

bool ComboBox::Isvisible()
{
	return this->visible;
}

void ComboBox::SetForeground(ForegroundColor color)
{
	this->foreground = color;
}

void ComboBox::SetBackground(BackgroundColor color)
{
	this->background = color;
}

void ComboBox::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType ComboBox::getBorder()
{
	return this->border;
}

void ComboBox::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y == top + 1 && x > left + width - 5 && x < left + width - 1)
			showList();
		else if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y > top + 2 && x > left + 1 && x < left + width - 5)
			mouseClick(y);
		break;
	case MOUSE_MOVED:
		if (y > top + 2 && y < top + 3 + options.size() && x > left + 1 && x < left + width - 5)
		{
			mouseMove(y);
		}

		break;
	default:
		//Nothing...
		break;
	}
}

void ComboBox::keyPress(KEY_EVENT_RECORD ker)
{
	if (printed == 0)
		return;
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		_graphics.getPosition(coord);
		if (coord.Y == top + 3)
			_graphics.moveTo(left + 2, top + 3);
		else
		{
			_graphics.resetColor();
			_graphics.moveTo(left + 2, row + top + 3);
			cout << options[row];
			--row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(left + 2, row + top + 3);
			cout << options[row];
		}

	}
	else if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		_graphics.getPosition(coord);
		if (coord.Y == top + 2 + options.size())
			_graphics.moveTo(left + 2, top + 2 + options.size());
		else
		{
			_graphics.resetColor();
			_graphics.moveTo(left + 2, row + top + 3);
			cout << options[row];
			++row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(left + 2, row + top + 3);
			cout << options[row];
		}
	}
	else if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		_graphics.resetColor();
		_graphics.moveTo(left + 1, top + 1);
		cout << options[row];
		showList();
	}
	else if (ker.bKeyDown)
	{
		//Do nothing...
	}
}

bool ComboBox::canGetFocus()
{
	return true;
}
