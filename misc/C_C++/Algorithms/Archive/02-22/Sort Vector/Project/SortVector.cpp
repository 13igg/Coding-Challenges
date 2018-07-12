//SortVector.cpp
#include <iostream>
#include <algorithm>
#include "SortVector.h"

///////////////////////////////////////////////////////////////////////
//CONSTRUCTORS
///////////////////////////////////////////////////////////////////////
SortVector::SortVector(int size)
:vector<int>(size)
{
	for(int i = 0; i < size; i++)
		(*this)[i] = i + 1;
	random_shuffle(begin(), end());
}
SortVector::SortVector(vector<int>& v)
:vector<int>(v)
{

}
SortVector::SortVector(int a[], int size)
:vector<int>(size)
{
	for(int i = 0; i < size; i++)
		(*this)[i] = a[i];
}
///////////////////////////////////////////////////////////////////////
//MUTATORS
///////////////////////////////////////////////////////////////////////
void SortVector::reverse()
{
	std::reverse(begin(), end());
}
void SortVector::reverse_sort()
{
	sort();
	reverse();
}
void SortVector::shuffle()
{
	std::random_shuffle(begin(), end());
}
void SortVector::sort()
{
	std::sort(begin(), end());
}
bool SortVector::comp_exch(int pos1, int pos2)
{
	if((*this)[pos1] > (*this)[pos2])
	{
		std::swap( (*this)[pos1], (*this)[pos2] );
		return true;
	}
	return false;
}
void SortVector::swap_min(int pos)
{
	if(pos < 0)
		pos = 0;
	int min_index = pos;
	for(int i = pos + 1; i < (int) size(); i++)
		if((*this)[i] < (*this)[min_index])
			min_index = i;
	std::swap((*this)[pos], (*this)[min_index]);
}
void SortVector::bubble(int pos)
{
	if(pos < 0)
		pos = 0;
	for(int i = (int) size() - 1; i > pos; i--)
		comp_exch(i-1,i);
}
///////////////////////////////////////////////////////////////////////
//OTHER METHODS
///////////////////////////////////////////////////////////////////////
void SortVector::print(int n)
{
	if(size() == 0)
		return;

	//Print the first and last n elements, or fewer if vector is small
	if(size() < n)
		n = size();

	for(vector<int>::iterator i = begin(); i < begin() + n; i++)
	{
		std::cout << *i << " ";
	}

	std::cout << ". . . ";

	for(vector<int>::iterator i = end() - n; i < end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl;
}
bool SortVector::is_sorted()
{
	for(size_t i = 1; i < size(); i++)
		if((*this)[i-1] > (*this)[i])
			return false;
	return true;
}

