// TextBoxTest.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TextBoxTest.h"


// This is an example of an exported variable
TEXTBOXTEST_API int nTextBoxTest=0;

// This is an example of an exported function.
TEXTBOXTEST_API int fnTextBoxTest(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see TextBoxTest.h for the class definition
CTextBoxTest::CTextBoxTest()
{
    return;
}
