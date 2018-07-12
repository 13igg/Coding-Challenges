#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "OrdLinkedList.h"
#include "SafeArray.h"
using namespace std;

template <class T>
class HashTable
{
	public:
		HashTable();
		HashTable(const int initSize);
		~HashTable();
		void insert(const string& key, const T& value);
		bool remove(const string& key);
		bool retrieve(const string& key, T& elem);
		bool isEmpty();
		void printCollisionInfo();
	private:
		int hash(string hData); //hData is data to be hashed
		int tableSize; //use this in a prime number calculator
	    SafeArray< OrdLinkedList<T> > table; // replace this array with a safe array later
		
};

template <class T>
HashTable<T>::HashTable()
{
}
template <class T>
HashTable<T>::HashTable(const int initSize)
	:table(initSize)
{
	tableSize = initSize;
	//cout<<"HashTables size is: " <<initSize;
	//initialize the array from above here. the one taht needsto be replaced
			//table.resize(initSize+1);//adding 1 just as a way to make it prime for this example
	//fill the safe array with elements to the init size
//	table.numElements = initSize;
}
template <class T>
HashTable<T>::~HashTable()
{
}
template <class T>
int HashTable<T> :: hash(string hData)
{
	unsigned int result = 0;
	for(int i = 0; i < hData.length(); i++)
	{
		result = (result*33) + hData[i];
	}
	//return (int)(result%(tableSize - 3) ); //remove -2 when u get a prime number cacculator up n runnin;
	return (int)(result%(991));
}
//3990758
//	l108
//	a97
//	r115
//	g103
//	e101
//4134455
//	p112
//	a97
//	r114
//	t116
		
template <class T>
void HashTable<T>::insert(const string& key, const T& value)
{
	//when inserting, hash the value?
	
	//table[hash(key)]
	cout<<"Inserting data at hased value of: " << hash(key)<<endl;
	table[hash(key)].insert(value);
}
template <class T>
bool HashTable<T>::remove(const string& key)
{
}
template <class T>
bool HashTable<T>::retrieve(const string& key, T& elem)
{
}
template <class T>
bool HashTable<T>::isEmpty()
{
	if(table[0] == NULL)
		return false;
}
template <class T>
void HashTable<T>::printCollisionInfo()
{
	int emptyTables = 0;
	// Print the average length of each of the non-empty lists, the longest list, and the number of empty lists.
	for(int i = 0; i < table.size(); i ++)
		if(table[i].isEmpty())
			emptyTables++;
	cout<<emptyTables<<endl;


	//this is just a testing function to see exactly what words show up at which spot. 
	//It looks weird because of my next, previous, and first functions working the way 
	//they do in my ordlinkedlist 
	T x;
	int j = 0;
	cout<<"\n\n\n\n\n\n\n\n\n\nTESTING PRINTING INFORMATION";
	for(int i =0; i < table.size(); i ++)
		if(table[i].isEmpty())
			cout<<"table["<<i<<"] = null\n";
		else
			while(true)
			{
				if(table[i].first(x) != NULL)
				{	
					if(table[i].next(x) == NULL)
					{
						cout<<"table["<<i<<"] = "<<table[i].at(j)->english<<endl;
						table[i].previous(x);
						break;
					}
					else
					{
						table[i].previous(x);
						cout<<"table["<<i<<"] = "<<x->english<<endl;
						for(int j = 0; j < table[i].size()-1; j ++)
						{
							table[i].next(x);
							cout<<"table["<<i<<"] = "<<x->english<<endl;
						}
					}
				}			
			break;
			}

}