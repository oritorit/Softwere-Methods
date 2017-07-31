// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TEXTBOXTEST_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TEXTBOXTEST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TEXTBOXTEST_EXPORTS
#define TEXTBOXTEST_API __declspec(dllexport)
#include <string>
#else
#define TEXTBOXTEST_API __declspec(dllimport)
#endif

// This class is exported from the TextBoxTest.dll
class TEXTBOXTEST_API CTextBoxTest {


public:
	CTextBoxTest(void);
	// TODO: add your methods here.
	class TextBox
	{
	protected:
		int width, height;
		std::string text;
	public:
		TextBox() {};
		TextBox(int _width):width(_width){};
		~TextBox() {};
		void setText(std::string _text){
			text = _text;
		}
		std::string getText() {
			return text;
		};
		int getWidth() {
			return width;
		};
		void setWidth(int _width)
		{
			width = _width;
		}
		void setHeight(int _height)
		{
			height = _height;
		}
		int getHeight() {
			return height;
		};
	};
};

extern TEXTBOXTEST_API int nTextBoxTest;

TEXTBOXTEST_API int fnTextBoxTest(void);
