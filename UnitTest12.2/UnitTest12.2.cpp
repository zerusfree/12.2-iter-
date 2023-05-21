#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* head = NULL;
			push(&head, 4);
			push(&head, 7);
			push(&head, 2);
			push(&head, 8);
			push(&head, 1);
			push(&head, 8);

			InputBefore(&head, 8, 4);

			Assert::AreEqual(head->info, 4);
			Assert::AreEqual(head->next->info, 8);
			Assert::AreEqual(head->next->next->info, 1);
			Assert::AreEqual(head->next->next->next->info, 4);
		}
	};
}
