//Swap Saver Bubble Sort -- This code is missing a crucial piece!
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

void swap_saver_bubble_sort(vector<int>& v)
{
	for(size_t left = 0; left < v.size(); left++)
	{
		int save = v[v.size() - 1];
		for(size_t right = v.size() - 1; right > left; right--)
		{
			if(v[right-1] > save)
			{
				v[right] = v[right - 1];
			}
			else
			{
				v[right] = save;
				save = v[right-1];
			}
		}
	}
}

int main()
{
	srand(time(NULL));

	vector<int> v(100);
	for(int i = 0; i < 100; i++)
		v[i] = rand() % 1000 + 1;

	print(v);
	swap_saver_bubble_sort(v);
	print(v);

	system("pause");
	return 0;
}


