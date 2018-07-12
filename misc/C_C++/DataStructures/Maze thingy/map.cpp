#include<iostream>
#include<fstream>
#include "map.h"
using namespace std;

map::map()
{	
	file =  "C:\\Users\\Matthew\\Google Drive\\DataStructures\\StackLinkedList\\map.txt";
	xCord = 0;
	yCord = 0;	
	setRc();
	buildCells();
	setPointers();

 };
void map::setPointers()
{
	Cell newCell;
	int count = 0;
	//for every single cell
	while(count<getRc()*getRc())
	{
		newCell = cellList.at(count);
		newCell.beenTransversed = false;
		newList.push(newCell);
		//check p_Cell -north (y-1>=0) point to cellList(.x,.y-1)
		
		if(newCell.getY()-1>=0)
			newList.top().p_north = &XY(newCell.getX(),newCell.getY()-1);
		
		if(newCell.getY()+1<=getRc()-1)
			newList.top().p_south = &XY(newCell.getX(),newCell.getY()+1);
		
		if(newCell.getX()-1>=0)
			newList.top().p_west = &XY(newCell.getX()-1,newCell.getY());
		
		if(newCell.getX()+1<=getRc()-1)
			newList.top().p_east = &XY(newCell.getX()+1,newCell.getY());
		
			newCell.beenTransversed = false;
newList.top().Print();
				count++;
	}		
}
//return a cell at chosen x,y
Cell map::XY(int ex, int why)
{
	Cell returnCell;
	returnCell = cellList.at(0);
	for(int i=0;i<cellList.size();i++)
		if(returnCell.getX() != ex || returnCell.getY() != why)
			returnCell = cellList.at(i);
	return returnCell;
}
Cell map::XYnew(int ex, int why)
{
	Cell returnCell; 
	returnCell = newList.at(0);
	for(int i=0;i<newList.size();i++)
		if(returnCell.getX() != ex || returnCell.getY() != why)
			returnCell = newList.at(i);
	return returnCell;
}

void map::buildCells()
{
	//run through .txt to find first rows of cells and give them their type/xycords
    myReadFile.open(file);
	cell.beenTransversed = false;
	while(myReadFile.is_open() && !myReadFile.eof())
	{
		xCord = 0;	
		while(xCord < getRc() && yCord < getRc())
		{
			myReadFile >> output;
			cell.setX(xCord);
			cell.setY(yCord);
			cell.setType(output);
			xCord ++;
			cell.beenTransversed = false;
			cellList.push(cell);		
			cout<<"cell type: "<<cell.getType()<<" (x,y): (" << cell.getX() << ","<< cell.getY() <<")"<<endl;
		}	
	if(yCord > getRc())
		break;
	yCord += 1;
	}
}

void map::setRc()
{	
	double count = 0; //since its always a square, just sqrt count to find rows/columns
	//run through .txt to find rows and columns
	 myReadFile.open(file);
	 if (myReadFile.is_open()) 
		while (!myReadFile.eof()) 
		{
			myReadFile >> output;
			count ++;
		}
		rC = sqrt(count-1);
		cout<<"Building "<< rC <<"x"<< rC<< " Map"<<endl;
		   myReadFile.close();
};
int map::getRc()
{
	return rC;
};

void map::Print()
{
	//print first row, from top-max r/c
	//print next, next next
	int count =0;
	int rowCounter=0;
	int row=getRc();
	while (row > 0)
	{
		if(rowCounter == getRc())
		{
			cout<<"\n";
			rowCounter=0;
			row-=1;
		}
		if(row > 0)
			cout<<newList.at(count).getType()<<" ";
		count += 1;
		rowCounter+=1;
	}

}