#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "forward_list.h"

namespace forward_list_test
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestForwardList_is_empty)
		{
			forward_list<int> fli;
			Assert::AreEqual(true, fli.is_empty());

		}
		TEST_METHOD(TestForwardList_push_front_and_front){
			forward_list<int> fli;
			fli.push_front(10);
			Assert::AreEqual(10, fli.front());
			fli.push_front(20);
			Assert::AreEqual(20, fli.front());

		}

		TEST_METHOD(TestForwardList_swap){
			forward_list <int> fli1;
			forward_list <int> fli2;

			Assert::AreEqual(true, fli1.is_empty());

			fli1.push_front(10);
			fli1.push_front(20);

			fli2.push_front(30);
			fli1.swap(fli2);
			Assert::AreEqual(20, fli2.front());
		}

		TEST_METHOD(TestForwardList_iterator_begin_end){
			forward_list <int> fli;

			fli.push_front(10);
			fli.push_front(20);
			fli.push_front(30);
			int i = 0;
			Assert::AreEqual(false, fli.is_empty());
		}

		TEST_METHOD(TestForwardList_pop_front){
			forward_list<int> fli;
			int a = 10;
			int b = 20;
			int c = 30;
			fli.push_front(a);
			Assert::AreEqual(10, fli.front());
			fli.push_front(b);
			Assert::AreEqual(20, fli.front());
			fli.push_front(c);
			Assert::AreEqual(30, fli.front());

			fli.pop_front();
			Assert::AreEqual(20, fli.front());

		}

		//TEST_METHOD(TestForwardList_size){
			//Assert::AreEqual(false, true);
		//}
	};
};