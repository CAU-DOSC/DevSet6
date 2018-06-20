#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DevSet\IntSetBST.cpp"
#include "../DevSet/util_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBST
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int max_v = 1000000;
		int max_e = max_v / 100;
		int *v = new int[max_e];
		int *expect = new int[max_e]; // 테스트 기댓값;
		bool result_equal = true;

		int bigrand(int v) {
			int r = 0;

			// this will generate a Integer using 30bit(larger than 10^8)
			for (int i = 0; i < 2; ++i) {
				r = (r << 15) | (rand() & 0x7FFF);
			}
			// return value: 0 to v
			return r % (v + 1);
		}

		/* 정렬하는 데 걸리는 시간 */
		TEST_METHOD(BST_Insert_Desc) // 내림차순 입력
		{
			IntSetBST test(max_e, max_v);
			int j = 0;
			for (int i = max_e - 1; i >= 0; i--) {
				test.insert(max_v - j);
				j++;
			}
		}
		TEST_METHOD(BST_Insert_Asce) // 오름차순 입력
		{
			IntSetBST test(max_e, max_v);
			int j = 0;
			for (int i = max_e - 1; i >= 0; i--) {
				test.insert(max_v - j);
				j++;
			}
		}
		TEST_METHOD(BST_Insert_Rand) // 랜덤 입력
		{
			IntSetBST test(max_e, max_v);
			int temp = 0;
			for (int i = test.size(); i < max_e; i++) {
				test.insert(bigrand(max_v));
			}
		}
		/* 총 정렬하는 데 걸리는 시간 및 성공 */
		TEST_METHOD(BST_Total_Desc)
		{
			IntSetBST test1(max_e, max_v);
			int j = 0;
			for (int i = max_e-1; i >= 0; i--) {
				test1.insert(max_v-j);
				expect[i] = max_v-j;
				j++;
			}

			test1.report(v);

			/* 정렬된 값이랑 기대한 값이랑 같은가 */
			for (int i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false; // 다르면 false
				}
			}

			Assert::AreEqual(true,result_equal); // 기대값이랑 정렬된 값이 같나?
		}
		TEST_METHOD(BST_Total_Rand)
		{
			IntSetBST test2(max_e, max_v);

			int temp = 0;
			for (int i = test2.size(); i < max_e; i++) {
				temp = bigrand(max_v);
				test2.insert(temp);
				expect[i] = temp;
			}

			test2.report(v);
			std::sort(expect, expect+(max_e));

			/* 정렬된 값이랑 기대한 값이랑 같은가 */
			for (int i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
				}
			}

			Assert::AreEqual(true, result_equal); // 기대값이랑 정렬된 값이 같나?
		}
		TEST_METHOD(BST_Total_Asce)
		{
			IntSetBST test3(max_e, max_v);

			int temp = 0;
			for (int i = 0; i < max_e; i++) {
				temp = max_v - max_e + i;
				test3.insert(temp);
				expect[i] = temp;
			}

			test3.report(v);
			std::sort(expect, expect + (max_e));

			/* 정렬된 값이랑 기대한 값이랑 같은가 */
			for (int i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
				}
			}

			Assert::AreEqual(true, result_equal); // 기대값이랑 정렬된 값이 같나?
		}
	};
}