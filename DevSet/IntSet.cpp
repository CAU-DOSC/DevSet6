#ifndef INTSET__
#define INTSET__

#include "util_func.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

class IntSet {
private:
	int maxval;
	int maxelems;
public:
	//getter & setter methods
	void set_maxval(int v) {
		maxval = v;
	}
	int get_maxval() {
		return maxval;
	}
	void set_maxelems(int e) {
		maxval = e;
	}
	int get_maxelems() {
		return maxelems;
	}
	//abstract classes
	virtual void insert(int element) = 0;
	virtual int size() = 0;
	virtual void report(int *v) = 0;
};

#endif