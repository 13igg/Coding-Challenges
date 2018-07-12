#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "phrase.h"
using namespace std;
//findign orime oinlyu go to the square root
int main()
{
	int size = 0;
	string file =  "C:\\Users\\educ\\Desktop\\translate.txt";
	ifstream MyReadFile;
	vector<string> inputs;
		string input;
		string english;
		string translate;
		string garbage;

		//finding size
	MyReadFile.open(file);
	while(MyReadFile.is_open() && !MyReadFile.eof())
	{
		MyReadFile >> garbage;//reads through file once to find the size of it
			if(garbage != ":::")
				size ++; //size is english + translation
	}
	MyReadFile.close();

	HashTable < phrase* > t1(size/2); //size is english+translation/2

	//filling the hash table
	
	MyReadFile.open(file);
	while(MyReadFile.is_open() && !MyReadFile.eof())
	{
		phrase *p = new phrase;
		MyReadFile >> p->english;//reavind a value into previous
		MyReadFile >> garbage;//reading garbage into current
		MyReadFile >> p->translate;//reading a real value into current
			if(p->english != ":::")
				t1.insert(p->english,p);
	}
		MyReadFile.close();
		MyReadFile.open(file);

	t1.printCollisionInfo();
	//reading users inputs	
		cout<<"HashTable Program\n";
		cout<<"Enter words or phrases and press enter - type x to begin:\n";
		while(input != "x")
		{
			cin>>input;
			inputs.push_back(input);
		}
		for(int i = 0; i <inputs.size(); i ++)
		{
			cout<<inputs[i]<<" translated is: ";
				
		}
		system("pause");

}
