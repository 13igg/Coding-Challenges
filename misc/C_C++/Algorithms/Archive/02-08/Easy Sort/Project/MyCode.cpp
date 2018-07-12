//Easy Sort
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

//A function for printing vectors of integers
void print(vector<int>& v)
{
	for(size_t i = 0; i < v.size(); i++)
		cout << setw(5) << v[i];
	cout << endl << endl;
}
//Easy Sort on vectors of integers
void easy_sort(vector<int>& v)
{
	for(size_t left = 0; left < v.size(); left++)
		for(size_t right = left + 1; right < v.size(); right++)
			if(v[left] > v[right])
				swap(v[left], v[right]);
}
//A generic Easy Sort
template <typename T>
void easy_sort(T& v)
{
	for(size_t left = 0; left < v.size(); left++)
		for(size_t right = left + 1; right < v.size(); right++)
			if(v[left] > v[right])
				swap(v[left], v[right]);
}
int main()
{
	srand(time(NULL));			//See the random number generator

	//Make a vector of 100 random numbers from 1-1000
	vector<int> v;
	for(int i = 0; i < 100; i++)
	{
		v.push_back(rand()% 1000 + 1);
	}

	//Show the vector before and after the sort
	print(v);
	easy_sort(v);
	print(v);

	//Note that we can even sort strings
	string s = "CARTHAGE";
	easy_sort(s);
	cout << s << endl << endl;

	system("pause");
	return 0;
}


