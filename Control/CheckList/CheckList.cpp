#include "CheckList.h"



CheckList::CheckList()
{
}

//CheckList::CheckList(int _height, int _width, vector<string> _options)
//{
//	this->height = _height;
//	this->width = _width;
//	this->border = BorderType::None;
//	chosen.resize(_options.size());
//	options.swap(_options);
//}

CheckList::CheckList(int optionsNum, int _width, vector<string> _options)
{
	this->height = optionsNum;
	this->width = _width;
	this->border = BorderType::None;
	chosen.resize(_options.size());
	options.swap(_options);
}


CheckList::~CheckList()
{
}

string CheckList::getType()
{
	return "CheckList";
}

vector<size_t> CheckList::GetSelectedIndices()
{
	return chosen;
}

void CheckList::SelectIndex(size_t index)
{
	chosen[index] = 1;
}

void CheckList::DeselectIndex(size_t index)
{
}

int CheckList::getWidth()
{
	return this->width;
}

int CheckList::getHeight()
{
	return this->height;
}

void CheckList::Show()
{
	_top = top;
	_left = left;
	this->cleanSpace();
	_graphics.setForeground(this->foreground);
	_graphics.setBackground(this->background);
	this->printBorder(height + 2, width, _left, _top, border);
	for (int i = 0; i < options.size(); i++)
	{
		if (border != BorderType::None) {
			ifBorder = 1;
			_graphics.moveTo(_left + 1, i + _top + 1);
		}
		else
			_graphics.moveTo(_left, i + _top);
		if (i == 0) {
			_graphics.setBackground(BackgroundColor::Black);
			_graphics.setForeground(ForegroundColor::White);
		}
		else
			_graphics.resetColor();
		if (chosen[i] == 1)
		{
			cout << "[#]" << options[i];
		}
		else
		cout << "[ ]" << options[i];
		_graphics.moveTo(_left, _top);
	}
}

void CheckList::Hide()
{
}

bool CheckList::Isvisible()
{
	return this->visible;
}

void CheckList::SetForeground(ForegroundColor color)
{
	this->foreground = color;
}

void CheckList::SetBackground(BackgroundColor color)
{
	this->background = color;
}

void CheckList::SetBorder(BorderType _border)
{
	if (_border == BorderType::None) {
		return;
	}
	else {
		ifBorder = 1;
	}
	this->border = _border;
}

BorderType CheckList::getBorder()
{
	return this->border;
}

void CheckList::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y >= _top && y <= _top + options.size() - 1 && x >= _left && x < _left + width)
		{
			mouseClick(y);
		}
		break;
	case MOUSE_MOVED:
		if (y >= _top && y <= _top + options.size() - 1 && x >= _left && x < _left + width)
		{
			mouseMove(y);
		}

		break;
	default:
		//Nothing...
		break;
	}
}

void CheckList::keyPress(KEY_EVENT_RECORD ker)
{
	if (ifBorder == 1) {
		_left++;
		_top++;
		ifBorder = 0;
	}
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		_graphics.getPosition(coord);
		if (coord.Y <= _top)
			_graphics.moveTo(_left, _top);
		else
		{
			_graphics.resetColor();
			_graphics.moveTo(_left, row + _top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(_left + 1, row + _top);
				cout << "#";
			}
			--row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(_left, row + _top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(_left + 1, row + _top);
				cout << "#";
			}
		}
		
	}
	else if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		_graphics.getPosition(coord);
		if (coord.Y >= _top + options.size() - 1)
			_graphics.moveTo(_left, _top + options.size());
		else
		{
			_graphics.resetColor();
			_graphics.moveTo(_left, row + _top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(_left + 1, row + _top);
				cout << "#";
			}
			++row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(_left, row + _top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(_left + 1, row + _top);
				cout << "#";
			}
		}
	}
	else if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		if (chosen[row] == 0) {
			
			_graphics.moveTo(_left + 1, row + _top);
			cout << "#";
			chosen[row]++;
		}
		else {
			_graphics.moveTo(_left + 1, row + _top);
			cout << " ";
			chosen[row]--;
		}
	}
	else if (ker.bKeyDown)
	{
		//Do nothing...
	}
}

void CheckList::mouseMove(int _row)
{
	if (ifBorder == 1) {
		_left++;
		_top++;
		ifBorder = 0;
	}
	for (int i = 0; i < options.size(); i++)
	{

		_graphics.moveTo(_left, _top + i);
		if (i == _row - _top)
		{
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
		}
		else
		{
			_graphics.resetColor();
		}
		row = _row - _top;
		cout << "[ ]" << options[i];
		if (chosen[i] == 1) {
			_graphics.moveTo(_left + 1, _top + i);
			cout << "#";
		}
	}
	_graphics.moveTo(_left, _row);
}

void CheckList::mouseClick(int _y)
{
	if (chosen[_y - _top] == 0) {
		_graphics.moveTo(_left + 1, _y);
		cout << "#";
		chosen[_y - _top]++;
	}
	else {
		_graphics.moveTo(_left + 1, _y);
		cout << " ";
		chosen[_y - _top]--;
	}
}

bool CheckList::canGetFocus()
{
	return true;
}