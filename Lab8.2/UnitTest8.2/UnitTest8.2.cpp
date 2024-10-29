#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.2/Lab8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82
{
	TEST_CLASS(UnitTest82)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string input = "Hello, world!";
			string expected = "Hello, world!";
			Assert::AreEqual(expected, RemoveBrackets(input));
		}
	};
}