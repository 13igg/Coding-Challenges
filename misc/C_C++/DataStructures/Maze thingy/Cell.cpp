#include<iostream>
#include<fstream>
#include "Cell.h"
using namespace std;

Cell::Cell()
{
	x=0;
	y=0;
	type = 'a';
	beenTransversed = false;
	p_north = NULL;
	p_south = NULL;
	p_east = NULL;
	p_west  = NULL;
};

int Cell::getX()
{
	return x;
}
int Cell::getY()
{
	return y;
}	
void Cell::setX(int X)
{
	x = X;
}	
void Cell::setY(int Y)
{
	y = Y;
}
void Cell::setType(char Type)
{
	type = Type;
	beenTransversed = false;
}
char Cell::getType()
{
	beenTransversed = false;
	return type;
}
void Cell::Print()
{
	cout<<"Cell type: "<< getType();
	if(p_north!=0)
		cout << " Cell points north to: "<<p_north->getType()<<" \n";
	
	if(p_south!=0)
		cout<<" Cell points south to "<<p_south->getType()<<" \n";
	
	if(p_east!=0)
		cout<< " cell points east to: "<< p_east->getType()<<" \n";
		
	if(p_west!=0)
		cout<< " Cell points west to "<<p_west->getType()<<" \n";

	cout<<" \n";
}