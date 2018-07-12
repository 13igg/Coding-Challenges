//FILE: arrangement.cpp

#include "arrangement.h"
#include <algorithm>
#include <iostream>
using namespace std;

namespace arr
{
	void demo()
	{
		//using namespace arr;		//Required for client programs

		cout << "Words formed from \"dog\"\n";
			Permutation_string dog_words("dog");
			demo_output_all(dog_words);

			cout << "Ordered pairs of symbols # and %\n";
			vector<char> v;
			v.push_back('#');	v.push_back('%');
			Tuple_vector<char> pairs(v, 2);
			demo_output_all(pairs);

		cout << "Power set of {1,2}: ";
			Combination comb(2, 0, 3);
			demo_output_all(comb);
			
		cout << "Power set of {6,7}: ";
			comb.set_first(6);
			demo_output_all(comb);

	}
	void demo_output_all(arrangement& comb)
	{
		int count = 0;
		do
		{
			if(count > 0)
				cout << " / ";
           	cout << comb;
			count++;

		}while(comb.next());

		cout << "\nCount: " << count << endl << endl;
	}
}

namespace arr_backend
{
	arrangement::arrangement(int N, int MIN_SIZE, int MAX_SIZE, bool ALLOWREPEATS)
	{
		//Sanity checking of the parameters
		n = (N < 0 ? 0 : N);
		min_size = (MIN_SIZE < 0 ? 0 : MIN_SIZE);
		max_size = (MAX_SIZE < 0 ? 0 : MAX_SIZE);
		if(!ALLOWREPEATS)
		{
			if(min_size > n) min_size = n;
			if(max_size > n) max_size = n;
		}
		if(min_size > max_size)
			swap(min_size, max_size);
		k = min_size;
	}

	int arrangement::get_universal_size()
	{
		return n;
	}

	int arrangement::get_max_size()
	{
		return max_size;
	}

	int arrangement::get_min_size()
	{
		return min_size;
	}

	int arrangement::get_size()
	{
		return k;
	}

	///////////////////////////////////////////////////////////////////////////////////
	
	arrangement_integer::arrangement_integer(int N, int MIN_SIZE, int MAX_SIZE, 
											 bool ALLOWREPEATS, int FIRST):
		arrangement(N, MIN_SIZE, MAX_SIZE, ALLOWREPEATS),
		AllowRepeats(ALLOWREPEATS),
		first(FIRST)
	{

	}
	void arrangement_integer::print(ostream& out)
	{
		arr::operator<<(out, (*this));
	}

	vector<int> arrangement_integer::get_universal()
	{
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			v[i] = (*this)[i];
		return v;
	}

	int arrangement_integer::get_first()
	{
		return first;
	}

	void arrangement_integer::set_first(int new_first)
	{
		int dif = new_first - first;
		for(int i = 0; i < k; i++)
			(*this)[i] += dif;
		first = new_first;
	}
	///////////////////////////////////////////////////////////////////////////////////

	combination::combination(int N, int MIN_SIZE, int MAX_SIZE, 
							 bool ALLOWREPEATS, int FIRST):
		arrangement_integer(N, MIN_SIZE, MAX_SIZE, ALLOWREPEATS, FIRST)
	{
		reset(k);
	}

	bool combination::next()
	{
		if(next_combination())
			return true;
		else
		{
			k < get_max_size() ? reset(k + 1) : reset(get_min_size());
			return k > get_min_size();
		}
	}

	void combination::reset(int new_k)
	{
		k = new_k;
		resize(k);
		for(int i = 0; i < k; i++)
			(*this)[i] = first + (AllowRepeats ? 0 : i);
	}
	bool combination::next_combination()
	{
		int i = k - 1;
		while(i >= 0 && (*this)[i] == first + n - (AllowRepeats ? 1 : (k - i)))
			i--;
		if(i >= 0)
		{
			(*this)[i]++;
			for(int j = i + 1; j < k; j++)
				(*this)[j] = (*this)[j - 1] + (AllowRepeats ? 0 : 1);
			return true;
		}
		else
		{
			reset(k);
			return false;
		}
	}

	permutation::permutation(int n, int MIN_SIZE, int MAX_SIZE, 
							 bool ALLOWREPEATS, int FIRST):
		arrangement_integer(n, MIN_SIZE, MAX_SIZE, ALLOWREPEATS, FIRST),
		comb(n, MIN_SIZE, MAX_SIZE, ALLOWREPEATS, 0)
	{
		update();
	}

