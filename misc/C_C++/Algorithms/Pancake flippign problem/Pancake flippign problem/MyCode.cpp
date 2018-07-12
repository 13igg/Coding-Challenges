//Pancake Flipping Problem
//Given a vector of relative pancake sizes stored in v[1]..v[n],
//obtain a flip-vector of spatula positions from which to flip.
/*For example, given pancakes of sizes 5,2,4,3,1,6 stored in 
a vector starting at index 1, the flip-vector 1,2,4,3,5
would transform the original vector to 6,5,4,3,2,1.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Returns the flip-vector -- see comment above.
vector<int> get_flips(vector<int> stack)
{
	int n = stack.size() - 1;		//Number of pancakes.  Ignore stack[0]
	vector<int> flips;				//The flip-vector

	//Starting from the bottom of the stack, position each pancake.
	for(int pos = 1; pos <= n; pos++)
	{
		//The size of the next biggest pancake, which must go into index pos
		int big_size = n + 1 - pos;

		if(stack[pos] == big_size)	//The next biggest pancake is correctly positioned
			continue;

		//Find the position of the next biggest pancake
		int big_pos;
		if(stack[n] == big_size)	//If it is already at the top..
			big_pos = n;
		else						//If it is not at the top..
		{
			//..find it...
			big_pos = pos;
			while( stack[++big_pos] != big_size  );

			//..and then flip it to the top and record the flip
			reverse( stack.begin() + big_pos, stack.end());
			flips.push_back(big_pos);
		}

		//Now flip the next biggest pancake to the correct index pos..
		reverse( stack.begin() + pos, stack.end());
		flips.push_back(pos);	//..and record the flip
	}

	return flips;		//Return the flip-vector
}

//Overload operator << for outputting vectors
ostream& operator<<(ostream& out, vector<int> v)
{
	for(int i = 0; i < v.size(); i++)
		out << v[i] << ' ';
	return out;
}

int main()
{
	for(int n = 3; n <=10; n ++)
	{				//Number of pancakes
		vector<int> pancakes(n+1);	//We ignore the first position
		for(int i = 1; i <= n; i++)
			pancakes[i] = i;
		int worstCase = 0;
		do
		{
			if(get_flips(pancakes).size() > worstCase)
				worstCase = get_flips(pancakes).size();			
		}while( next_permutation(pancakes.begin() + 1, pancakes.end()));
		cout << "Pancakes: " << pancakes.size()-1 << "  ";
		cout<<worstCase<<endl;
	}
	system("pause");
	return 0;
}


