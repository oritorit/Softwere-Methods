#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../Label/Label.h"
class NumericBox:public Panel
{

protected:
	int _min;
	int _max;
	int _value;
	Button* b_plus = new Button(4);
	Button* b_minus = new Button(4);
	Label* label = new Button(4);
	
public:
	NumericBox();
	NumericBox(int width, int min, int max);
	~NumericBox();
	virtual string getType();;
	int GetValue()const;
	void setValue(int value);
	virtual int getWidth();
	virtual int getHeight();
	//virtual void addControl(IControl & control, int _left, int _top);
	virtual void Show();
	virtual void Hide();
	virtual bool Isvisible();
	virtual void SetForeground(ForegroundColor color);
	virtual void SetBackground(BackgroundColor color);
	//virtual void SetBorder(BorderType _border);
	//virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	//virtual void keyPress(KEY_EVENT_RECORD ker);
	bool canGetFocus();
};

