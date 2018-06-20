#include "stdafx.h"
#include "CppUnitTest.h"

#include "../DevSet/IntSetList.cpp"
#include "../DevSet/util_func.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestList
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int max_v = 1000000;
		int max_e = max_v / 100;
		int *v = new int[max_e];
		int *expect = new int[max_e]; // Expected values;
		bool result_equal = true;

		int i, j, temp;

		TEST_METHOD(List_Insert_Desc)
		{
			// Inserting values in descending order
			IntSetList test(max_e, max_v);
			j = 0;
			for (i = max_e - 1; i >= 0; i++) {
				test.insert(max_v - j);
				j++;
			}
		}

		TEST_METHOD(List_Insert_Asce)
		{
			// Inserting values in ascending order
			IntSetList test(max_e, max_v);
			for (i = 0; i < max_e + 1; i++) {
				test.insert(max_e + i);
			}
		}

		TEST_METHOD(List_Insert_Rand)
		{
			// Inserting random values
			IntSetList test(max_e, max_v);
			for (i = 0; i < max_e + 1; i++) {
				test.insert(bigrand(max_v));
			}
		}

		TEST_METHOD(List_Report_Desc)
		{
			// Inserting values in descending order
			IntSetList test(max_e, max_v);
			j = 0;
			for (i = max_e - 1; i >= 0; i++) {
				test.insert(max_v - j);
				expect[i] = max_v - j;
				j++;
			}

			test.report(v);
			std::sort(expect, expect + max_e);

			// Comparing expected values and result values
			for (i = 0; i < max_e + 1; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
					break;
				}
			}

			Assert::AreEqual(true, result_equal);
		}

		TEST_METHOD(List_Report_Asce)
		{
			// Inserting values in ascending order
			IntSetList test(max_e, max_v);

			for (i = 0; i < max_e + 1; i++) {
				test.insert(max_e + i);
				expect[i] = max_e + i;
			}

			test.report(v);
			std::sort(expect, expect + max_e);

			// Comparing expected values and result values
			for (i = 0; i < max_e + 1; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
					break;
				}
			}

			Assert::AreEqual(true, result_equal);
		}

		TEST_METHOD(List_Report_Rand)
		{
			// Inserting random values
			IntSetList test(max_e, max_v);
			for (i = 0; i < max_e + 1; i++) {
				temp = bigrand(max_v);
				test.insert(temp);
				expect[i] = temp;
			}

			test.report(v);
			std::sort(expect, expect + max_e);

			// Comparing expected values and result values
			for (i = 0; i < max_e + 1; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
					break;
				}
			}

			Assert::AreEqual(true, result_equal);
		}

	};
}