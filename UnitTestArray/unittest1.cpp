#include "stdafx.h"
#include "CppUnitTest.h"

#include "../DevSet/IntSetArray.cpp"
#include "../DevSet/util_func.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestArray
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

		TEST_METHOD(Array_Insert_Desc)
		{
			// Inserting values in descending order
			IntSetArray test(max_e, max_v);
			j = 0;
			for (i = max_e - 1; i >= 0; i--) {
				test.insert(max_v - j);
				j++;
			}
		}

		TEST_METHOD(Array_Insert_Asce)
		{
			// Inserting values in ascending order
			IntSetArray test(max_e, max_v);
			for (i = 0; i < max_e + 1; i++) {
				test.insert(max_e + i);
			}
		}

		TEST_METHOD(Array_Insert_Rand)
		{
			// Inserting random values
			IntSetArray test(max_e, max_v);
			for (i = 0; i < max_e + 1; i++) {
				test.insert(bigrand(max_v));
			}
		}

		TEST_METHOD(Array_Report_Desc)
		{
			// Inserting values in descending order
			IntSetArray test(max_e, max_v);
			j = 0;
			for (i = max_e - 1; i >= 0; i--) {
				test.insert(max_v - j);
				expect[i] = max_v - j;
				j++;
			}

			test.report(v);
			std::sort(expect, expect + max_e);

			// Comparing expected values and result values
			for (i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
					break;
				}
			}

			Assert::AreEqual(true, result_equal);
		}

		TEST_METHOD(Array_Report_Asce)
		{
			// Inserting values in ascending order
			IntSetArray test(max_e, max_v);
			
			for (i = 0; i < max_e; i++) {
				test.insert(max_e + i);
				expect[i] = max_e + i;
			}

			test.report(v);
			std::sort(expect, expect + max_e);

			// Comparing expected values and result values
			for (i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
					break;
				}
			}

			Assert::AreEqual(true, result_equal);
		}

		TEST_METHOD(Array_Report_Rand)
		{
			j = 0;
			// Inserting random values
			IntSetArray test(max_e, max_v);
			for (i = 0; i < max_e; i++) {
				temp = bigrand(max_v);
				test.insert(temp);

				if (dupCheck(temp, max_e, expect)) continue;

				expect[j++] = temp;
			}

			test.report(v);
			std::sort(expect, expect + j);

			// Comparing expected values and result values
			for (i = 0; i < j; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
					break;
				}
			}

			Assert::AreEqual(true, result_equal);
		}

	};
}