#pragma once

#include "../IControl.h"

class CheckList: public IControl
{
protected:
	vector<string> options;
	vector<size_t> chosen;
	int row = 0;
	bool ifBorder = 0;
	int _left, _top;
public:
	CheckList();
	//CheckList(int _height, int _width, vector<string> _options);
	CheckList(int optionsNum, int _width, vector<string> _options);
	~CheckList();
	virtual string getType();
	vector<size_t> GetSelectedIndices();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	virtual void mouseMove(int _row);
	virtual void mouseClick(int _y);
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
};

