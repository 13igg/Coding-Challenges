//In Class February 20
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void print(vector<T>& v, int n = 3);	//Print n first and n last elements

//Public inheritance allows us to publically use the vector stuff, like .size().
class SortVector: public vector<int>
{
public:
	SortVector(int size = 0);
};

int main()
{
	//This illustrates using random_shuffle from the algorithms library
	string s = "doghouse";
	random_shuffle(s.begin() + 3, s.end());
	cout << s << endl;

	SortVector v(10);
	print(v);
	print(v, 4);
	
	system("pause");
	return 0;
}

template <typename T>
void print(vector<T>& v, int n)
{
	if(v.size() == 0)
		return;

	//Print the first and last n elements, or fewer if vector is small
	if(v.size() < n)
		n = v.size();

	for(vector<T>::iterator i = v.begin(); i < v.begin() + n; i++)
	{
		cout << *i << " ";
	}

	cout << ". . . ";

	for(vector<T>::iterator i = v.end() - n; i < v.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;
}

SortVector::SortVector(int size)
:vector<int>(size)		//Calls the appropriate vector<int> constructor
{

}