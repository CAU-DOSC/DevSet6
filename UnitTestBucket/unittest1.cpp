#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DevSet\IntSetBins.cpp"
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
			int *expect = new int[max_e];
			bool result_equal = true;
			IntSetBins test(max_e, max_v);
			
			for (int i = max_e-1; i >= 0; i--) {
				test.insert(i);
				expect[i] = i;
			}

			test.report(v);

			for (int i = 0; i < max_e; i++) {
				if (expect[i] != v[i]) {
					result_equal = false;
				}
			}

			Assert::AreEqual(0,v[0]); 
			Assert::AreEqual(max_e - 1, v[max_e - 1]);
			Assert::AreEqual(true,result_equal); 
		}

	};
}