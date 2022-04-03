#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR 3.1.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Student s[2];
			s[0].physics = 4;
			s[1].physics = 5;
			Assert::AreEqual(100., ProsPhysik(s, 2));
		}
	};
}