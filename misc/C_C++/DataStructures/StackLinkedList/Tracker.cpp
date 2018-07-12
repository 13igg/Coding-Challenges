#include<iostream>
#include<fstream>
#include "Tracker.h"
#include "Cell.h"
#include "StackLinkedList.h"
#include "map.h"
using namespace std;

Tracker::Tracker(map* m1)
{	 	 
	 curX=0;
	 curY=0;
	 startX=0;
	 startY=0;
	 endX=0;
	 endY=0;
	 m=m1;
	 setPositions();
	 solve();
	 printSolution();
	
	
};

void Tracker::solve()
{
	//start at S
	//while current cell != E
	currentCell = m->XYnew(startX,startY);
	currentCell.beenTransversed = true;
	solution.push(currentCell);
	while(currentCell.getType() != 'E')
	{
		//if any are free, transverse to it
		//if it is a blocked one, continue checking
	//check north for a free cell
		if(solution.top().p_north != 0)
			checkNorth();
	//check east
		else if(solution.top().p_east != 0)
			checkEast();
	//check south
		else if(solution.top().p_south != 0)
			checkSouth();
	//check west
	   else if(solution.top().p_west != 0)
			checkWest();
		else
		 //traverse backwards 1 - check rest that havenot been transversed yet
		{
			solution.pop();
			currentCell = solution.top();
		}
	}
}
void Tracker::checkNorth()
{
	if(currentCell.p_north->getType() == 'F' && currentCell.p_north->beenTransversed == false)
			{
				currentCell.p_north->beenTransversed = true;
				currentCell = m->XY(currentCell.p_north->getX(),currentCell.p_north->getY());
				solution.push(currentCell);
			}
}

void Tracker::checkSouth()
{
	if(currentCell.p_south->getType() == 'F' && currentCell.p_south->beenTransversed == false)
		{
			currentCell.p_south->beenTransversed = true;
			currentCell = m->XY(currentCell.p_south->getX(),currentCell.p_south->getY());
			solution.push(currentCell);
		}
}

void Tracker::checkEast()
{
	if(currentCell.p_east->getType() == 'F' && currentCell.p_east->beenTransversed == false)
		{
			currentCell.p_east->beenTransversed = true;
			currentCell = m->XY(currentCell.p_east->getX(),currentCell.p_east->getY());
			solution.push(currentCell);
		}
}

void Tracker::checkWest()
{
	if(currentCell.p_west->getType() == 'F' && currentCell.p_west->beenTransversed == false)
		{
			currentCell.p_west->beenTransversed = true;
			currentCell = m->XY(currentCell.p_west->getX(),currentCell.p_west->getY());
			solution.push(currentCell);
		}
}
void Tracker::printSolution()
{
	int count =0;
	int rowCounter=0;
	int row=m->getRc();
	while (row > 0)
	{
		if(rowCounter == m->getRc())
		{
			cout<<"\n";
			rowCounter=0;
			row-=1;
		}
		if(row > 0 && (m->newList.at(count).getX() != currentCell.getX() && m->newList.at(count).getY() != currentCell.getY()))
			cout<<"X ";
		else
			cout<<"O ";
		count += 1;
		rowCounter+=1;
	}
}
void Tracker::setPositions()
{
	//check every cell first and find coords of start and end
	for(int i=0;i<m->newList.size();i++)
	{
		if(m->newList.at(i).getType() == 'S')
			//start x = x y = y
		{
			startX = m->newList.at(i).getX();
			startY = m->newList.at(i).getY();
		}
		else if(m->newList.at(i).getType() == 'E')
		{
			endX = m->newList.at(i).getX();
			endY = m->newList.at(i).getY();
		}
	}
}