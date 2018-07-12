/*FILE: arrangement.h

This is the header file for the arrangement classes.
See and run arr::demo() for a demonstration.

The client arrangement classes are

	arr::Combination	arr::Combination_string		arr::Combination_vector<T>
	arr::Permutation	arr::Permutation_string		arr::Permutation_vector<T>
	arr::Multiset		arr::Multiset_string		arr::Multiset_vector<T>
	arr::Tuple			arr::Tuple_string			arr::Tuple_vector<T>

The namespace arr_backend contains the backend to make the classes in arr work.

An arrangement class represents a collection of a given type and size of arrangement.
For example, given the universal set {1,2,3,4} and the size 2,
the Combination arrangement class consists of the 6 vectors {1,2} through {3,4}.

When a Combination object is created, its value represents the first arrangement
in the class.  The .next() method advances the value through all arrangements, 
back to the beginning again when it returns false.

We deal with 4 types of arrangements

	Combinations - order doesn't matter and repeats are not allowed.
	Permutations - order does matter and repeats are not allowed.
	Multisets    - order doesn't matter and repeats are allowed.
	Tuples       - order matters and repeats are allowed.

For each type of arrangement, we have the option of specifying the universal set
as an integer n (giving {1..n} unless the default first = 1 is changed), as a 
string, or as a vector of any type.

The arrangement type and a universal set type determine one of the classes above.
Objects of these classes have inherited types vector<int>, string, or vector<T>

The class constructor allows us to set the universal set and the size or range of sizes.
Each class has 3 non-default forms of the constructor.  For example,

	Combination(n)		--	all size 1 through n combinations of {1..n}
	Combination(n,k)	--	combinations of size k
	Combination(n,a,b)	--  combinations of sizes a through b inclusive

A useful idiom is illustrated by the following example which generates all 
words that can be formed from the letters of "frog".

	Permutation_string frog_word("frog");
	do
	{
		cout << string(frog_word) << endl;
	}while(frog_word.next());

Notes:

1. Within namespace arr, operator << is overloaded to print vectors.
2. Duplications in the universal set or string are treated as distinct.
3. An optional parameter in the longest constructor of the classes representing
   arrangements of consecutive integers allows us to set the starting integer.
   Also use the set_first(new_first) and get_first() methods.

Variable conventions:

n - size of the universal set or string
k - current size of the value of an arrangement class object
min_size and max_size - range of arrangement sizes for class objects

*/

#pragma once
#include <vector>
#include <string>
using namespace std;

namespace arr_backend{ class arrangement;}	//Forward declaration
namespace arr
{
	typedef arr_backend::arrangement arrangement;//Don't put arrangement in arr!
	void demo();
	void demo_output_all(arrangement&);	//Helper function for demo.
}

namespace arr_backend
{
	//This is the abstract base class of all arrangements.
	//Note "typedef arr_backend::arrangement arr::arrangement" above.
	class arrangement
	{
		public:
			arrangement(int n, int min_size, int max_size, bool AllowRepeats);

			virtual bool next() = 0;
			virtual void print(ostream& out) = 0;

			int get_universal_size();
			int get_max_size();
			int get_min_size();
			int get_size();

		protected:
			int n, k, min_size, max_size;
	};

	//This is the base class when the universal set is a vector of consecutive integers.
	class arrangement_integer:public arrangement, public vector<int>
	{
		public:
			arrangement_integer(int n, int min_size, int max_size, bool AllowRepeats, int first);

			virtual bool next() = 0;
			virtual void print(ostream& out);

			vector<int> get_universal();

			int  get_first();
			void set_first(int new_first);

		protected:
			bool AllowRepeats;
			int first;
	};

	//This class can represent combinations and multisets.
	class combination: public arrangement_integer
	{
		public:
			combination(int n = 0, int min_size = 0, int max_size = 0,
						bool AllowRepeats = false, int first = 1);

			virtual bool next();
		
		protected:
			void reset(int k);
			bool next_combination();
	};

	//This class can represent permutations and tuples.
	//An embedded combination object steps through all combinations, 
	//and for each of its values we form all possible permutations.
	class permutation: public arrangement_integer
	{
		public:
			permutation(int n = 0, int min_size = 0, int max_size = 0, 
						bool AllowRepeats = false, int first = 1);

			virtual bool next();
		
		protected:
			combination comb;	//Embedded object.
			void update();
	};

	//This class can represent arrangements of universe type string or vector<T>.
	//The AType refers to one of the four types of arrangements.
	//An embedded arrangement_integer generates vectors of subscripts
	//from which we extract elements of the universal.
    template <typename UType, typename AType>
	class arrangement_vector: public arrangement, public UType
	{
		public:
			arrangement_vector(UType UNIVERSAL = UType(), 
							int	MIN_SIZE = 0, int MAX_SIZE = 0,
							bool ALLOWREPEATS = false):
				arrangement(int(UNIVERSAL.size()), MIN_SIZE, MAX_SIZE, ALLOWREPEATS),
				universal(UNIVERSAL),
				arr(int(UNIVERSAL.size()), MIN_SIZE, MAX_SIZE, ALLOWREPEATS, 0)
			{
				update();
			}

			virtual bool next()
			{
				bool b = arr.next();
				update();
				return b;
			}

