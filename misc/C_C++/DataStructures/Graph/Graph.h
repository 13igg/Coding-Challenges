/*
Graphs
a router has several interfaces/ports on each side - router is big expensive machience - receives packet-looks up a tables where to send it
connections in and out, receives a packet of data that needs to be delivered - knows address of destination computer
destination      |       interface
ip addresses     |		4
ip addresss      |		6
		each router knows about every other router


			directed graph example - cannot go from 1 to 3 per say. only 1 way, down in this example
					 	 0
					 10/  \5
				      1	    2
				     20\ 10/ \5
					     4    3

		1s are connections
	0	1	2	3	4
0	1	1	1	0	0
1	0	1	0	0	1
2	0	0	1	1	1
3	0	0	0	1	0
4	0	0	0	0	1

now need to store weights to travel through an edge - replace 1's with weights
													  replace 0s with intmax/infinities
					
	replace 1's on diagonal with 0s
weight table			to
		0	1	2	3	4
	0	0	10	5	10	15 //update with hop table
	1	00	0	00	00	20
from2	00	00	0	5	10
	3	00	00	00	0	00
	4	00	00	00	00	0

need another table - non 0, non hop values- 
	"next hop table"
	//add a new value, update total cost in weight table
	0	1	2	3	4
0	-	1	2	2	2
1	-	-	-	-	4
2	-	-	-	3	4
3	-	-	-	-	-
4	-	-	-	-	-


need to use Dijkstra's algorthm
weight - ability to move from 1 point to	the next
				//
		-//				//-
				//

	0 connects to 1 and 1 connects to 4 therfore 0 connects to 4
			10					20						30
						
	0 connects to 2 and 2 connects to 4 therfore 0 connects to 4 - take this path
			5					10						15

finding optimal path
look for commaniality in from and two  
	common counter follows verticies (safearray container of things in the graph)
		look where the weight table from i to common is a good value

		n^3
for(int common = 0; commom < verticies.size(); common++) 
	for(int i = 0; i < verticies.size(); i +=)
		if(weightTable[i][common] != //00(infinty)) -i is from - common is to
			for(int j = 0; j <verticies.size(); j++)
				if(weightTable[common][j] != //00(infinighy) -from common  - to j
					//indirect connection from i to j
					//i->common   common->j  => i->j
					//update weight to show indirect connection -  i-common cost + common to j cost 
					//check weight table to see if old value is bigger than new value, if it is, update it
					//update hop table to show common
			


GraphAdjMatrix(int s); //initial size - graphs houdl expand appropriately - therfor needs to increce verticies, but also the weight and next top table need new row and column
weight table and next hop shoudl be created dynamically - do it in constructor, deconstruct it later
graph type is the tmplated part

safe array to hold verticies
*/



#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "SafeArray.h"
using namespace std;

template <class T>
class Graph
{
        public:
				Graph();
				Graph(int s);
               ~Graph();
				void addVertex(T& v);
				void setEdge(T& from, T& to, int weight);
				void topSort(); //top sort only works when there are no cycles in the graph
				bool isEmpty();
				int size();
				bool getEdge(const T& fromVertex, const T& toVertex);
				int getEdgeWeight(const T& fromVertex, const T& toVertex);
				SafeArray < T* > getIncomingNeighbors(const T& vertex);
				SafeArray < T* >  getOutgoingNeighbors(const T& vertex);
				void print(); //print each vertex and all of its incoming and outgoing neighbors 
				void printRoutingTable(); //print the total weight and next hop to get to each vertex
	private:
			int Size;
			SafeArray < T* > topSortHelperIn(const T& vertex);//used to delete the weights in temp table
			SafeArray < T* > topSortHelperOut(const T& vertex);//used to delete the weights in temp table
				SafeArray<T> vertices; //
				int ** nextHopTable;//Hop table, changes to show next hops
				int ** weightsTable; //holds the inital weights
				int ** tempTable;//table used in "topSortHelperIn and topSortHelperOut" -will be emptied later
				int ** indirectWeightsTable; //holds total weights
};

template <class T>
Graph<T>::Graph()
{
	weightsTable = new int*[0];//Main weights table, takes in original weights
	nextHopTable = new int*[0];//Hop table, changes to show next hops
	tempTable = new int*[0];//table used in "topSortHelperIn and topSortHelperOut" -will be emptied later
	indirectWeightsTable = new int*[0];//used to show final weights, indirect and direct
	Size = 0;
}
template <class T>
Graph<T>::Graph(int s)
{
	Size = s;
	weightsTable = new int*[size()];//Main weights table, takes in original weights
	nextHopTable = new int*[size()];//Hop table, changes to show next hops
	tempTable = new int*[size()];// table used in "topSortHelperIn and topSortHelperOut"-will be emptied later
	indirectWeightsTable = new int*[size()];//used to show final weights, indirect and direct
}

