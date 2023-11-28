#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 9.1 B/lab 9.1 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace laba91B
{
	TEST_CLASS(laba91B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student* students = new Student[N];


			students[0] = { "Ivanov", 5, 5, 1,  Õ, 5 };
			students[1] = { "Petrov", 4, 5, 1, ≤Õ‘, 5 };
			students[2] = { "Sidorov", 5, 4, 1, Ã“≈, 5 };

			Assert::AreEqual(2, Physics(students, N));

		}
	};
}
