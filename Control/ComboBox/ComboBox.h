#pragma once

#include "../IControl.h"

class ComboBox: public IControl
{
protected:
	vector<string> options;
	int printed = 0, row = 0;
public:
	ComboBox();
	ComboBox(int _width, vector<string> _options);
	~ComboBox();
	virtual string getType();
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	void showList();
	void mouseMove(int _row);
	void mouseClick(int _y);
	virtual int getWidth();
	virtual int getHeight();
	virtual void Show();
	virtual void Hide();
	virtual bool Isvisible();
	virtual void SetForeground(ForegroundColor color);
	virtual void SetBackground(BackgroundColor color);
	virtual void SetBorder(BorderType _border);
	virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker);
	virtual bool canGetFocus();
	int getPrinted() { return printed; };
};

