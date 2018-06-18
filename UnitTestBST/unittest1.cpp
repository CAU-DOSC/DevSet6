#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DevSet\IntSetBST.cpp"
#include "..\DevSet\util_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBST
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int max_v = 1000000;
			int max_e = max_v / 100;
			int *v = new int[max_e];
			int *expect = new int[max_e]; // 테스트 기댓값;
			bool result_equal = true;
			IntSetBST test(max_e, max_v);

			for (int i = max_e-1; i >= 0; i--) {
				test.insert(i);
				expect[i] = i;
			}

			// TODO: 테스트 코드를 여기에 입력합니다.
			test.report(v);

			/* 정렬된 값이랑 기대한 값이랑 같은가 */
			for (int i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
				}
			}

			Assert::AreEqual(0,v[0]); // 가장 작은 값이 맨 처음인가?
			Assert::AreEqual(max_e - 1, v[max_e - 1]); // 가장 큰 값이 맨 마지막인가?
			Assert::AreEqual(true,result_equal); // 기대값이랑 정렬된 값이 같나?
		}

	};
}