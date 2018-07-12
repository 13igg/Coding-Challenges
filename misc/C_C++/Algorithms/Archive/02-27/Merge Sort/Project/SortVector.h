//SortVector.h
#ifndef SORT_VECTOR_H
#define SORT_VECTOR_H

#include <vector>

class SortVector: public std::vector<int>
{
public:
	//CONSTRUCTORS
	SortVector(int size = 0);
	SortVector(vector<int>& v);
	SortVector::SortVector(int a[], int size);

	//MUTATORS
	void reverse();
	void reverse_sort();
	void shuffle();
	void sort();

	//If the element at pos1 exceeds the element at pos2, swap
	bool comp_exch(int pos1, int pos2);

	//Swap the minimum from index pos onward into index pos
	void swap_min(int pos = 0);

	//Move the least element from pos onward into index pos via incremental swaps
	void bubble(int pos = 0);

	//OTHER METHODS
	void print(int n = 3);	//Print n first and n last elements
	bool is_sorted();
};

#endif