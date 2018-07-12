#include<iostream>
#include "OrdLinkedList.h"
using namespace std;

int main()
{
   OrdLinkedList<int> a;
  // cout<<a.isEmpty();
   //cout<<endl;

   cout<<"Hello, Fair warning, Insert works as it should, keeping it in order\nRemove and find work as they should\n p_current is touchy, doesnt keep track of it's position\n\n";
 cout<<"insert 8 digits: \n";
  a.insert(533);cout<<"533\n";
  a.insert(5);cout<<"5\n";
  a.insert(10);cout<<"10\n";
  a.insert(14);cout<<"14\n";
  a.insert(8);cout<<"8\n";
  a.insert(9);cout<<"9\n";
  a.insert(5);cout<<"5\n";
  a.insert(1);cout<<"1\n";

  cout<<"search for 533: ";
  a.find(533);
  cout<<"\nremove all 5s:";
  a.remove(5);
  cout<<"remove all 9s:\n";
  a.remove(9);
		cout<<"a.at(1): "<<a.at(1)<<endl;
		cout<<"a.at(2): "<<a.at(3)<<endl;
		cout<<"a.at(3): "<<a.at(2)<<endl;
		cout<<"a.at(4): "<<a.at(0)<<endl;
		cout<<"a[0]: "<<a[0]<<endl;
	//cout<<a[1];
	
	system("pause");
} 