template <class T>
void Graph<T>::addVertex(T& v)
{
	vertices.push_back(v);
	Size++;
	
	for(int i = 0; i < size(); i++)
	{
		weightsTable[i] = new int[size()];
		nextHopTable[i] = new int[size()];
		tempTable[i] = new int[size()];
		indirectWeightsTable[i] = new int[size()];
	}
	
	for(int r = 0; r <size(); r++)
		for(int c = 0; c<size(); c++)
			if(r==c)
			{
				indirectWeightsTable[r][c] = -1;//diagonal
				nextHopTable[r][c] = -1;//diagonal
				weightsTable[r][c] = 0; //diagonal
				tempTable[r][c] = 0; //diagonal
			}
			else
			{
				indirectWeightsTable[r][c] = -1;//everything else
				nextHopTable[r][c] = -1;//everything else
				weightsTable[r][c] = -1;//everythign else
				tempTable[r][c] = -1;
			}

	//print();
}

template <class T>
void Graph<T>::setEdge(T& from, T& to, int weight)
{
	//graph.setEdge(chicago, minneapolis, 354);
	for(int r = 0; r < size(); r ++)
		if(vertices[r] == from)
			for(int c = 0; c<size(); c++)
				if(vertices[c] == to)
				{
					weightsTable[r][c] = weight;
					tempTable[r][c] = weight;
					indirectWeightsTable[r][c] = weight;
					nextHopTable[r][c] = c;
					break;
				}	
}

