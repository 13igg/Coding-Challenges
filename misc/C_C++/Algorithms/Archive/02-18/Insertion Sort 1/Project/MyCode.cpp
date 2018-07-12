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
void insertion_sort1(vector<int>& v)
{
	int num_asn = 0;
	for(int right = 1; right < (int) v.size(); right++)
	{
		int save = v[right];
		num_asn++;
		int i = right;
		while( i > 0 && v[i-1] > save )
		{
			v[i] = v[i-1];
			num_asn++;
			i--;
		}
		v[i] = save;
		num_asn++;
	}
	cout << num_asn << endl;
}
void insertion_sort(vector<int>& v)
{
	int num_asn = 0;
	for(int right = 1; right < (int) v.size(); right++)
	{
		for(int i = right; i > 0 && v[i-1] > v[i]; i--)
		{
			swap(v[i-1], v[i]);
			num_asn += 3;
		}
	}
	cout << num_asn << endl;
}

int main()
{
	srand(time(NULL));
	vector<int> v(1000), w(1000);
	for(int i = 0; i < 1000; i++)
		v[i] = w[i] = rand() % 1000 + 1;

	insertion_sort(v);
	if(is_sorted(v))
		cout << "The vector is sorted.\n";

	insertion_sort1(w);
	if(is_sorted(w))
		cout << "The vector is sorted.\n";

	system("pause");
	return 0;
}


