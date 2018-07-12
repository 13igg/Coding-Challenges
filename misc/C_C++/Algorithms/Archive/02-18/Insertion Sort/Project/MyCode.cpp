//Insertion Sort
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool is_sorted(vector<int>& v)
{
	for(int i = 1; i < (int) v.size(); i++)
		if(v[i] < v[i-1])
			return false;
	return true;
}

void insertion_sort(vector<int>& v)
{
	for(int right = 1; right < (int) v.size(); right++)
	{
		for(int i = right; i > 0 && v[i-1] > v[i]; i--)
		{
			swap(v[i-1], v[i]);
		}
	}
}

int main()
{
	srand(time(NULL));
	vector<int> v(1000);
	for(int i = 0; i < 1000; i++)
		v[i] = rand() % 1000 + 1;

	insertion_sort(v);
	if(is_sorted(v))
		cout << "The vector is sorted.\n";

	system("pause");
	return 0;
}


