//SortVector.h
#ifndef SORT_VECTOR_H
#define SORT_VECTOR_H

#include <vector>
template <typename T>
class SortVector: public std::vector<T>
{
public:
	//CONSTRUCTORS
	SortVector(int size = 0);
	SortVector(vector<T>& v);
	SortVector(T a[], int size);
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

///////////////////////////////////////////////////////////////////////
//CONSTRUCTORS

template <typename T>
SortVector<T>::SortVector(int size)
:vector<T>(size)
{
	//for(int i = 0; i < size; i++)
	//	(*this)[i] = i + 1;
	//random_shuffle(begin(), end());
}
template <typename T>
SortVector<T>::SortVector(vector<T>& v)
:vector<T>(v)
{
	//random_shuffle(begin(), end());
}

template <typename T>
SortVector<T>::SortVector(T a[], int size)
:vector<T>(size)
{
	for(int i = 0; i < size; i++)
		(*this)[i] = a[i];
}

///////////////////////////////////////////////////////////////////////
//MUTATORS
///////////////////////////////////////////////////////////////////////
template <typename T>
void SortVector<T>::reverse()
{
	std::reverse(begin(), end());
}
template <typename T>
void SortVector<T>::reverse_sort()
{
	sort();
	reverse();
}
template <typename T>
void SortVector<T>::shuffle()
{
	std::random_shuffle(begin(), end());
}
template <typename T>
void SortVector<T>::sort()
{
	std::sort(begin(), end());
}
template <typename T>
bool SortVector<T>::comp_exch(int pos1, int pos2)
{
	if((*this)[pos1] > (*this)[pos2])
	{
		std::swap( (*this)[pos1], (*this)[pos2] );
		return true;
	}
	return false;
}
template <typename T>
void SortVector<T>::swap_min(int pos)
{
	if(pos < 0)
		pos = 0;
	int min_index = pos;
	for(int i = pos + 1; i < (int) size(); i++)
		if((*this)[i] < (*this)[min_index])
			min_index = i;
	std::swap((*this)[pos], (*this)[min_index]);
}
template <typename T>
void SortVector<T>::bubble(int pos)
{
	if(pos < 0)
		pos = 0;
	for(int i = (int) size() - 1; i > pos; i--)
		comp_exch(i-1,i);
}
///////////////////////////////////////////////////////////////////////
//OTHER METHODS
///////////////////////////////////////////////////////////////////////
template <typename T>
void SortVector<T>::print(int n)
{
	if(size() == 0)
		return;

	//Print the first and last n elements, or fewer if vector is small
	if(size() < n)
		n = size();

	for(vector<T>::iterator i = begin(); i < begin() + n; i++)
	{
		std::cout << *i << " ";
	}

	std::cout << ". . . ";

	for(vector<T>::iterator i = end() - n; i < end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl;
}
template <typename T>
bool SortVector<T>::is_sorted()
{
	for(size_t i = 1; i < size(); i++)
		if((*this)[i-1] > (*this)[i])
			return false;

	return true;
}




#endif