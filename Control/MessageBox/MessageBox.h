#pragma once

#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../Label/Label.h"
#include "../TextBox/TextBox.h"


class MsgBox : public Panel
{
protected:
	bool clicked = false;
	string _text;
	string _title;
	Label _msg;
	Label _label;
	Button yesButton;
	Button noButton;
public:
	MsgBox();
	MsgBox(int _height, int _width, string text, string title);
	~MsgBox();

	virtual string getType();
	virtual int getWidth();
	virtual int getHeight();
	//virtual void addControl(IControl & control, int _left, int _top);
	virtual void Show();
	virtual void Hide();
	//virtual bool Isvisible();
	virtual void SetForeground(ForegroundColor color);
	virtual void SetBackground(BackgroundColor color);
	//virtual void SetBorder(BorderType _border);
	//virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker);
	virtual bool canGetFocus();

	void SetText(string text);
	void SetTitle(string title);
	virtual void setLeft(int _left);
	virtual void setTop(int _top);
	virtual int getLeft();
	virtual int getTop();
	////virtual void getAllControls(vector<IControl*> &v);
	//virtual void SetForeground(ForegroundColor color);
	//virtual void SetBackground(BackgroundColor color);	
	////virtual void SetBorder(BorderType _border);
	////virtual BorderType getBorder();
	//virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	//virtual void keyPress(KEY_EVENT_RECORD ker);
	////virtual void addControl(IControl &control, int _left, int _top);
	////virtual bool canGetFocus();

};