#include "..\Component\Component.h"
#pragma once

using namespace std;

#ifndef _CHECK
#define _CHECK

class Checklist : public Component
{
protected: 
	int row = 0;
	int chosen[5] = { 0, 0, 0, 0, 0 };
	vector<string> options;
public:
	Checklist();
	~Checklist();
	void mouseMove(int _row);
	void mouseClick(int _y);
	virtual void paint();
	virtual VOID KeyEventProc(KEY_EVENT_RECORD ker);
	virtual VOID MouseEventProc(MOUSE_EVENT_RECORD mer);
};


#endif
