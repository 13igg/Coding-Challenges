//Euler 336
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

const int N = 11;			//Number of carriages
int STOP_AT = 2011;			//Which maximix to select

bool is_maximix(int a[])
{
	int v[N];
	for(int i = 0; i < N; i++)
		v[i] = a[i];
	for(int pos = 0; pos <= N - 3; pos++)
	{
		if(v[pos] == pos || v[N-1] == pos)
			return false;
		int* it = find(v + pos, v + N, pos);
		reverse(it, v + N);
		reverse(v + pos, v + N);
	}
	return v[N-1] != N - 1;
}
int main()
{
	int begin = clock(), end;

	int v[N];
	for(int i = 0; i < N; i++)
		v[i] = i;
	swap(v[0],v[1]);		//Skip these non-maximixes

	int count = 0;
	do
	{
		if(is_maximix(v))
		{
			count++;
			if(count == STOP_AT)
			{
				for(int i = 0; i < N; i++)
					cout << char( 65 + v[i] ) << ' ';
				end = clock();
				cout << endl << "Time: " << end - begin << endl;
				break;
			}

		}
	}while(next_permutation(v,v + N));

	system("pause");
	return 0;
}


