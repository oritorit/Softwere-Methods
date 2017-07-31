#include "..\Component\Component.h"
#pragma once

using namespace std;

#ifndef _RADIO
#define _RADIO

class Radiolist: public Component
{
protected:
	vector<string> options;
	int row = 0;
	int chosen[5] = { 0, 0, 0, 0, 0 };
public:
	Radiolist();
	~Radiolist();
	void clearAll();
	void mouseMove(int _row);
	void mouseClick(int _y);
	virtual void paint();
	virtual VOID KeyEventProc(KEY_EVENT_RECORD ker);
	virtual VOID MouseEventProc(MOUSE_EVENT_RECORD mer);
};


#endif

