//Selection Sort - Majorly Weird Findings
#include <iostream>
#include "SortVector.h"
using namespace std;

//Selection sort searching from the left
void selection_sort1(SortVector& v)
{
	int min_index;
	for(int i = 0; i < v.size(); i++)
	{
		min_index = i;
		for(int j = i + 1; j < v.size(); j++)
			if(v[j] < v[min_index])
				min_index = j;
		swap(v[i], v[min_index]);
	}
}
//Selection sort searching from the right
void selection_sort2(SortVector& v)
{
	int min_index;
	for(int i = 0; i < v.size(); i++)
	{
		min_index = v.size() - 1;
		for(int j = v.size() - 2; j >= i ; j--)
			if(v[j] < v[min_index])
				min_index = j;
		swap(v[i], v[min_index]);
	}
}
//Selection sort searching from the right
//and avoiding a self-swap
void selection_sort3(SortVector& v)
{
	int min_index;
	for(int i = 0; i < v.size(); i++)
	{
		min_index = v.size() - 1;
		for(int j = v.size() - 2; j > i ; j--)
			if(v[j] < v[min_index])
				min_index = j;
		if(v[i] > v[min_index])
			swap(v[i], v[min_index]);
	}
}

int main()
{
	srand(time(NULL));

	int end;
	SortVector v(50000);
	SortVector w(v);

	cout << "Random Data\n";
	w = v;
	begin_timer();
	selection_sort1(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "1: " << end << endl;

	w = v;
	begin_timer();
	selection_sort2(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "2: " << end << endl;

	w = v;
	begin_timer();
	selection_sort3(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "3: " << end << endl;

	cout << "Sorted Data\n";
	v.sort();
	w = v;
	begin_timer();
	selection_sort1(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "1: " << end << endl;

	w = v;
	begin_timer();
	selection_sort2(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "2: " << end << endl;

	w = v;
	begin_timer();
	selection_sort3(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "3: " << end << endl;

	system("pause");
	return 0;
}


/*
	for(int i = 1; i <= 5; i++)
	{
		int a = rand()%50000;
		int b = rand()%50000;
		swap(v[a],v[b]);
	}
*/



