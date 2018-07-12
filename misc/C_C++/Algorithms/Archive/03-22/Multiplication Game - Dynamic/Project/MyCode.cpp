//Multiplication Target Game
//Using Dynamic Programming
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//We are going to store results up to p = 5000 in the array this_player_wins
const int STORE_MAX = 5001;

//Suppose a player is faced with a target of n and a current product of p.
bool can_this_player_win(int n, int p, int this_player_wins[])
{
	if(9 * p > n)		//If 9 * p > n, he can exceed the target on his turn.
		return true;
	if(p < STORE_MAX && this_player_wins[p] > 0)
		return this_player_wins[p] == 1;

	//Consider all possible values this player can choose to multiply by.
	for(int value = 2; value <= 9; value++)
	{
		//If choosing a certain value means that his opponent can't force a win,
		//then that value allows the original player to force a win.
		if(! can_this_player_win(n, value * p, this_player_wins))
		{
			if(p < STORE_MAX)
				this_player_wins[p] = 1;
			return true;
		}
	}
	if(p < STORE_MAX)
		this_player_wins[p] = 2;
	return false;	//His opponent can force a win no matter what value was picked.

}
//This is a wrapper around the recursion.

bool can_player_one_win(int n)
{
	//this_player_wins[p] == 1 if the current player wins, 
	//this_player_wins[p] == 2 if he loses,
	//this_player_wins[p] == 0 if it hasn't been determined yet.

	int this_player_wins[STORE_MAX] = {0};

	//Player 1 begins with a current product of p = 1.
	return can_this_player_win(n, 1, this_player_wins);
}
int main()
{

	int begin = clock(), end;
	int N = 400000;		//Search up to this value

	int count = 0;		//Count player 1 wins

	for(int target = 1; target <= N; target++)
		if(can_player_one_win(target))
			count++;

	end = clock();
	cout << "Wins: " << count << ' '
		 << "Time: " << end - begin << endl;

	system("pause");

	return 0;
}
