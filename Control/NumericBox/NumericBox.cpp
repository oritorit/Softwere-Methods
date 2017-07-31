#include "numericBox.h"



NumericBox::NumericBox()
{
}

NumericBox::NumericBox(int width, int min, int max)
{
	this->height = 5;
	this->_min = min;
	this->_max = max;
	this->width = width;
	this->_value = min;
	b_plus->setWidth((width / 3)-1);
	b_plus->SetValue("+");
	b_plus->SetBorder(BorderType::Single);
	
	label->setWidth((width/3)-1);
	label->SetValue(to_string(_value));
	
	b_minus->setWidth((width/3)-1);
	b_minus->SetValue("-");
	b_minus->SetBorder(BorderType::Single);
	addControl(*b_minus, this->left , this->top + 1);
	addControl(*label, this->left , this->top + 1);
	addControl(*b_plus, this->left , this->top + 1);
}


NumericBox::~NumericBox()
{
	delete b_plus;
	delete b_minus;
	delete label;
}

string NumericBox::getType()
{
	return "NumericBox";
}

int NumericBox::GetValue() const
{
	return _value;
}

void NumericBox::setValue(int value)
{
		_value = value;
		label->SetValue(to_string(_value));
		//controllers[1]->Show();

}

int NumericBox::getWidth()
{
	return this->width;
}

int NumericBox::getHeight()
{
	return this->height;
}


void NumericBox::Show()
{
	
	int tmpWidth = 1;
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->setTop(this->top + 1);
		controllers[i]->setLeft(this->left + 1 + tmpWidth);
		tmpWidth += controllers[i]->getWidth();
	}
	Panel::Show();

}

void NumericBox::Hide()
{
}

bool NumericBox::Isvisible()
{
	return this->visible;
}

void NumericBox::SetForeground(ForegroundColor color)
{
	this->foreground = color;
}

void NumericBox::SetBackground(BackgroundColor color)
{
	this->background = color;
}

void NumericBox::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	switch (mer.dwEventFlags)
	{
	case 0:
		if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && x > this->left+1 && x < this->left+5 && y<this->top+3 && y>this->top+1) {
			/*_graphics.moveTo(30, top + 10);
			cout << "-";*/
			if (_value > _min) {
				_value--;
				label->SetValue(to_string(_value));
				controllers[1]->Show();
			}

		}
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && x >this->left + 10 && x < this->left+14 && y<this->top + 3 && y>this->top+1 ) {
			
			if (_value < _max) {
				_value++;
				label->SetValue(to_string(_value));
				controllers[1]->Show();
			}

		}
		
		break;
	default:
		//Nothing...
		break;
	}
}

bool NumericBox::canGetFocus()
{
	return true;
}


