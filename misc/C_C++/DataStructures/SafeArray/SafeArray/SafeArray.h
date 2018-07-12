#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "SafeArrayOutOfBoundsException.h"
using namespace std;

template <class T>
class SafeArray
{
	public:
	~SafeArray();
		SafeArray(int initSize);
		SafeArray(SafeArray<T> &x);
		SafeArray();
		int size();
		T& at(int pos);
		void resize(int newSize);
		void push_back(const T& item);
		void push_back(SafeArray < T >& x);
		void pop_back(); //remove 1 item, cuz size in half if it is smaller.
		T& operator[](int pos);
	private:
		T* p_array;
		int numElements;
		int Compacity;
};

template <class T>
SafeArray<T>::SafeArray(int initSize)
{
	if(initSize>=0)
	{
		Compacity = initSize;
		numElements = initSize;
		p_array = new T[numElements];
	}
	else
		throw SafeArrayOutOfBoundsException();
	//throw exception
	
};
template <class T>
SafeArray<T>::SafeArray()
{
	p_array = new T[0];
	numElements = 0;
	Compacity = 0;
};

template <class T>
SafeArray<T>::SafeArray(SafeArray<T> &x)
{
	numElements = x.numElements;
	Compacity = x.Compacity;
	p_array = new T[Compacity];
	for(int i = 0; i < x.numElements; i ++)
		p_array[i] = x[i];

}

template <class T>
SafeArray<T>::~SafeArray()
{
	//cout<<endl<<endl<<"DESTRUCTORRRRR";
	delete [] p_array;
};

template <class T>
int SafeArray<T>::size()
{
	return numElements;
};

template <class T>
T& SafeArray<T>::operator[](int pos)
{
	if(pos >= 0 && pos <= size()-1)
		return p_array[pos];
	//throw exception
	else
		throw SafeArrayOutOfBoundsException();
}
template <class T>
T& SafeArray<T>::at(int pos)
{
	if(pos >= 0 && pos <= size()-1)
		return p_array[pos];
	//throw exception;
	else
		throw SafeArrayOutOfBoundsException();
}

template <class T>
void SafeArray<T>::resize(int newSize)
{
	T *newArray = new T[newSize];
	if(newSize >= Compacity)
	{
		cout<<"resize from: "<<Compacity<<" to: " <<newSize<<endl;
		
		for(int i = 0; i < newSize; i ++)
				newArray[i] = p_array[i];
		delete [] p_array;
		p_array = newArray;
	}
	else if(newSize < numElements)
	{
		cout<<"resize from: "<<Compacity<<" to: " <<newSize<<endl;
		for(int i = 0; i < newSize; i ++)
				newArray[i] = p_array[i];
		delete [] p_array;
		p_array = newArray;
	}
	else
		cout<<"resize from : "<<Compacity<<" to: " <<newSize<<endl;
		
		Compacity = newSize;
		
};

template <class T>
void SafeArray<T>::push_back(const T& item)
{
	if(numElements == 0)	
		resize(1);
	else if(numElements+1 >= Compacity)
		resize(Compacity*2);
	
	p_array[numElements] = item;
	numElements+=1;

}
template<class T>
void SafeArray<T>::push_back(SafeArray < T >& x)
{
	for(int i=0; i < x.numElements; i ++)
		push_back(x[i]);
}


template <class T>
void SafeArray<T>::pop_back()
{
	numElements-=1;
	if(numElements <= Compacity/2)
		resize(Compacity/2);
	
	T *newArray = new T[numElements];
	for(int i = 0; i < numElements; i ++)
		newArray[i] = p_array[i];	
	
	delete [] p_array;
	p_array = newArray;
}
