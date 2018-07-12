//3x3 MAGIC SQUARES
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

bool is_magic(vector<int>& v)
{
	if(v[0] + v[1] + v[2] == 15)
	{
		if(v[3] + v[4] + v[5] == 15)
		{
			return
			   v[0] + v[3] + v[6] == 15 &&
			   v[1] + v[4] + v[7] == 15 &&
			   v[0] + v[4] + v[8] == 15 &&
			   v[2] + v[4] + v[6] == 15;
		}
		else
		{
			reverse( v.begin() + 6, v.end() );
			return false;
		}
	}
	else
	{
		reverse(v.begin() + 3, v.end());
		return false;
	}
}

int main()
{
	int begin, end;
	vector<int> v(9);
	for(int i = 0; i < 9; i++)
		v[i] = i+1;

	int count = 0;
	begin = clock();
	do
	{
		if(is_magic(v))
			count++;

	}while( next_permutation(v.begin(), v.end()) );
	end = clock();

	cout << "Count: " << count << endl;
	cout << "Time : " << end - begin << endl;

	system("pause");
	return 0;
}

