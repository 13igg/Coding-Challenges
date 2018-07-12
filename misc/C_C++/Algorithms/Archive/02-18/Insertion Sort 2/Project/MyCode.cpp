//Insertion Sorts
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
void insertion_sort2(vector<int>& v)
{
	if(v.size() == 0)
		return;
	int least = 0;
	for(int i = 1; i < (int) v.size(); i++)
		if(v[i] < v[least])
			least = i;
	swap(v[0], v[least]);

	for(int right = 1; right < (int) v.size(); right++)
	{
		for(int i = right; v[i-1] > v[i]; i--)
			swap(v[i-1], v[i]);
	}
}

int main()
{
	srand(time(NULL));
	vector<int> v(1000), w(1000);
	for(int i = 0; i < 1000; i++)
		v[i] = w[i] = rand() % 1000 + 1;

	insertion_sort2(w);
	if(is_sorted(w))
		cout << "The vector is sorted.\n";

	system("pause");
	return 0;
}


