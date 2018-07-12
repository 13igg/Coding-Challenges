//SortVector.h
#ifndef SORT_VECTOR_H
#define SORT_VECTOR_H

#include <vector>
#include <ctime>
#include <string>

class SortVector: public std::vector<int>
{
public:
	//CONSTRUCTORS
	SortVector(int size = 10);		//1..size randomly shuffled
	SortVector(vector<int>& v);
	SortVector::SortVector(int a[], int size);

	//MUTATORS
	void reverse();
	void reverse_sort();
	void shuffle();
	void sort();
	template <typename T> void sort(T f, std::string label);

	//OTHER METHODS

	//Move the least element from index pos onward into index pos via incremental swaps
	  void bubble(int pos = 0);
	//If the element at pos1 exceeds the element at pos2, swap
	  bool comp_exch(int pos1, int pos2);
	//Return true if sorted
	  bool is_sorted();
	//Print n first and n last elements
	  void print(int n = 3);
	//Return number of elements as an int
	  int size();
	//Swap the least from index pos onward into index pos
	  void swap_min(int pos = 0);
};

void begin_timer();
int end_timer();		//Return milliseconds since call to begin_timer();

template <typename T> 
void SortVector::sort(T f, std::string label)
{
	int end;
	begin_timer();
	f(*this);
	end = end_timer();
	if(is_sorted())
		cout << label << " Time: " << end << endl;
	else
	{
		cout << "Sort failed: ";
		print();
	}
}



#endif