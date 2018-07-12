//Merge Sort with Improvements
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

void merge(int v[], int u[], int first, int mid, int last)
{
	for(int i = first; i <= last; i++)
		u[i] = v[i];

	int left = first, right = mid + 1;
	for(int pos = first; pos <= last; pos++)
	{
		if(left > mid)
			v[pos] = u[right++];
		else if(right > last)
			v[pos] = u[left++];
		else if(u[left] <= u[right])
			v[pos] = u[left++];
		else
			v[pos] = u[right++];
	}
}
void merge_sort(int v[], int u[], int first, int last)
{
	if(first == last)
		return;
	int mid = (first + last) / 2;
	merge_sort(v, u, first, mid);
	merge_sort(v, u, mid + 1, last);
	merge(v, u, first, mid, last);
}
void merge_sort(int v[], int size)
{
	int* u = new int[size];
	merge_sort(v, u, 0, size - 1);
	delete[] u;
}
bool is_sorted(int v[], int size)
{
	for(int i = 1; i < size; i++)
		if(v[i-1] > v[i])
			return false;
	return true;
}

int main()
{
	const int N = 100000;
	int v[N];
	for(int i = 0; i < N; i++)
		v[i] = i + 1;
	random_shuffle(v, v + N);

	int begin, end;

	begin = clock();
	merge_sort(v, N);
	end = clock();
	if(is_sorted(v, N))
		cout << "MergeSort run time on 100000 elements in millisecs: " << end - begin << endl;

	system("pause");
	return 0;
}