			virtual void print(ostream& out)
			{
				arr::operator<<(out, (*this));
				//Calls arr::operator<<(out, vector<T>) or ::operator<<(out, string)
			}

			UType get_universal()
			{
				return universal;
			}

		protected:
			UType universal;	//universal set or string
			AType arr;			//embedded arrangement_integer object
			void update()
			{
				k = int(arr.size());
				resize(k);
				for(int i = 0; i < k; i++)
				(*this)[i] = universal[arr[i]];
			}
	};
	ostream& operator<<(ostream& out, arrangement& a);

}	//End of namespace arr_backend

//The namespace arr represents the client front-end of the arrangement library.
//These classes amount to convenience constructors for the arr_backend classes.
namespace arr
{
	class Combination: public arr_backend::combination
	{
		public:
			Combination();
			Combination(int n);
			Combination(int n, int k);
			Combination(int n, int min_size, int max_size, int first = 1);
	};

	class Permutation: public arr_backend::permutation
	{
		public:
			Permutation();
			Permutation(int n);
			Permutation(int n, int k);
			Permutation(int n, int min_size, int max_size, int first = 1);
	};

	class Multiset: public arr_backend::combination
	{
		public:
			Multiset();
			Multiset(int n);
			Multiset(int n, int k);
			Multiset(int n, int min_size, int max_size, int first = 1);
	};

	class Tuple: public arr_backend::permutation
	{
		public:
			Tuple();
			Tuple(int n);
			Tuple(int n, int k);
			Tuple(int n, int min_size, int max_size, int first = 1);
	};

	class Combination_string: public arr_backend::arrangement_vector<string, arr_backend::combination>
	{
		public:
			Combination_string();
			Combination_string(string s);
			Combination_string(string s, int k);
			Combination_string(string s, int min_size, int max_size);
	};

	class Permutation_string: public arr_backend::arrangement_vector<string, arr_backend::permutation>
	{
		public:
			Permutation_string();
			Permutation_string(string s);
			Permutation_string(string s, int k);
			Permutation_string(string s, int min_size, int max_size);
	};

	class Multiset_string: public arr_backend::arrangement_vector<string, arr_backend::combination>
	{
		public:
			Multiset_string();
			Multiset_string(string s);
			Multiset_string(string s, int k);
			Multiset_string(string s, int min_size, int max_size);
	};
	class Tuple_string: public arr_backend::arrangement_vector<string, arr_backend::permutation>
	{
		public:
			Tuple_string();
			Tuple_string(string s);
			Tuple_string(string s, int k);
			Tuple_string(string s, int min_size, int max_size);
	};

	template <typename T>
	class Combination_vector: public arr_backend::arrangement_vector<vector<T>, arr_backend::combination>
	{
		public:
			Combination_vector():
			arr_backend::arrangement_vector<string, arr_backend::combination>(vector<T>(), 0, 0, false){}
			Combination_vector(vector<T> v):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, 1, int(v.size()), false){}
			Combination_vector(vector<T> v, int k):
			arr_backend::arrangement_vector<vector<T>, arr_backend::combination>(v, k, k, false){}
			Combination_vector(vector<T> v, int min_size, int max_size):
			arr_backend::arrangement_vector<vector<T>, arr_backend::combination>(v, min_size, max_size, false){}
	};

	template <typename T>
	class Permutation_vector: public arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>
	{
		public:
			Permutation_vector():
			arr_backend::arrangement_vector<string, arr_backend::permutation>(vector<T>(), 0, 0, false){}
			Permutation_vector(vector<T> v):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, 1, int(v.size()), false){}
			Permutation_vector(vector<T> v, int k):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, k, k, false){}
			Permutation_vector(vector<T> v, int min_size, int max_size):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, min_size, max_size, false){}
	};

	template <typename T>
	class Multiset_vector: public arr_backend::arrangement_vector<vector<T>, arr_backend::combination>
	{
		public:
			Multiset_vector():
			arr_backend::arrangement_vector<string, arr_backend::combination>(vector<T>(), 0, 0, true){}
			Multiset_vector(vector<T> v):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, 1, int(v.size()), true){}
			Multiset_vector(vector<T> v, int k):
			arr_backend::arrangement_vector<vector<T>, arr_backend::combination>(v, k, k, true){}
			Multiset_vector(vector<T> v, int min_size, int max_size):
			arr_backend::arrangement_vector<vector<T>, arr_backend::combination>(v, min_size, max_size, true){}
	};

	template <typename T>
	class Tuple_vector: public arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>
	{
		public:
			Tuple_vector():
			arr_backend::arrangement_vector<string, arr_backend::permutation>(vector<T>(), 0, 0, true){}
			Tuple_vector(vector<T> v):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, 1, int(v.size()), true){}
			Tuple_vector(vector<T> v, int k):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, k, k, true){}
			Tuple_vector(vector<T> v, int min_size, int max_size):
			arr_backend::arrangement_vector<vector<T>, arr_backend::permutation>(v, min_size, max_size, true){}
	};

	ostream& operator<<(ostream& out, string s);

	template <typename T>
	ostream& operator<<(ostream& out, vector<T> v)
	{
		for(int i = 0; i + 1 < int(v.size()); i++)
			out << v[i] << ' ';
		if(v.size() == 0)
			out << "<empty>";
		else
			out << v.back();
		return out;
	}
}//End of namespace arr