template <class T>
void Graph<T>::topSort()
{

	//pick a vertex w/ no incoming edges list it
	//remove selected vertex outgoing edges
	//repeat until no more edgesa 
	cout<<"\nFinding a path through the graph:\n";
	bool con; //continue if not already used
	SafeArray <T> chosen;
	for(int i = 0; i < size(); i ++)
	{
		SafeArray < T* > outgoingNeighbors(topSortHelperOut(vertices[i]));
		SafeArray < T* > incomingNeighbors(topSortHelperIn(vertices[i]));
		con = true;
		if(incomingNeighbors.size() == 0)
			{
				for(int k = 0; k < chosen.size();k++)
					if(chosen[k] == vertices[i])//checks chosen to see if it hasalready been used
					{con = false; break;}
					if(con)
					{				
						chosen.push_back(vertices[i]);
						cout<<"\t"<<vertices[i]<<endl;
							for(int j = 0; j < size();j++)
								tempTable[i][j] = 0;
								i=0;
					}
			}
	}
}
template <class T>
SafeArray < T* > Graph<T>::topSortHelperIn(const T& vertex)
{
	int j=0;
	SafeArray < T* > incomingNeighbors;
	for(int i = 0; i < size(); i ++)
		if(vertices[i] == vertex)
			 j = i;
	for(int  i = 0; i <size(); i ++)
		if(tempTable[i][j] != 0 && tempTable[i][j] != -1)
			incomingNeighbors.push_back(&vertices[i]);
	return incomingNeighbors;
}
template <class T>
SafeArray < T* > Graph<T>::topSortHelperOut(const T& vertex)
{
	int j=0;
	SafeArray < T* > outgoingNeighbors;
	for(int i = 0; i < size(); i ++)
		if(vertices[i] == vertex)
			 j = i;
	for(int  i = 0; i <size(); i ++)
		if(weightsTable[j][i] != 0 && weightsTable[j][i] != -1)
			outgoingNeighbors.push_back(&vertices[i]);
	return outgoingNeighbors;
}
template <class T>
bool Graph<T>::isEmpty()
{
	return Size == 0 ? true:false;
}
template <class T>
int Graph<T>:: size()
{
	return Size;
}
template <class T>
bool Graph<T>::getEdge(const T& fromVertex, const T& toVertex)
{
	return nextHopTable[fromVertex][toVertex] != -1 ? true:false;
}
template <class T>
int Graph<T>::getEdgeWeight(const T& fromVertex, const T& toVertex)
{
	return getEdge(fromVertex,toVertex) ? indirectWeightsTable[fromVertex][toVertex] : INT_MAX;
}
template <class T>
SafeArray < T* > Graph<T>::getIncomingNeighbors(const T& vertex)
{
	int j=0;
	SafeArray < T* > incomingNeighbors;
	for(int i = 0; i < size(); i ++)
		if(vertices[i] == vertex)
			 j = i;
	for(int  i = 0; i <size(); i ++)
		if(weightsTable[i][j] != 0 && weightsTable[i][j] != -1)
			incomingNeighbors.push_back(&vertices[i]);
	return incomingNeighbors;
}
template <class T>
SafeArray < T* > Graph<T>::getOutgoingNeighbors(const T& vertex)
{
	int j=0;
	SafeArray < T* > outgoingNeighbors;
	for(int i = 0; i < size(); i ++)
		if(vertices[i] == vertex)
			 j = i;
	for(int  i = 0; i <size(); i ++)
		if(weightsTable[j][i] != 0 && weightsTable[j][i] != -1)
			outgoingNeighbors.push_back(&vertices[i]);
	return outgoingNeighbors;
}
template <class T>
void Graph<T>:: print()
{
	cout<<"\n*********************************\n";
	for(int i = 0; i < size(); i++)
		{
			cout<<"\n";
			SafeArray < T* > outgoingNeighbors(getOutgoingNeighbors(vertices[i]));
			SafeArray < T* > incomingNeighbors(getIncomingNeighbors(vertices[i]));
			cout<<vertices[i]<< endl<< "Incoming neighbors:\n";
			for(int j = 0; j <incomingNeighbors.size(); j++)
				cout<<"\t"<<*incomingNeighbors[j]<<endl;
			cout<<"\nOutgoing neighbors:\n";
			for(int j = 0; j <outgoingNeighbors.size(); j++)
				cout<<"\t"<<*outgoingNeighbors[j]<<endl;
			cout<<"\n*********************************\n";
		}
	
						/*
						cout<<"\nWEIGHTS TABLE\n";
						for(int i = 0; i <vertices.size(); i ++)
						{				
								for(int r = 0; r < size(); r++)
								{
										for(int c = 0; c<size(); c++)
											cout<<" "<<	weightsTable[r][c] <<" ";	
									cout<<"vertex: "<<vertices[i];				
									i++;
									cout<<endl;
								}			
								cout<<endl;
						}
	
						cout<<"\nINDIRECT WEIGHTS TABLE\n";
						for(int i = 0; i <vertices.size(); i ++)
						{				
								for(int r = 0; r < size(); r++)
								{
										for(int c = 0; c<size(); c++)
											cout<<" "<<	indirectWeightsTable[r][c] <<" ";	
									cout<<"vertex: "<<vertices[i];				
									i++;
									cout<<endl;
								}			
								cout<<endl;
						}
	
						cout<<"\nHOP TABLE\n";
						for(int i = 0; i <vertices.size(); i ++)
						{				
								for(int r = 0; r < size(); r++)
								{
										for(int c = 0; c<size(); c++)
											cout<<" "<<	nextHopTable[r][c] <<" ";	
									cout<<"vertex: "<<vertices[i];				
									i++;
									cout<<endl;
								}			
								cout<<endl;
						}
						*/
} //print each vertex and all of its incoming and outgoing neighbors 
template <class T>
void Graph<T>::printRoutingTable()
{
for(int common = 0; common < size(); common++) 
	for(int i = 0; i < size(); i ++)
		if(indirectWeightsTable[i][common] != -1)// from i to common
			for(int j = 0; j <size(); j++)
				if(indirectWeightsTable[common][j] != -1)//from common  - to j
				{
					//used for testing things	
					/*	cout<<"i: "<<i<<" j: "<<j<<" common: "<<common<<"\n\n";
						cout<<"from "<< i<< " to " <<common<<"\n";
						cout<<"from "<< common<< " to " <<j<<"\n";
						cout<<"from "<< i<< " to " <<j<<"\n";
						cout<<"from "<< common<< " to " <<j<<" + "<<"from "<< i<< " to " <<common;
						cout<<"from "<< i<< " to " <<j<<" = " <<(indirectWeightsTable[i][j]);	
						cout<<endl<<(indirectWeightsTable[common][j] + indirectWeightsTable[i][common])<<endl;
					*/
					int previous = indirectWeightsTable[i][j];
					indirectWeightsTable[i][j] = (indirectWeightsTable[common][j] + indirectWeightsTable[i][common]);
																	
					if( (indirectWeightsTable[common][j] + indirectWeightsTable[i][common]) > previous)
						previous!=-1 ? indirectWeightsTable[i][j] = previous : nextHopTable[i][j] = common;
					else
						nextHopTable[i][j] = nextHopTable[i][common];
				}

	for(int i = 0; i < size(); i ++)
	{
		SafeArray < T* > outgoingNeighbors(getOutgoingNeighbors(vertices[i]));
		cout<<"\n"<<vertices[i];
			for(int j = 0; j < size(); j ++)
				if(nextHopTable[i][j] != -1)
					cout<<endl<<"\t"<<vertices[j]<<": "<<indirectWeightsTable[i][j]<<" Next Hop: " << vertices[nextHopTable[i][j]];
		cout<<"\n";
	}

} //print the total weight and next hop to get to each vertex
template <class T>
Graph<T>::~Graph()
{
 	delete [] weightsTable;
	delete [] nextHopTable;
	delete [] indirectWeightsTable;
	delete [] tempTable;
}
