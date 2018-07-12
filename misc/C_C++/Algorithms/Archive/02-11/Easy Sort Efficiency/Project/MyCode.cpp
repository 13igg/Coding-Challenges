//Benchmarks for Easy Sort
//Counting Swaps for initially reverse sorted data
#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

int count_swaps = 0;

void easy_sort(vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i + 1; j < v.size(); j++)
		{
			if(v[i] > v[j])
			{
				count_swaps++;
				swap(v[i],v[j]);
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	vector<int> v;
	for(int i = 0; i < 100; i++)
		v.push_back(101-i);
	easy_sort(v);
	cout << count_swaps << endl;

	system("pause");
	return 0;
}


