//Binomial Coefficients
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef unsigned long long BIG_INT;

//An iterative factorial function
BIG_INT factorial(int n)
{
	if(n < 0) return 0;		//Negative factorials?
	if(n == 0) return 1;	//0! = 1

	BIG_INT product = 1;
	for(int i = 2; i <= n; i++)
	{
		if(product > _UI64_MAX / i)	//Checking for overflow
			return 0;
		product = i * product;
	}
	return product;
}
//A recursive factorial function
BIG_INT recursive_factorial(int n)
{
	if(n < 0) return 0;		//Negative factorials?
	if(n == 0) return 1;	//0! = 1

	BIG_INT result = recursive_factorial(n - 1);
	if( result > _UI64_MAX / n )	//Checking for overflow
		return 0;
	return n * result;
}
//An iterative binomial coefficient function.
//Note we are limited by overflowing factorials.
int binomial1(int n, int k)
{
	if(n < k)			//There aren't enough n to choose from...
		return 0;
	BIG_INT f = factorial(n);
	if(f == 0)		//If factorials overflowed...
	{
		cout << "\nOverflow at " << n << ' ' << k << endl;
		system("pause");
		exit(0);
	}
	return f / factorial(k) / factorial(n-k);
}
//A recursive binomial coefficient function.
BIG_INT binomial2(int n, int k)
{
	if(n < k)
		return 0;
	if(k == 0 || n == k)		//Base cases -- the 1's of Pascal's Triangle
		return 1;
	BIG_INT a = binomial2(n-1,k-1);
	BIG_INT b = binomial2(n-1,k);
	if(a > _UI64_MAX - b)		//Checking for overflow
	{
		cout << "\nOverflow at " << n << ' ' << k << endl;
		system("pause");
		exit(0);
	}
	return a + b;
}
//A bottom up binomial coefficient function
BIG_INT binomial3(int n, int k)
{
	if(n < k)
		return 0;

	//Create a vector to store the table of binomial coefficients, initially:
	vector< vector<BIG_INT> > b(n+1);		//1000..0
	for(int i = 0; i <= n; i++)				//0000..0
		b[i] = vector<BIG_INT>(k+1);			//0000..0
	b[0][0] = 1;

	//Now fill in the table starting from its first rows down
	for(int row = 1; row <= n; row++)
	{
		b[row][0] = 1;
		for(int col = 1; col <= k; col++)
		{
			BIG_INT x = b[row-1][col];
			BIG_INT y = b[row-1][col-1];
			if(x > _UI64_MAX - y)
			{
				cout << "\nOverflow at " << n << ' ' << k << endl;
				system("pause");
				exit(0);
			}
			b[row][col] = b[row-1][col] + b[row-1][col-1];
		}
	}
	return b[n][k];
}
BIG_INT fibonacci1(int n)
{
	if(n <= 0) return 0;
	if(n <= 2) return 1;
	return fibonacci1(n-1) + fibonacci1(n-2);
}
//Fibonacci with dynamic programming
BIG_INT fibonacci_helper(int n, vector<BIG_INT>& v)
{
	if(v[n] > 0)			//This would mean that we've already calculated it
		return v[n];
	//Otherwise, calculate and store
	 v[n] = fibonacci_helper(n-1, v) + fibonacci_helper(n-2, v);
	 return v[n];
}
//The wrapper function to create the storage space:
BIG_INT fibonacci(int n)
{
	if(n <= 0) return 0;
	if(n <= 2) return 1;

	//Storage space
	vector<BIG_INT> v(n+1);		//All zeros initially
	v[1] = v[2] = 1;
	return fibonacci_helper(n, v);
}

//Bottom-up Fibonacci
BIG_INT fibonacci2(int n)
{
	vector<BIG_INT> result = vector<BIG_INT>();
	result.push_back(0);
	result.push_back(1);
	result.push_back(2);//sets the first 2 and a empty one to start
    
	for (int j=3; j<=n; ++j)
	{
		result.push_back( result[j-1] + result[j-2] );
		if(result[result.size] > _UI64_MAX)		//Checking for overflow
		{
			cout << "\nOverflow at "<< endl;
			system("pause");
			exit(0);
		}

	}

    return result[n-1];

	return 0;
}


BIG_INT binomial4_helper(int n, int k, vector< vector<BIG_INT> > b)
{
	return 0;
}
BIG_INT binomial4(int n, int k)
{
	return 0;
}


//Passing a function as a parameter to test the binomial functions.
template <typename T>
void print(T f)
{
	const int N = 10;
	for(int n = 0; n <= N; n++)
	{
		for(int k = 0; k <= N; k++)
			cout << setw(4) << f(n,k);
		cout << endl;
	}
}

int main()
{
	//print(binomial4);	//This will test the function by printing a table.
	cout<<fibonacci2(10)<<endl;
	system("pause");
	return 0;
}


