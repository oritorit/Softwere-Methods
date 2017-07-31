#pragma once

#include "../IControl.h"
#include "../Panel/Panel.h"
#include "../ComboBox/ComboBox.h"

class EventEngine
{
private:

	HANDLE _console;
	DWORD _consoleMode;
	void EventEngine::moveFocus(IControl &main, IControl *focused);
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	virtual ~EventEngine();

	void run(IControl &c);
	
};
