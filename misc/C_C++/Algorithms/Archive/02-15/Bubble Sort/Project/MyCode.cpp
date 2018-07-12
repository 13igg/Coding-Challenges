//Bubble Sort
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;

void print(vector<int>& v)
{
	for(size_t i = 0; i < v.size(); i++)
		cout << setw(5) << v[i];
	cout << endl << endl;
}

void bubble_sort(vector<int>& v)
{
	for(size_t left = 0; left < v.size(); left++)
		for(size_t right = v.size() - 1; right > left; right--)
			if(v[right-1] > v[right])
				swap(v[right-1], v[right]);
}

int main()
{
	srand(time(NULL));

	vector<int> v(100);
	for(int i = 0; i < 100; i++)
		v[i] = rand() % 1000 + 1;

	print(v);
	bubble_sort(v);
	print(v);

	system("pause");
	return 0;
}


