#include "IntSet.cpp"

/*
	Implementation using array (counting sort)
	time complexity: O(n + k) (k: max_value)
	space complexity: O(n + k) (k: max_value)
*/

class IntSetArray : IntSet {
private:
	int n;
	int *arr;
	int arr_i;

	bool dupCheck(int target) {
		/*
		Duplication check implemented based on binary search which takes o(log n) on average
		*/

		int low = 0;
		int mid = 0;
		int high = n - 1;

		int midVal;

		while (low <= high) {
			mid = (low + high) >> 1;
			midVal = arr[mid];

			if (midVal < target) low = mid + 1;
			else if (midVal > target) high = mid - 1;
			else return true;
		}

		return false;
	}

public:
	// constructor
	IntSetArray(int max_elements, int max_value) {
		set_maxelems(max_elements);
		set_maxval(max_value);
		
		/*
		This code occurs sparsity problem of array resulting in waste of memory
		but it is necessary to compromise (time complexity and space complexity)
		By giving up space complexity, it is definitely expected to reduce 
		*/

		arr = new bool[get_maxval()+1];

		//initialize arr
		for (int i = 0; i < max_elements + 1; i++) {
			arr[i] = false;
		}
			
		n = 0;
		arr_i = 0;
	}

	int size() { return n; }

	void insert(int num) {
		/*
		Checking whether incoming number 'n' is already in array
		Even though the process takes only the time complexity of o(1),
		in this way, too much of memory space is wasted
		
		if (!arr[num]){	
			arr[num] = true;
			n++;
		}
		*/

		if (!dupCheck(num)) {
			
		}
	}

	void report(int *v) {
		int j = 0;
		for (int i = 0; i < get_maxval() + 1; i++)
			if (arr[i]) v[j++] = i;
	}
};