//Bubble Sort vs. Adaptive Bubble Sort
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

int bubble_sort(vector<int>& v)
{
	int comps = 0;
	for(size_t left = 0; left < v.size(); left++)
	{
		for(size_t right = v.size() - 1; right > left; right--)
		{
			comps++;
			if(v[right-1] > v[right])
				swap(v[right-1], v[right]);
		}
	}
	return comps;
}
int adaptive_bubble_sort(vector<int>& v)
{
	int comps = 0;
	for(size_t left = 0; left < v.size(); left++)
	{
		bool no_swap = true;
		for(size_t right = v.size() - 1; right > left; right--)
		{
			comps++;
			if(v[right-1] > v[right])
			{
				swap(v[right-1], v[right]);
				no_swap = false;
			}
		}
		if(no_swap)
			break;
	}
	return comps;
}
int main()
{
	const int N = 1000;
	vector<int> v(N);

	srand(100);
	for(int i = 0; i < N; i++)
		v[i] = rand() % 1000 + 1;
	int comps1 = bubble_sort(v);

	srand(100);
	for(int i = 0; i < N; i++)
		v[i] = rand() % 1000 + 1;
	int comps2 = adaptive_bubble_sort(v);

	cout << fixed << setprecision(2);
	cout << 100.0 * (comps1 - comps2) / comps1 
		 << "% fewer comparisons." << endl;

	system("pause");
	return 0;
}


