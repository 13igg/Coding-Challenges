#include <iostream>
using namespace std;

//This function counts the number of ways to sum to n in k increasing
//parts using the numbers s through m.
int f(int n, int k, int s, int m)
{
	if(k == 1)
	{
		if(n >= s && n <= m)
			return 1;
		else
			return 0;
	}

	int count = 0;
	for(int i = s; k * (2*i + k - 1) / 2 <= n; i++)
		count += f(n-i, k-1, i+1, m);

	return count;
}

int main()
{

	cout << "3 increasing parts using 1-10 to sum to 10: " << f(10,3,1,10) << endl << endl;
	cout << "f(34,4,1,16) = " << f(34,4,1,16) << endl;
	cout << "f(65,5,1,25) = " << f(65,5,1,25) << endl;

	//For comparison, here is another way of generating these numbers.
	int count = 0;
	for(int a = 1; a <= 16;  a++)
		for(int b = a+1; b <= 16; b++)
			for(int c = b+1; c <= 16; c++)
				for(int d = c+1; d <= 16; d++)
					if(a+b+c+d == 34)
						count++;
	cout << "f(34,4,1,16) = " << count << endl;

	count = 0;
	for(int a = 1; a <= 25;  a++)
		for(int b = a+1; b <= 25; b++)
			for(int c = b+1; c <= 25; c++)
				for(int d = c+1; d <= 25; d++)
					for(int e = d+1; e <= 25; e++)
					if(a+b+c+d+e == 65)
						count++;
	cout << "f(65,5,1,25) = " << count << endl << endl;
	
	system("pause");
	return 0;
}


