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
			Assert::AreEqual(false, fli.is_empty());

		}

		/*TEST_METHOD(TestForwardList_iterator_begin_end){
			forward_list <int> fli;
			Assert::AreEqual(false, fli.is_empty());
			
			}

			TEST_METHOD(TestForwardList_pop_front){
				forward_list<int> fli;
				Assert::AreEqual(true, false);
			
			}

			TEST_METHOD(TestForwardList_size){
			Assert::AreEqual(false, true);
			}
			}*/
	};
};