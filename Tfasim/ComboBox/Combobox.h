#include "..\Component\Component.h"
#pragma once

using namespace std;

#ifndef _COMBO
#define _COMBO

class Combobox: public Component
{
protected:
	vector<string> options;
	int printed = 0, row = 0;
public:
	Combobox();
	~Combobox();
	void mouseMove(int _row);
	void mouseClick(int _y);
	void showList();
	virtual void paint();
	virtual VOID KeyEventProc(KEY_EVENT_RECORD ker);
	virtual VOID MouseEventProc(MOUSE_EVENT_RECORD mer);
};


#endif

