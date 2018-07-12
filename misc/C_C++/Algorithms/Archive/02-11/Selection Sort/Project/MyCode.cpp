#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void print(vector<int>& v)
{
	for(size_t i = 0; i < v.size(); i++)
		cout << setw(5) << v[i];
	cout << endl << endl;
}

void selection_sort(vector<int>& v)
{
	for(size_t left = 0; left < v.size(); left++)
	{
		int min_index = left;
		for(size_t right = left + 1; right < v.size(); right++)
		{
			if(v[min_index] > v[right])
				min_index = right;
		}
		swap(v[left], v[min_index]);
	}
}

int main()
{
	vector<int> v(100);
	for(int i = 0; i < 100; i++)
		v[i] = rand() % 1000 + 1;

	print(v);
	selection_sort(v);
	print(v);

	system("pause");
	return 0;
}


