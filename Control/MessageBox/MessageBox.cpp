#include "MessageBox.h"

MsgBox::MsgBox()
{
}

MsgBox::MsgBox(int height, int width, string text, string title )
{
	this->height = height;
	this->width = width;
	this->top = 2;
	this->left = 3;

	_label.setWidth(title.size());
	_label.SetValue(title);
	_label.SetBorder(BorderType::None);

	_msg.setWidth(text.size());
	_msg.SetValue(text);
	_msg.SetBorder(BorderType::None);

	yesButton.setWidth(5);
	yesButton.SetValue("Yes");
	yesButton.SetBorder(BorderType::Single);

	noButton.setWidth(5);
	noButton.SetValue("No");
	noButton.SetBorder(BorderType::Single);

	addControl(_label, this->left+1, this->top + 1);
	addControl(_msg, this->left+1 , this->top + 1);
	addControl(yesButton, this->left+1 , this->top + 1);
	addControl(noButton, this->left +1, this->top+1);

}

MsgBox:: ~MsgBox()
{
}
string MsgBox::getType()
{
	return "MessageBox";
}
int MsgBox::getWidth()
{
	return this->width;
}
int MsgBox::getHeight()
{
	return this->height;
}

void MsgBox::SetText(string text)
{
	_text = text;
}
void MsgBox::SetTitle(string title)
{
	_title = title;
}

void MsgBox::Show()
{
	int tmpWidth = 1;
	for (int i = 0; i < controllers.size(); i++)
	{
		if(i>1)
		{

			controllers[i]->setTop(this->top + 5);
			controllers[i]->setLeft(this->left + width/4 + tmpWidth);
			tmpWidth += controllers[i]->getWidth();
		}
		else
		{
			controllers[i]->setTop(this->top +1+i);
			controllers[i]->setLeft(this->left + 1 );
		}
		
	}
	Panel::Show();
	
}
void MsgBox::Hide()
{
	this->setVisible(false);

	Panel::Show();
}


void MsgBox::SetForeground(ForegroundColor color)
{
	this->foreground = color;
}

void MsgBox::SetBackground(BackgroundColor color)
{
	this->background = color;
}


void MsgBox::setLeft(int _left)
{
	this->left = _left;
}
void MsgBox::setTop(int _top)
{
	this->left = _top;
}
int MsgBox::getLeft()
{
	return this->left;
}
int MsgBox::getTop()
{
	return this->top;
}
/*
void MsgBox::getAllControls(vector<IControl*> &v)
{

}

void MsgBox::SetForeground(ForegroundColor color)
{

}
void MsgBox::SetBackground(BackgroundColor color)
{

}
void MsgBox::SetBorder(BorderType _border)
{

} 
BorderType MsgBox:: getBorder()
{
	return BorderType::None;
}
*/

void MsgBox::mouseEvent(MOUSE_EVENT_RECORD mer)
{

	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	

	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED
			&& x > (this->left + width / 4 + 1)
			&& x < (this->left + width / 4 + 6)
			&& y > (this->top +5)
			&& y < (this->top + 8)
			)
		{
			//cout << "Yes";
			clicked = true;
			Hide();
		}
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED
			&& x > (this->left + width / 4 + 2)
			&& x < (this->left + width / 4 + 7)
			&& y > (this->top + 5)
			&& y < (this->top + 8)
			)
		{
			//cout << "No";
			clicked = true;
			Hide();
		}
		break;
	default:
		/// nothing to do 
		break;
	}
}

void MsgBox::keyPress(KEY_EVENT_RECORD ker)
{

}

bool MsgBox::canGetFocus()
{
	return true;
}

/*
void MsgBox::addControl(IControl &control, int _left, int _top)
{
	
}

bool MsgBox::canGetFocus()
{
	return true;
}
*/