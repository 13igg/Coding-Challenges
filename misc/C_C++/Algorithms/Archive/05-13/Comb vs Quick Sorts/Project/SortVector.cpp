//SortVector.cpp
#include <iostream>
#include <algorithm>
#include "SortVector.h"

///////////////////////////////////////////////////////////////////////
//CONSTRUCTORS
///////////////////////////////////////////////////////////////////////
SortVector::SortVector(int size)
:std::vector<int>(size)
{
	for(int i = 0; i < size; i++)
		(*this)[i] = i + 1;
	std::random_shuffle(this -> begin(), this -> end());
}
SortVector::SortVector(vector<int>& v)
:std::vector<int>(v)
{

}
SortVector::SortVector(int a[], int size)
:std::vector<int>(size)
{
	for(int i = 0; i < size; i++)
		(*this)[i] = a[i];
}
///////////////////////////////////////////////////////////////////////
//MUTATORS
///////////////////////////////////////////////////////////////////////
void SortVector::reverse()
{
	std::reverse(this -> begin(), this -> end());
}
void SortVector::reverse_sort()
{
	sort();
	reverse();
}
void SortVector::shuffle()
{
	std::random_shuffle(this -> begin(), this -> end());
}
void SortVector::sort()
{
	std::sort(this -> begin(), this -> end());
}
///////////////////////////////////////////////////////////////////////
//OTHER METHODS
///////////////////////////////////////////////////////////////////////
void SortVector::bubble(int pos)
{
	if(pos < 0)
		pos = 0;
	if(pos >= this -> size())
		return;
	for(int i = this -> size() - 1; i > pos; i--)
		comp_exch(i-1,i);
}
bool SortVector::comp_exch(int pos1, int pos2)
{
	if(pos1 < 0 || pos2 < 0 || pos1 >= this -> size() || pos2 >= this -> size())
		return false;
	if((*this)[pos1] > (*this)[pos2])
	{
		std::swap( (*this)[pos1], (*this)[pos2] );
		return true;
	}
	return false;
}
bool SortVector::is_sorted()
{
	for(int i = 0; i < this -> size(); i++)
		if((*this)[i] != i+1)
			return false;
	return true;
}
void SortVector::print(int n)
{
	if(this -> size() == 0)
		return;

	//Print the first and last n elements, or fewer if vector is small
	if(this -> size() / 2 < n)
	{
		for(int i = 0; i < this -> size(); i++)
			std::cout << (*this)[i] << " ";
		std::cout << std::endl;
		return;
	}
	//if(n > this -> size())
	//	n = this -> size();

	for(vector<int>::iterator i = this -> begin(); i < this -> begin() + n; i++)
	{
		std::cout << *i << " ";
	}

	std::cout << ". . . ";

	for(vector<int>::iterator i = this -> end() - n; i < this -> end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl;
}
int SortVector::size()
{
	return (int) vector<int>::size();
}
void SortVector::swap_min(int pos)
{
	if(pos < 0)
		pos = 0;
	if(pos >= this -> size())
		return;
	int min_index = pos;
	for(int i = pos + 1; i < this -> size(); i++)
		if((*this)[i] < (*this)[min_index])
			min_index = i;
	std::swap((*this)[pos], (*this)[min_index]);
}
/////////////////////////////////////
static int elapsed__time = 0;
void begin_timer()
{
	elapsed__time = clock();
}
int end_timer()
{
	return clock() - elapsed__time;
}




