#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include "MemoryManager.h"
using namespace std;


MemoryManager::MemoryManager(int s) //num elements
{
	p_mem = new char[s + (2 * sizeof(Node))];
	p_begin = (Node*)p_mem;
	p_end = (Node*)(p_mem+s+sizeof(Node));
	p_current = NULL;

	p_end->previous = p_begin;
	p_end->size = 0;
	p_end->next = NULL;
	p_end->isFree = false;
	
	p_begin->next = p_end;
	p_begin->size = s;
	p_begin->previous = NULL;
	p_begin->isFree = true;
	cout<<(int)p_begin<<"\n"<<(int)p_mem<<endl<<endl;
}
MemoryManager::~MemoryManager()
{
	delete [] p_mem;
}
void MemoryManager::dump()
{
	p_current = p_begin;//start at the beginning
	int block = 1;//keeps track of the memory blocks
	while(p_current->next != NULL) //and print every block
	{		
		if(p_current->isFree == true)//prints if the memory block is free/notfree and its space
			cout<<block<<": "<<p_current->size<<" bytes of free space"<<endl;
		else
			cout<<block<<": "<<p_current->size<<" bytes of used space"<<endl;
		block++;
		p_current = p_current->next;//move pcurrent over one
	}
}
void MemoryManager::deallocate(int*p)
{
	p_current = (Node*)((char*)p-sizeof(Node));//assign p_current to the address of the pointer we need to deallocate
	if(p != 0)
		p_current->isFree = true;		
	//combines alike free spaces
	while(true && p != 0)
	{
		//combines pcurrent and its next's free space
		if(p_current->next->next != NULL && p_current->next->isFree)
			{
				//gets the size of the new combination
				p_current->next->size += sizeof(Node) + p_current->size;
				//when there is 3 nodes (begin mid end) and they are all free, combine them
				if(p_current->previous == NULL && p_current->next->next == p_end)
				{
					p_begin ->size = p_current->next->size; 
					p_current->next->next->previous = p_begin;
					p_end->previous = p_begin;					
					p_begin->next=p_end; 
					p_current = NULL;
					break;
				}									
					p_current->previous->next = p_current->next;
					p_current->next->previous = p_current->previous;
					p_current = p_begin;//move p current tothe beginning for another search
			}
		//combines the size of pcurrents previous and itself
		else if(p_current->previous != NULL && p_current->previous->isFree)
			{				
				p_current->previous->size += sizeof(Node) + p_current->size;
				p_current->previous->next = p_current->next;
				p_current->next->previous = p_current->previous;
				p_current = p_begin;//move pcurrent to the beginning for another search
			}
		else
			break;//break out of the loop when there are no combinations to be made
		}
		p_current = NULL;//set pcurrent to null to remove it
}
void* MemoryManager::allocate(int bytes)
{
	Node* p_node;
	p_current = p_begin;
	int totalSize = bytes+sizeof(Node);//adds total needed + a size of a node
    //Moves current through all the nodes till one is free and has the most space
		while(p_current->isFree != true || (p_current->size+sizeof(Node)) <= bytes)//change this to make it work for largest first (insetead of a while, count how many nodes there are and forloop through them
			{
				totalSize+=p_current->size+sizeof(Node);//runing sum of total size of the allocation spot
				if(p_current->next == NULL)
					return NULL;//returns null if such a space does not exist
				else
				{//need to check the sizes here for largest first
						p_current = p_current->next; //moves right one node	
				}				
			}
		//assigning p_node to the right address
		p_node = (Node*)(p_mem+totalSize);
		//creating the new nodes free space
		p_node->isFree = true; //able to hold data
		p_node->size = p_current->size-sizeof(Node)-bytes; //recalculating free space
		p_node->previous = p_current; //previous is now equal to the current cursor
		p_node->next = p_current->next;//set the nexts equal
			
		//updates current to reflect its new useable space //new node is now in the middle of p_current and p_current's old nexts previous//
		p_current->isFree = false;//not able to hold more
		p_current->next->previous = p_node; //moves the next node's previous pointer to the newly created node
		p_current->size = bytes; //gives it the required size of the data
		p_current->next = p_node; //points to the newly created node
			
			return (((char*)(p_current)+sizeof(Node))); //returns a void* so that it is empty



 }
