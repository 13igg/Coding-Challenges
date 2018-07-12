#pragma once
#include <iostream>
#include <fstream>
#include "Cell.h"
#include "StackLinkedList.h"
using namespace std;

class map
{
public:
		map();
		ifstream myReadFile;
		string file;
		Cell cell;	
		Cell XY(int ex, int why);
		Cell XYnew(int ex, int why);
		int getRc();
		StackLinkedList<Cell> newList;	
		void Print();

private:

		char output;	
		void setRc();
		int rC, yCord, xCord;
		void buildCells();	
		
		void setPointers();	
		StackLinkedList<Cell> cellList;
};
