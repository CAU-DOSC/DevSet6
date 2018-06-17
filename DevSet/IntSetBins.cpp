#include "IntSet.cpp"

/*
	Implementation using bins
	time complexity: 
		worst O(n^2)
		best O(n)
	space complexity: O(n))
*/

class IntSetBins : IntSet {
private:
	/*
		bins[0]: 0 ~ 9
		bins[1]: 10 ~ 100
		...
		bbins[7]: 10^6 ~ 10^7 + 10^8
	*/
	enum { MAXNUMOFBINS =  8};

	std::vector<int>* bins[MAXNUMOFBINS];

	int n;

	int test(int num) {
		int temp = num;
		int idx = 0;
		//find which bin the number is in
		while ((temp /= 10) > 0 && idx < 8)	idx++;
		//search the bin if it already has num in it
		for (std::vector<int>::iterator iter = bins[idx]->begin(); iter != bins[idx]->end(); iter++)
			if (num == *iter) return true;
		return false;
	}

	void set(int num) {
		int temp = num;
		int idx = 0;
		//find which bin to put the number in
		while ((temp /= 10) > 0 && idx < 8)	idx++;
		bins[idx]->push_back(num);
	}
public:
	IntSetBins(int max_elements, int max_value) {
		set_maxelems(max_elements);
		set_maxval(max_value);
		for (int i = 0; i < MAXNUMOFBINS; i++) {
			bins[i] = new std::vector<int>;
		}
		n = 0;
	}

	int size() { return n; }

	void insert(int num) {
		if (test(num)) return;
		set(num);
		n++;
	}

	void report(int *v) {
		int j = 0;
		//from bin 0 to bin 7
		for (int i = 0; i < MAXNUMOFBINS; i++){
			// if bin is empty, move on to next bin
			if (!bins[i]->size()) continue;
			// sort the bin
			std::sort(bins[i]->begin(), bins[i]->end());
			for(std::vector<int>::iterator iter = bins[i]->begin(); iter != bins[i]->end(); iter++)
				v[j++] = *iter;
		}
	}

};