#include "..\Component\Component.h"
#pragma once

using namespace std;


#ifndef _TEXTBOX
#define _TEXTBOX

class Textbox: public Component
{
protected:
	string myString;
public:
	Textbox();
	~Textbox();
	virtual void paint();
	virtual VOID KeyEventProc(KEY_EVENT_RECORD ker);
	virtual VOID MouseEventProc(MOUSE_EVENT_RECORD mer);
};


#endif _TEXTBOX
