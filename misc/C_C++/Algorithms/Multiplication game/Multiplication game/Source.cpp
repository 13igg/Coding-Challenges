//Euler 336
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

bool can_next_player_win(int n, int p)
{
	if(p*9 > n)
		return true;

	for(int value = 9; value >=2; value --)
		if(!can_next_player_win(n,value*p))
			return true;
	return false;
}

bool can_first_player_win(int n)
{
	return(can_next_player_win(n,1));
}
int main()
{
	int N = 72000;
	int count = 0;
	int begin = clock(), end;
	for(int i = 1; i <=N; i ++)
	{
		if(can_first_player_win(i))
			count++;
		//cout<<i<< " ";
		//cout<<can_first_player_win(i) ? true : false;
		//cout<<endl;
	}
	end = clock();
	cout<<"count: " << count<< endl;
	cout<<"Time: " << end - begin<< endl;

	system("pause");
}