#include "IntSetArray.cpp"
#include "IntSetList.cpp"
#include "IntSetBST.cpp"
#include "IntSetBitVec.cpp"
#include "IntSetBins.cpp"

bool dupCheck(int target, int max_e, int *expect) {
	/*
	Duplication check implemented based on binary search which takes o(log n) on average
	*/

	int low = 0;
	int mid = 0;
	int high = max_e - 1;

	int midVal;

	while (low <= high) {
		mid = (low + high) >> 1;
		midVal = expect[mid];

		if (midVal < target) low = mid + 1;
		else if (midVal > target) high = mid - 1;
		else return true;
	}

	return false;
}

int main(void) {
	/*
	int max_v = 1000000;
	//int max_v = 100000000;

	int max_e = max_v / 100;
	//int max_e = max_v / 50;
	//int max_e = max_v / 25;

	int *v = new int[max_e];
	*/
	/*
	//code for IntSetArray
	IntSetArray S(max_e, max_v);
	while (S.size() < max_e)	S.insert(bigrand(max_v));
	S.report(v);
	for (int i = 0; i < max_e; i++)
		if (!(i % 100)) std::cout << v[i] << "\n";
	*/
	/*
	//code for IntSetList
	IntSetList S(max_e, max_v);
	while (S.size() < max_e)	S.insert(bigrand(max_v));
	S.report(v);
	for (int i = 0; i < max_e; i++)
		if (!(i % 100)) std::cout << v[i] << "\n";
	*/
	
	//code for IntSetBST
	/*
	IntSetBST S(max_e, max_v);
	while (S.size() < max_e)	S.insert(bigrand(max_v));
	S.report(v);
	for (int i = 0; i < max_e; i++)
		if (!(i % 100)) std::cout << v[i] << "\n";
	int a;
	std::cin >> a;
	*/
	/*	
	//code for IntSetBitVec
	IntSetBitVec S(max_e, max_v);
	while (S.size() < max_e)	S.insert(bigrand(max_v));
	
	S.report(v);
	for (int i = 0; i < max_e; i++)
		if(!(i % 100)) std::cout << v[i] << "\n";
	*/
	/*
	//code for IntSetBins
	IntSetBins S(max_e, max_v);
	while (S.size() < max_e)	S.insert(bigrand(max_v));
	S.report(v);
	for (int i = 0; i < max_e; i++)
		if(!(i % 100)) std::cout << v[i] << "\n";
	*/

	int max_v = 1000000;
	int max_e = max_v / 100;
	int *v = new int[max_e];
	int *expect = new int[max_e]; // Expected values;
	bool result_equal = true;

	int i, j, temp=0;

	// Inserting random values
	IntSetArray test(max_e, max_v);
	for (i = test.size(); i < max_e; i++) {
		temp = bigrand(max_v);
		test.insert(temp);
		expect[i] = temp;
	}

	test.report(v);
	std::sort(expect, expect + max_e);

	// Comparing expected values and result values
	for (i = 0; i < max_e; i++) {
		cout << "[" << i << "]" << expect[i] << ", " << v[i] << endl;
		if (expect[i] != v[i]) {
			cout << "[" << i << "]" << expect[i+1] << ", " << v[i+1] << endl;
			result_equal = false;
			break;
		}
	}

	int a;
	cin >> a;
}