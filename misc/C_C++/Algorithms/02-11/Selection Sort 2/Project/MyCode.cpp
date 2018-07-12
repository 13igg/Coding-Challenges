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

void selection_sort2(vector<int>& v)
{
	for(size_t i = 0; i < v.size(); i++)
	{
		int min_index = i;
		for(size_t j = v.size() - 1; j > i; j--)
			if(v[min_index] > v[j])
				min_index = j;
		swap(v[min_index], v[i]);
	}
}
int main()
{
	vector<int> v(100);
	for(int i = 0; i < 100; i++)
		v[i] = rand() % 1000 + 1;

	print(v);
	selection_sort2(v);
	print(v);

	system("pause");
	return 0;
}


