//Easy Shuffle
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

void print(vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
		cout << setw(5) << v[i];
	cout << endl << endl;
}
template <typename T>
void easy_shuffle(T& v)
{
	vector<int> w;
	for(size_t i = 0; i < v.size(); i++)
		w.push_back(rand() % 1000 + 1);
	for(int i = 0; i < w.size(); i++)
	{
		for(int j = i + 1; j < w.size(); j++)
		{
			if(w[i] > w[j])
			{
				swap(v[i], v[j]);
				swap(w[i], w[j]);
			}
		}
	}
}
int main()
{
	srand(time(NULL));

	vector<int> v;
	for(size_t i = 0; i < 100; i++)
		v.push_back(i+1);
	print(v);
	easy_shuffle(v);
	print(v);

	
	

	system("pause");
	return 0;
}


