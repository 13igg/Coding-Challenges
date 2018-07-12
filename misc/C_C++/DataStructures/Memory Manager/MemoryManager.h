#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class MemoryManager
{
	
        public:
			MemoryManager(int s);
			~MemoryManager();
			void* allocate(int bytes);//- takes an integer representing the number of bytes requested from the memory manager and returns the address of the block on the heap.
			void deallocate(int* p);//- takes a pointer that holds the address of the block of memory to be released.
			void dump();//- prints information about all the blocks currently being tracked in the system.
				
		private:
			
			struct Node
			{
				bool isFree;
				int size;
				//int usedSize;
				Node* previous;
				Node* next;
			};
			Node* p_current;

			char * p_mem;
			Node* p_begin;
			Node* p_end;

		
};

