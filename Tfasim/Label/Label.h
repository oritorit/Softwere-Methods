#include "../Component/Component.h"

using namespace std;

#ifndef _LABEL
#define _LABEL

#pragma once
class Label: public Component
{
protected:
	string myString;
public:
	Label();
	Label(string str);
	~Label();
	virtual void paint();
	virtual VOID KeyEventProc(KEY_EVENT_RECORD ker);
	virtual VOID MouseEventProc(MOUSE_EVENT_RECORD mer);
};

#endif