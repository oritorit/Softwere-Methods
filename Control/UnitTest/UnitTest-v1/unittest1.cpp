#include "stdafx.h"
#include "CppUnitTest.h"

#include "../TextBoxTest/TextBoxTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestv1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(setHeightTest)
		{
			CTextBoxTest::TextBox boxTest(10);
			boxTest.setHeight(5);
			Assert::AreEqual(5, boxTest.getHeight(), L"message");
			boxTest.setHeight(6);
			Assert::AreEqual(6, boxTest.getHeight(), L"message");
		}
		TEST_METHOD(setWidthTest)
		{
			CTextBoxTest::TextBox boxTest(10);
			Assert::AreEqual(10, boxTest.getWidth(), L"message");
			boxTest.setWidth(6);
			Assert::AreEqual(6, boxTest.getWidth(), L"message");
		}

	};
}