//Shaker Sort
#include <iostream>
#include <vector>
#include <ctime> 
using namespace std;

bool is_sorted(vector<int>& v)
{
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[i-1])
			return false;
	return true;
}
int bubble_sort(vector<int>& v)
{
	int num_comps = 0;
	for(size_t i = 0; i < v.size(); i++)
		for(size_t j = v.size() - 1; j > i; j--)
		{
			num_comps++;
			if(v[j] < v[j-1])
			{
				swap(v[j-1],v[j]);
			}
		}
	return num_comps;	//Returns the number of comparisons
}

int shaker_sort(vector<int>& v)
{
	int num_comps = 0;
	bool did_swap = true;
	for(int inset = 1; did_swap; inset++)
	{
		did_swap = false;
		//bubble left
		for(int j = (int) v.size() - inset; j >= inset; j--)
		{
			num_comps++;
			if(v[j-1] > v[j])
			{
				swap(v[j-1],v[j]);
			}
		}

		//bubble right
		for(int j = inset; j < v.size() - inset; j++)
		{
			num_comps++;
			if(v[j] > v[j+1])
			{
				swap(v[j],v[j+1]);
				did_swap = true;
			}
		}
	}
	return num_comps;	//Returns the number of comparisons

}
int main()
{
	srand(time(NULL));
	vector<int> v(100), w(100); 
	for(int i = 0; i < 100; i++)
		v[i] = w[i] = rand() % 1000 + 1;

	cout << bubble_sort(w) << " comparisons for bubble sort" << endl;
	if(is_sorted(w))
		cout << "Is sorted\n";

	cout << shaker_sort(v) << " comparisons for bubble sort" << endl;
	if(is_sorted(v))
		cout << "Is sorted\n";

	system("pause");
	return 0;
}


