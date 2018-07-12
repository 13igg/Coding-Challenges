#include <iostream>
#include "SafeArray.h"
#include "SafeArrayOutOfBoundsException.h"
#include <string>
using namespace std;

int main()
{
	try{
		cout<<"Creating Safe Array with 5 elements"<<endl;
		SafeArray < int > s1(5); //creates an array with 5 elements
		cout<<"s1.size(): = "<<s1.size()<<endl;
		cout<<"Successfully created.";
		cout<<endl<<"\nCreating an empty Safe Array"<<endl;
		SafeArray < int > s2; //creates an array with 0 elements
		cout<<"s2.size(): = "<<s2.size()<<endl;
		cout<<"Successfully created.\n\n";
	
		//SafeArray < int > s3(s1); //want to copy all elements in s1 to s3
	
		cout<< "testing at() function by filling s1.at(i) with 10+i\nShould return 11: ";
		for(int i=0; i <s1.size(); i ++)
			s1.at(i) = i+10;
		cout<<s1.at(1)<<endl;
	
		cout<<endl<<"Testing at() function a little more with a new SafeArray: \"Expressions\" \n";
		SafeArray < int > s4(5);
		cout<<"SafeArray s4 has been created with 5 elements, lets square numbers: \n";
		for(int i = 0;i < s4.size();i++)
		{
			s4.at(i) = i + 10; //can use on the left of an =
			cout<<s4.at(i)<<endl;
			s4.at(i) = s4.at(i) * s4.at(i); //can use in an expression
			cout<<s4.at(i)<<endl;
		}
		//returns:
		//10
		//100
		//11
		//121

		//need to fix SafeArrayOutOfBoundsException~!!!
		//******************
		//******************
		//If the user goes outside the bounds of the SafeArray the class should throw an exception. Create a new exception type called SafeArrayOutOfBoundsException. Your driver program (main function) should catch the exception and the program should gracefully exit. Display an error message when that exception is caught.
		//******************
		//******************


		//Overload the [] operator so that you can use the data type like an array.
		cout<<endl<<"Using the overloaded [] operator, makes it more vectorlike";
		cout<<endl<<"lets make another SafeArray, \'s\' with 10 elements: \n";
		SafeArray<int> s(5);
		cout<<"Success, now, lets print 10-14 with s[i]: \n";
			for(int i = 0;i < s.size();i++)
			{
				s[i] = i + 10;
				cout<<s[i]<<endl;
			}
		//should return
			//11
			//12
			//etc
			cout<<endl;

			cout<<"Good, Lets try adding items to the end of the SafeArray\n";
			cout<<"Let us push 2 items to s then pop one off \n\n";
			s.push_back(15);
			s.push_back(16);
			s.pop_back();
			cout<<"\nIf all went well, we should have resized the compacity of the previosly created Safe array\n As a way to make room for \'15\' and \'16\'\nAnd then we will remove the lastnumber, and get this: \n";
			for(int i = 0 ; i<s.size();i++)
				cout<<s[i]<<endl;	

		cout<<"\nIT WORKS! now lets check how many elements are being stored in s, s1 and s2:\n";
			cout<<"s.size = "<<s.size()<<endl;
			cout<<"s1.size = "<<s1.size()<<endl;
			cout<<"s2.size = "<<s2.size()<<endl<<endl;
		cout<<"Seems like s2 is empty, lets fill it with s!\n\t\t(this will require some resizing)\n";
			s2.push_back(s);
			cout<<"\nThe new size of s2 is: " << s2.size();
			cout<<"\nand contains the items: \n";
			for(int i = 0 ; i<s2.size();i++)
				cout<<s2[i]<<endl;	

			cout<<"\nNow that we have s2 filled, lets push s into it again and remove some elements:\n";
			s2.push_back(s);
			for(int i = 0 ; i<s2.size();i++)
				cout<<s2[i]<<endl;	
			//removes 4 items.
			s2.pop_back();s2.pop_back();s2.pop_back();s2.pop_back();
			for(int i = 0 ; i<s2.size();i++)
				cout<<s2[i]<<endl;	

			cout<<"Lets cut s2 in half once: \n";
			s2.resize(s2.size()/2);
			for(int i = 0 ; i<s2.size();i++)
				cout<<s2[i]<<endl<<endl;	
			
			

			cout<<"Checking for out of bounds errors: "<<endl<<endl;
			s1[5555] = 0;
		return 0;
	}
	catch (SafeArrayOutOfBoundsException)
	{
		cout<<"Exception caught!";
		system("pause");
	}
}
	
	