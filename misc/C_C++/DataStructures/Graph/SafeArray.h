#include <iostream>
#include "SafeArrayOutOfBoundsException.h"
using namespace std;

template <class T>
class SafeArray 
{
		public:
				  SafeArray();
				  SafeArray(const int &size);
				  SafeArray(SafeArray <T> &elem);
				  ~SafeArray();
				  int size();
				  void push_back(const T &elem);
				  void pop_back();				  
				  void resize(int size);
				  T& at(int a);
				  T& operator[](int a);
		private:
				  T* myarray;
				  int capacity;
				  int numElements;
};

template <class T>
SafeArray<T>::SafeArray()
{
	myarray = new T[0];
	numElements = 0;	
	capacity = 0;
}

template <class T>
SafeArray<T>::SafeArray(const int &size)
{
	myarray = new T[size];
	numElements = 0;
	capacity = size;
}

template <class T>
SafeArray<T>::SafeArray(SafeArray <T> &elem)
{	
	myarray = new T[0];
	capacity = 0;
	numElements = 0;

	for(int i = 0; i < elem.size(); i ++)
		push_back(elem[i]);
}
template <class T>
void SafeArray<T>::push_back(const T &elem)
{
	if(numElements == capacity)
		resize(numElements == 0 ? 1 : numElements*2);//true return 1 else return size *2
	myarray[numElements] = elem;
	numElements++;
}

template <class T>
void SafeArray<T>::pop_back()
{
	if(numElements > 0)
	{
		myarray[numElements-1] = NULL;
		numElements--;
	}
	else
		throw SafeArrayOutOfBoundsException();
	if((capacity/numElements) >= 2)
		resize(capacity/2);//resizes if it can be divided by 2 cleanly
}

template <class T>
void SafeArray<T>::resize(int size)
{
	T* arr2 = new T[size];
	for(int i = 0; i < (numElements < size ? numElements : size); i++) //Storm helped me here and he got help from Don
		arr2[i] = myarray[i];
	delete [] myarray;//delete my array
	myarray = arr2;	//set empty array = to temp array 2
	capacity = size; //reset capacity to size
	numElements = (numElements < size ? numElements : size); //if numElements > size set it to size
}

template <class T>
T& SafeArray<T>::at(int a)
{	
	if(a >= 0 || a <= numElements)
		return myarray[a];
	else
		throw SafeArrayOutOfBoundsException();
}

template <class T>
T& SafeArray<T>::operator[](int a)
{
	if(a >= 0 && a <= numElements)
		return myarray[a];
	else
		throw SafeArrayOutOfBoundsException();
}

template <class T>
int SafeArray<T>::size()
{
	return numElements;
}

template <class T>
SafeArray<T>::~SafeArray()
{
   if (numElements > 0)
      delete [] myarray;
}
	