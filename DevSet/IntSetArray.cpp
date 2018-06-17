#include "IntSet.cpp"

/*
	Implementation using array (counting sort)
	time complexity: O(n + k) (k: max_value)
	space complexity: O(n + k) (k: max_value)
*/

class IntSetArray : IntSet {
private:
	int n = 0;
	bool *arr;

public:
	IntSetArray(int max_elements, int max_value) {
		set_maxelems(max_elements);
		set_maxval(max_value);
		arr = new bool[get_maxval()+1];
		//initialize arr
		for (int i = 0; i < get_maxval() + 1; i++)
			arr[i] = 0;
		n = 0;
	}

	int size() { return n; }

	void insert(int num) {
		// if num is not in arr
		if (!arr[num]){	
			arr[num] = true;
			n++;
		}
	}

	void report(int *v) {
		int j = 0;
		for (int i = 0; i < get_maxval() + 1; i++)
			if (arr[i]) v[j++] = i;
	}
};