	bool permutation::next()
	{
		if(std::next_permutation(begin(), end()))
			return true;
		else
		{
			bool b = comb.next();
			update();
			return b;
		}
	}

	void permutation::update()
	{
		k = int(comb.size());
		resize(k);
		for(int i = 0; i < k; i++)
			(*this)[i] = first + comb[i];
	}
	ostream& operator<<(ostream& out, arrangement& a)
	{
		a.print(out);
		return out;
	}

}//End of namespace arr_backend


namespace arr
{
	Combination::Combination():
		arr_backend::combination(0, 0, 0, false, 1)
	{

	}
	Combination::Combination(int n):
		arr_backend::combination(n, 1, n, false, 1)
	{

	}
	Combination::Combination(int n, int k):
		arr_backend::combination(n, k, k, false, 1)
	{

	}
	Combination::Combination(int n, int min_size, int max_size, int first):
		arr_backend::combination(n, min_size, max_size, false, first)
	{

	}
	Permutation::Permutation():
		arr_backend::permutation(0, 0, 0, false, 1)
	{

	}
	Permutation::Permutation(int n):
		arr_backend::permutation(n, 1, n, false, 1)
	{

	}
	Permutation::Permutation(int n, int k):
		arr_backend::permutation(n, k, k, false, 1)
	{

	}
	Permutation::Permutation(int n, int min_size, int max_size, int first):
		arr_backend::permutation(n, min_size, max_size, false, first)
	{

	}

	Multiset::Multiset():
		arr_backend::combination(0, 0, 0, true, 1)
	{

	}
	Multiset::Multiset(int n):
		arr_backend::combination(n, 1, n, true, 1)
	{

	}
	Multiset::Multiset(int n, int k):
		arr_backend::combination(n, k, k, true, 1)
	{

	}
	Multiset::Multiset(int n, int min_size, int max_size, int first):
		arr_backend::combination(n, min_size, max_size, true, first)
	{

	}
	Tuple::Tuple():
		arr_backend::permutation(0, 0, 0, true, 1)
	{

	}
	Tuple::Tuple(int n):
		arr_backend::permutation(n, 1, n, true, 1)
	{

	}
	Tuple::Tuple(int n, int k):
		arr_backend::permutation(n, k, k, true, 1)
	{

	}
	Tuple::Tuple(int n, int min_size, int max_size, int first):
		arr_backend::permutation(n, min_size, max_size, true, first)
	{

	}

	Combination_string::Combination_string():
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(string(), 0, 0, false)
	{

	}
	Combination_string::Combination_string(string s):
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(s, 1, int(s.size()), false)
	{

	}
	Combination_string::Combination_string(string s, int k):
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(s, k, k, false)
	{

	}
	Combination_string::Combination_string(string s, int min_size, int max_size):
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(s,min_size,max_size,false)
	{

	}
	Permutation_string::Permutation_string():
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(string(), 0, 0, false)
	{

	}
	Permutation_string::Permutation_string(string s):
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(s, 1, int(s.size()), false)
	{

	}
	Permutation_string::Permutation_string(string s, int k):
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(s, k, k, false)
	{

	}
	Permutation_string::Permutation_string(string s, int min_size, int max_size):
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(s, min_size, max_size, false)
	{

	}

	Multiset_string::Multiset_string():
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(string(), 0, 0, true)
	{

	}
	Multiset_string::Multiset_string(string s):
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(s, 1, int(s.size()), true)
	{

	}
	Multiset_string::Multiset_string(string s, int k):
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(s, k, k, true)
	{

	}
	Multiset_string::Multiset_string(string s, int min_size, int max_size):
		arr_backend::
		arrangement_vector<string, arr_backend::combination>(s, min_size, max_size, true)
	{

	}
	Tuple_string::Tuple_string():
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(string(), 0, 0, true)
	{

	}
	Tuple_string::Tuple_string(string s):
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(s, 1, int(s.size()), true)
	{

	}
	Tuple_string::Tuple_string(string s, int k):
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(s, k, k, true)
	{

	}
	Tuple_string::Tuple_string(string s, int min_size, int max_size):
		arr_backend::
		arrangement_vector<string, arr_backend::permutation>(s, min_size, max_size, true)
	{

	}
	ostream& operator<<(ostream& out, string s)
	{
		::operator<<(out, s);
		return out;
	}

}//End of namespace arr

