//Stern-Brocot Number System
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getLR(int num, int denom)
{
	string LR;
	int left_num = 0, left_denom = 1, right_num = 1, right_denom = 0;
	while(true)
	{
		int mid_num = left_num + right_num;
		int mid_denom = left_denom + right_denom;
		if(mid_num * denom < mid_denom * num)
		{
			left_num = mid_num;
			left_denom = mid_denom;
			LR += 'R';
		}
		else if(mid_num * denom > mid_denom * num)
		{
			right_num = mid_num;
			right_denom = mid_denom;
			LR += 'L';
		}
		else break;
	}
	return LR;
}
	
void print_fraction(string LR)
{
	int left_num = 0, left_denom = 1, right_num = 1, right_denom = 0;
	int mid_num = 1, mid_denom = 1;
	for(int i = 0; i < int(LR.size()); i++)
	{
		if(LR[i] == 'L')
		{
			right_num = mid_num;
			right_denom = mid_denom;
		}
		else
		{
			left_num = mid_num;
			left_denom = mid_denom;
		}
		mid_num = left_num + right_num;
		mid_denom = left_denom + right_denom;
	}
	cout << mid_num << '/' << mid_denom << endl;
}

int main()
{

	cout << getLR(3,4) << ' ' << getLR(2,5) << endl;
	print_fraction("LRR");
	print_fraction("LRRLR");

	system("pause");
	return 0;
}
