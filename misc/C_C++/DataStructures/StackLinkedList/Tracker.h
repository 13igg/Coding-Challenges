#pragma once
#include <iostream>
#include "map.h"
#include "Cell.h"
#include "StackLinkedList.h"
using namespace std;

class Tracker
{
public:
		Tracker(map* m1);
		map *m;

		void setPositions();		
		void solve();
		void printSolution();
		void checkNorth();
			void checkSouth();
			void checkEast();
			void checkWest();
		StackLinkedList<Cell> solution;
		Cell currentCell;
private:
	int curX;
	int curY;
	int startX;
	int startY;
	int endX;
	int endY;
};
