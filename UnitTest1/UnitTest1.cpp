#include "pch.h"
#include "CppUnitTest.h"
#include "../lab PKR 3.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student s[2];
			s[0].math = 5;
			s[0].physics = 4;
			s[0].progr = 3;
			s[1].math = 1;
			s[1].physics = 2;
			s[1].numb = 3;
			Assert::AreEqual(4., HighestAverageScore(s, 2));
		}
	};
}