//Examples of Templates
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Find the minimum of two integers
int minInt(int x, int y)
{
	if(x < y)
		return x;
	else
		return y;
}
//Find the minimum of two doubles
double minDouble(double x, double y)
{
	if(x < y)
		return x;
	else
		return y;
}
//Find the minimum of any two variables of same type
template <typename T>
T mini(T x, T y)
{
	if(x < y)
		return x;
	else
		return y;
}
//Print a vector of integers
void printVectorInt(vector<int> v)
{
	for(int i = 0; i < 3; i++)
		cout << v[i] << ' ';
	cout << endl;
}
//Print a vector of doubles
void printVectorDouble(vector<double> v)
{
	for(int i = 0; i < 3; i++)
		cout << v[i] << ' ';
	cout << endl;
}
//Print a vector of any type, even strings
template <typename T>
void printVector(vector<T> v)
{
	for(int i = 0; i < 3; i++)
		cout << v[i] << ' ';
	cout << endl;
}
//Print vectors or arrays
template <typename T>
void print(T v)
{
	for(int i = 0; i < 3; i++)
		cout << v[i] << ' ';
	cout << endl;
}
int main()
{
	int a = 3, b = 5;
	cout << minInt(a,b) << endl;

	double c = 3.0, d = 5.0;
	cout << minDouble(c,d) << endl;

	cout << mini(a,b) << endl;
	cout << mini(c,d) << endl;

	string e = "ape", f = "Zoo";
	cout << mini(e, f) << endl;

	vector<int> v(3);
	v[0] = v[1] = v[2] = 1;
	printVectorInt(v);

	vector<double> w(3);
	w[0] = w[1] = w[2] = 1.1;
	printVectorDouble(w);

	printVector(v);
	printVector(w);

	int arr[3] = {1,2,3};
	print(v);
	print(w);
	print(arr);

	system("pause");
	return 0;
}


