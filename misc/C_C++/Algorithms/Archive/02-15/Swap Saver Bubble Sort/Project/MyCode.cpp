//Swap Saver Bubble Sort
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
bool is_sorted(vector<int>& v)
{
	for(int i = 1; i < (int) v.size() - 1; i++)
		if(v[i] < v[i-1])
			return false;
	return true;
}
int bubble_sort(vector<int>& v)
{
	int num_asn = 0;
	for(int i = 0; i < v.size(); i++)
		for(int j = v.size() - 1; j > i; j--)
		{
			if(v[j] < v[j-1])
			{
				swap(v[j-1], v[j]);
				num_asn += 3;
			}
		}
	return num_asn;
}
int swap_saver_bubble_sort(vector<int>& v)
{
	int num_asn = 0;
	for(size_t left = 0; left < v.size(); left++)
	{
		int save = v[v.size() - 1];
		num_asn++;
		for(size_t right = v.size() - 1; right > left; right--)
		{
			if(v[right-1] > save)
			{
				v[right] = v[right - 1];
				num_asn++;
			}
			else
			{
				v[right] = save;
				save = v[right-1];
				num_asn += 2;
			}
		}
		v[left] = save;
	}
	return num_asn;
}

int main()
{
	srand(time(NULL));
	int num_assignments;

	cout << "Bubble Sort on Random Data: ";
	vector<int> v(100);
	for(int i = 0; i < 100; i++)
		v[i] = rand() % 1000 + 1;
	num_assignments = bubble_sort(v);
	if(is_sorted(v))
		cout << num_assignments << endl;

	cout << "Bubble Sort on Reversed Data: ";
	for(int i = 0; i < 100; i++)
		v[i] = 100 - i;
	num_assignments = bubble_sort(v);
	if(is_sorted(v))
		cout << num_assignments << endl;

	cout << "Swap Saver Bubble Sort on Random Data: ";
	for(int i = 0; i < 100; i++)
		v[i] = rand() % 1000 + 1;
	num_assignments = swap_saver_bubble_sort(v);
	if(is_sorted(v))
		cout << num_assignments << endl;

	cout << "Swap Saver Bubble Sort on Reversed Data: ";
	for(int i = 0; i < 100; i++)
		v[i] = 100 - i;
	num_assignments = swap_saver_bubble_sort(v);
	if(is_sorted(v))
		cout << num_assignments << endl;

	system("pause");
	return 0;
}


