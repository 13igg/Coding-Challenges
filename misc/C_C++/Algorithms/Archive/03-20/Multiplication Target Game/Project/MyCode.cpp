//Multiplication Target Game
#include <iostream>
#include <ctime>
using namespace std;

//Suppose a player is faced with a target of n and a current product of p.
bool can_this_player_win(int n, int p)
{
	//If 9 * p > n, he can exceed the target on this turn and so can win

	//if(p > n / 9)		//This version runs slower, but won't overflow
	if(9 * p > n)		
		return true;

	//Consider all possible values this player can choose to multiply by.

	//for(int value = 2; value <= 9; value++)	//This version works slower
	for(int value = 9; value >= 2; value--)
	{
		//If choosing a certain value means that his opponent can't force a win,
		//then that value allows the original player to force a win.
		if(! can_this_player_win(n, value * p))
			return true;
	}
	return false;	//His opponent can force a win no matter what value was picked.

}
//This is a wrapper around the recursion.
bool can_player_one_win(int n)
{
	//Player 1 begins with a product of p = 1.
	return can_this_player_win(n,1);	
}

int main()
{
	int begin = clock(), end;
	int N = 72000;		//Search up to this value

	int count = 0;		//Count player 1 wins

	for(int target = 1; target <= N; target++)
		if(can_player_one_win(target))
			count++;

	end = clock();
	cout << "Targets through: " << N << endl;
	cout << "Wins for #1: " << count << endl;
	cout << "Percentage: " << 100. * count / N << endl;
	cout << "Time: " << end - begin << endl;

	system("pause");

	return 0;
}

