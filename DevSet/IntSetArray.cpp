#include "IntSet.cpp"

/*
	Implementation using array (counting sort)
	time complexity: O(n + k) (k: max_value)
	space complexity: O(n + k) (k: max_value)
*/

class IntSetArray : IntSet {
private:
	int n;
	bool *arr;

public:
	// constructor
	IntSetArray(int max_elements, int max_value) {
		set_maxelems(max_elements);
		set_maxval(max_value);
		
		/*
		This code occurs sparsity problem of array resulting in waste of memory
		but it is necessary to compromise (time complexity and space complexity)
		By giving up space complexity, it is definitely expected to reduce time complexity
		and not to sort the array when it comes to inserting or printing values.
		*/

		arr = new bool[max_value];

		//initialize arr
		for (int i = 0; i < max_value; i++) {
			arr[i] = false;
		}
			
		n = 0;
	}

	int size() { return n; }

	void insert(int num) {
		/*
		Checking whether incoming number 'n' is already in array
		This process takes only the time complexity of O(1),
		*/
		if (!arr[num]){	
			arr[num] = true;
			n++;
		}
	}

	void report(int *v) {
		int j = 0;
		for (int i = 0; i < get_maxval() + 1; i++) {
			if (arr[i]) v[j++] = i;
		}
	}
};