#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Cell
{
public:
	Cell();
	char getType();
	void setType(char Type);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void Print();
	bool beenTransversed;
		Cell *p_north;
		Cell *p_south;
		Cell *p_east;
		Cell *p_west;
private:
		int x;
		int y;
		char type;	
		
};

