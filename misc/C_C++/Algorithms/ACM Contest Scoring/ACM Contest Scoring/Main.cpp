#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Team
{
	int team_number;
	int num_solved;
	int penalty_time;
	int times_missed[10];
};
struct Inputs
{
	int team_number;
	int prob;
	char code;
	int time;
	int num_solved;
	int penalty_time;
	int times_missed[10];
};

bool operator<(Team& t1, Team& t2)
{
	if(t1.num_solved > t2.num_solved)
		return true;
	else if(t1.num_solved < t2.num_solved)
		return false;

	if(t1.penalty_time < t2.penalty_time)
		return true;
	else if(t1.penalty_time>t2.penalty_time)
		return false;

	return t1.team_number < t2.team_number;
}

void sort_inputs(vector <Inputs>& inputs, vector <Team>& teams)
{
	ifstream fin("data.txt");
	int team_num;
	int prob;
	int time;
	char code;

	while(fin>>team_num>>prob>>time>>code)
	{
		Inputs i;
		i.team_number = team_num;
		i.prob = prob;
		i.code = code;
		i.time = time;
		if(inputs.size()-1 == 1)
			if(time > inputs.at(0).time)
				inputs.push_back(i);
			else
				inputs.insert(inputs.begin(),i);
		for(int j = 0; j < inputs.size()-1; j ++)
			if(inputs[j].time >= time)
				inputs.insert(inputs.begin()+j+1,i);
	}	
	for(int i = 0; i < inputs.size(); i ++)
		while(fin>>team_num>>prob>>time>>code)
		{
			if(teams[inputs[i].team_number].times_missed[prob] == -1)
				continue;
			if(code == 'I')
				teams[inputs[i].team_number].times_missed[prob] ++;
			else if(code == 'C')
			{
				teams[inputs[i].team_number].num_solved++;
				teams[inputs[i].team_number].penalty_time += time + 20 * teams[inputs[i].team_number].times_missed[prob];
				teams[inputs[i].team_number].times_missed[prob] = -1;
			}
		}
	fin.close();

	/*
	ifstream fin("data.txt");
	int team_num;
	int prob;
	int time;
	char code;

	while(fin>>team_num>>prob>>time>>code)
	{
		if(teams[team_num].times_missed[prob] == -1)
			continue;
		if(code == 'I')
			teams[team_num].times_missed[prob] ++;
		else if(code == 'C')
		{
			teams[team_num].num_solved++;
			teams[team_num].penalty_time += time + 20 * teams[team_num].times_missed[prob];
			teams[team_num].times_missed[prob] = -1;
		}
	}
	fin.close();
	*/
}

int main()
{
	vector<Team> teams(101);
	vector<Inputs> inputs(101);
	inputs[0].code = 0;
	inputs[0].prob = 0;
	inputs[0].time = 0;
	inputs[0].team_number = 0;

	for( int i = 0; i <= 100; i ++)
	{
		teams[i].team_number = i;
		teams[i].num_solved = 0;
		teams[i].penalty_time = 0;
			for(int j = 1; j <=10; j++)
				teams[i].times_missed[j] = 0;
	}
	sort_inputs(inputs,teams);
	for( int i = 0; i <= 100; i ++)
	{
		if(teams[i].num_solved > 0)
		{
			cout<<teams[i].team_number<< ' '
				<<teams[i].num_solved << ' '
				<<teams[i].penalty_time<<endl;
		}
	}
}