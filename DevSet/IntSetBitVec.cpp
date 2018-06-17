#include "IntSet.cpp"

/*
	Implementation using bit vector
	time complexity: O(n + k) (k: max_value)
	space complexity: O(n + k) (k: max_value)
*/

class IntSetBitVec : IntSet {
private:
	enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };

	int n, *bitvec;

	void set(int i) { bitvec[i >> SHIFT] |= (1 << (i & MASK)); }

	void clr(int i) { bitvec[i >> SHIFT] &= ~(1 << (i & MASK)); }

	int test(int i) { return bitvec[i >> SHIFT] & (1 << (i & MASK)); }

public:
	IntSetBitVec(int max_elements, int max_value){
		set_maxelems(max_elements);
		set_maxval(max_value);
		bitvec = new int[1 + get_maxval() / BITSPERWORD];
		for (int i = 0; i < get_maxval(); i++) clr(i);
		n = 0;
	}

	int size() { return n; }

	void insert(int num){
		if (test(num)) return;
		set(num);
		n++;
	}

	void report(int *v){
		int j = 0;
		for (int i = 0; i < get_maxval(); i++)
			if (test(i)) v[j++] = i;
	}

};