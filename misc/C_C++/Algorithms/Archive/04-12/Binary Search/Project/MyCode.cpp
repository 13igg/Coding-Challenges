//Binary Search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int iterative_binary_search(vector<int>& v, int target)
{
	int low = 0, hi = (int) v.size() - 1;
	while(low <= hi)
	{
		int mid = (low + hi) / 2;
		if(target < v[mid])
			hi = mid - 1;
		else if(target > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int recursive_binary_search(vector<int>& v, int target, int low, int hi)
{
	if(low > hi)
		return -1;
	int mid = (low + hi) / 2;
	if(target < v[mid])
		return recursive_binary_search(v, target, low, mid - 1);
	else if(target > v[mid])
		return recursive_binary_search(v, target, mid + 1, hi);
	else
		return mid;
}

int main()
{
	//Put N random numbers in a vector and sort it.
	const int N = 500;
	vector<int> v(N);
	for(int i = 0; i < N; i++)
		v[i] = rand() % 1000;
	sort( v.begin(), v.end() );

	//For the numbers from 20 through 30, find their index in the vector.
	for(int i = 20; i <= 30; i++)
		cout << i << ' ' << iterative_binary_search(v, i) << endl;
	for(int i = 20; i <= 30; i++)
		cout << i << ' ' << recursive_binary_search(v, i, 0, (int) v.size() - 1) << endl;
	

	system("pause");
	return 0;
}


