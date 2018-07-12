//Contest Scoring
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team
{
	int team_number;
	int number_solved;
	int penalty_time;
	int num_times_wrong[11];	//set to -1 once correct
};
bool operator<(Team& t1, Team& t2)
{
	if(t1.number_solved > t2.number_solved) 
		return true;
	else if(t1.number_solved < t2.number_solved) 
		return false;

	if(t1.penalty_time < t2.penalty_time) 
		return true;
	else if(t1.penalty_time > t2.penalty_time) 
		return false;
    
	return t1.team_number < t2.team_number;
}
void read_file(vector<Team>& team)
{
	ifstream fin("data4.txt");
	int num;		//team number
	int prob;		//problem number
	int time;		//elapsed time
	char code;		//result code
	while(fin >> num >> prob >> time >> code)
	{
		if(team[num].num_times_wrong[prob] == -1)
			continue;

		if(code == 'C')
		{
			team[num].number_solved++;
			team[num].penalty_time += time + 20*team[num].num_times_wrong[prob];
			team[num].num_times_wrong[prob] = -1;
		}
		else if(code == 'I')
			team[num].num_times_wrong[prob]++;
	}
	fin.close();
}
int main()
{
	vector<Team> team(101);

	//Initialize teams
	for(int i = 1; i <= 100; i++)
	{
		team[i].team_number = i;
		team[i].number_solved = team[i].penalty_time = 0;
		for(int p = 1; p <= 10; p++)
		{
			team[i].num_times_wrong[p] = 0;
		}
	}

	read_file(team);

	sort(team.begin() + 1, team.end());

	//Generate output
	for(int i = 1; i <= 100; i++)
	{
		if(team[i].number_solved > 0)
		{
			cout << team[i].team_number << ' '
				 << team[i].number_solved << ' '
				 << team[i].penalty_time << endl;
		}
	}

	system("pause");
	return 0;
}
