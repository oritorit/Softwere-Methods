#pragma once

#include "../CheckList/CheckList.h"

class RadioList: public CheckList
{
	
public:
	RadioList();
	RadioList(int _height, int _width, vector<string> _options);
	~RadioList();
	virtual string getType();
	void clearAll();
	virtual void mouseMove(int _row);
	virtual void mouseClick(int _y);
	virtual bool Isvisible();
	//virtual void Show();
	//virtual void Hide();
	//virtual void SetForeground(ForegroundColor color);
	//virtual void SetBackground(BackgroundColor color);
	//virtual void SetBorder(BorderType _border);
	//virtual BorderType getBorder();
	//virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker);
	virtual bool canGetFocus();
};

