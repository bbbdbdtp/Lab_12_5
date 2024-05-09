#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_5/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCompareStacks)
		{
			// Arrange
			stack<int> stack1, stack2;
			stack1.push(1);
			stack1.push(2);
			stack1.push(3);

			stack2.push(1);
			stack2.push(2);
			stack2.push(3);

			// Act
			bool resultEqual = compareStacks(stack1, stack2); // Стеки однакові, тому має повернутися true

			stack<int> stack3;
			stack3.push(1);
			stack3.push(-2);
			stack3.push(4);

			// Act
			bool resultNotEqual = compareStacks(stack1, stack3); // Стеки різні, тому має повернутися false

			// Assert
			Assert::IsTrue(resultEqual);
			Assert::IsFalse(resultNotEqual);
		}
	};
}
