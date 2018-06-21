#include "IntSetArray.cpp"
#include "IntSetList.cpp"
#include "IntSetBST.cpp"
#include "IntSetBitVec.cpp"
#include "IntSetBins.cpp"

int main(void) {
	int max_v = 1000000;
	//int max_v = 100000000;

	int max_e = max_v / 100;
	//int max_e = max_v / 50;
	//int max_e = max_v / 25;

	int *v = new int[max_e];
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
	/*
	//code for IntSetBST
	IntSetBST S(max_e, max_v);
	while (S.size() < max_e)	S.insert(bigrand(max_v));
	S.report(v);
	for (int i = 0; i < max_e; i++)
		if (!(i % 100)) std::cout << v[i] << "\n";
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
}