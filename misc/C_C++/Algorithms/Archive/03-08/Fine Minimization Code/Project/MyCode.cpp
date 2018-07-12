//The Fine Minimization Problem
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
public:
	int job_number;
	int time;
	int penalty;
};
bool operator<(const Job& lhs, const Job& rhs)
{
	return lhs.time * rhs.penalty < rhs.time * lhs.penalty;
}
int compute_fine(vector<Job> job_vector)
{
	int total_penalty = 0;
	int total_time = job_vector[0].time;
	for(size_t i = 1; i < job_vector.size(); i++)
	{
		total_penalty += job_vector[i].penalty * total_time;
		total_time += job_vector[i].time;
	}
	return total_penalty;
}
int main()
{
	ifstream fin("data.txt");
	if(fin.fail())
	{
		cout << "Problems opening file\n";
		exit(0);
	}

	vector<Job> AllJobs;

	int time, penalty, num = 1;
	while(fin >> time >> penalty)
	{
		Job job = {num++, time, penalty};
		AllJobs.push_back(job);
	}

	stable_sort(AllJobs.begin(), AllJobs.end());

	for(size_t i = 0; i < AllJobs.size(); i++)
		cout << AllJobs[i].job_number << ' ';
	cout << endl;
	cout << "Fine: $" << compute_fine(AllJobs) << endl;

	system("pause");
	return 0;
}