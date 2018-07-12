#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include "Queue.h"
using namespace std;

template <class T>
class BSTree
{
        public:
			BSTree();
			~BSTree();
		void	insert(const T& elem);
		void	remove(const T& elem);
		void	printInOrder();
		void	printPreOrder();
		void	printPostOrder();
		bool	search(const T& d); 
		int		size(); //num elements
		T		findMax(); //maximum value in tree
		T		findMin(); //minimum value in tree
		int		heightOfTree();//return height of the tree
		double	percentLeaf();//percentage of nodes that are leafs
		double	percentInterior();//percentage of nodes that are interior
	
		//goodluck here
		void	printInTreeForm();//print looking like a tree
       
		private:
			struct Node
			{
				T data;
				Node* p_left;
				Node* p_right;
			};
			Node* p_root;

		void	insertHelper(const T& elem, Node*& p_node);
		void	arrInsertHelper(vector<Node*> arr, int pos);
		void	removeHelper(const T& elem, Node*& p_node);
		bool	searchHelper(const T& elem, Node*& p_node);
		T	    minMaxHelper(Node*& p_node,int minMax);	
		void	percentHelper(Node*& p_node);
		int		heightHelper(Node*& p_node);
		void	inOrderHelper(Node*& p_node);
		void	preOrderHelper(Node*& p_node);
		void	postOrderHelper(Node*& p_node);
		int	numElements;
		double numInterior;
		int height;
		double numLeafs;
		Queue<Node*> queue;
		void buildQueue(vector<Node*>& arr);//queue for breadth tree
		T elem;
};

template <class T>
BSTree<T>::BSTree()
{
	p_root = 0;
	numElements = 0;
	numInterior = 0;
	numLeafs = 0;
	height = 0;
}

template <class T>
void BSTree<T>::insert(const T& elem)
{
	insertHelper(elem,p_root);
		numElements++;
}
template <class T>
void BSTree<T>::insertHelper(const T& elem, Node*& p_node)
{
	if(p_node ==0)
	{
		p_node = new Node;
		p_node->data = elem;
		p_node-> p_left = 0;
		p_node->p_right = 0;
	}
	else if(elem<=p_node->data)
	{
		insertHelper(elem,p_node->p_left);
						////straight
						//if(!isBalanced(p_node))
						//{
						//	balanceLeft(p_node);
						//	//crooked
						//	if(!isBalanced(p_node)
						//	{
						//		balanceLeft(p_node->p_right);
						//		balanceRight(p_node);
						//	}
						//}
	}
	else
	{
		insertHelper(elem,p_node->p_right);
						////straight
						//if(!isBalanced(p_node))
						//{
						//	balanceRight(p_node);
						//	//crooked
						//	if(!isBalanced(p_node)
						//	{
						//		balanceRight(p_node->p_left);
						//		balanceLeft(p_node);
						//	}
	}
}
template <class T>		
void BSTree<T>::remove(const T& elem)
{
	removeHelper(elem,p_root);
		numElements--;
}
template <class T>
void BSTree<T>::removeHelper(const T& elem, Node*& p_node)
{
	if(p_node->p_left == 0 && p_node->p_right == 0 && elem == p_node->data)
	{
		//leaf node
		p_node = 0;
		cout<<"\nLeaf node, deleting\n";
	}
	else if(p_node->p_left !=0 && p_node->p_right != 0 && elem == p_node->data)
	{
		//2 child
		cout<<"Item has 2 children, deleting it!\n";
		//move the item all the way down to a leaf, then DELETE IT! MUWHAHHAHAHAHAH
		//ok so how to do this...
	}
	else if((p_node->p_left !=0 || p_node->p_right != 0) && elem == p_node->data)
	{
		//1 child
		cout<<"Item has 1 child, deleting it!\n";
		if(p_node-> p_left != 0)
		{
			Node* temp;
			temp = p_node->p_left;
			delete [] p_node;
			p_node = temp;
		}
		else
		{
			Node* temp;
			temp = p_node->p_right;
			delete [] p_node;
			p_node = temp;
		}
	}
	else if(elem<=p_node->data)
		removeHelper(elem,p_node->p_left);
	else if(elem>p_node->data)
		removeHelper(elem,p_node->p_right);
	
	

}

template <class T>
void BSTree<T>::printInOrder()
{
	//start at root
	//transverse left
	//process node
	//traverse right
	inOrderHelper(p_root);
}
template<class T>
void BSTree<T>::inOrderHelper(Node*& p_node)
{
	if(p_node != 0)
	{
		inOrderHelper(p_node->p_left);
		cout<<p_node->data<< " ";
		inOrderHelper(p_node->p_right);
	}
}
template <class T>
void BSTree<T>::printPreOrder()
{
	preOrderHelper(p_root);
}
template <class T>
void BSTree<T>::preOrderHelper(Node*& p_node)
{
	if(p_node != 0)
	{
		cout<<p_node->data<< " ";
		preOrderHelper(p_node->p_left);		
		preOrderHelper(p_node->p_right);
	}
	
}
template <class T>
void BSTree<T>::printPostOrder()
{
	postOrderHelper(p_root);
}
template<class T>
void  BSTree<T>::postOrderHelper(Node*& p_node)
{
	if(p_node != 0)
	{
		postOrderHelper(p_node->p_left);		
		postOrderHelper(p_node->p_right);
		cout<<p_node->data<< " ";
	}
}

template <class T>
BSTree<T>::~BSTree()
{
	//post order delete bottom up.
}
template <class T>
bool BSTree<T>::search(const T& d)
{
	return searchHelper(d,p_root);
}
template <class T>
bool BSTree<T>::searchHelper(const T& elem, Node*& p_node)
{
	if(p_node == 0)
		return false;
	else if(elem == p_node->data)
		return true;
	else if(elem <= p_node->data)
		searchHelper(elem,p_node->p_left);
	else 
		searchHelper(elem,p_node->p_right);
	
}
template <class T>
int	BSTree<T>::size() //num elements
{
	return numElements;
}
template <class T>
T BSTree<T>::findMax() //maximum value in tree
{
	return minMaxHelper(p_root,1);
}
template <class T>
T BSTree<T>::findMin() //minimum value in tree
{
	return minMaxHelper(p_root,0);
}
template <class T>
T BSTree<T>::minMaxHelper(Node*& p_node,int minMax)	
{
	//minMax = 0 min
	//minMax = 1 max	
		if(minMax == 0)
			if(p_node->p_left == 0)
				return p_node->data;
			else
				minMaxHelper(p_node->p_left,0);
		else
			if(p_node->p_right == 0)
				return p_node->data;
			else
				minMaxHelper(p_node->p_right,1);	
}

template <class T>
int	BSTree<T>::heightOfTree()//return height of the tree
{
	return heightHelper(p_root);
}
template <class T>
int	BSTree<T>::	heightHelper(Node*& p_node)
{
	int heightLeft=0;
    int heightRight=0;

    if (p_node == 0)
	{
       heightLeft = 0;
	   heightRight = 0;
	}
    else 
	{
	   //get height of left side of tree
       heightLeft = heightHelper(p_node->p_left) + 1;
	   //get height of right side of tree
	   heightRight = heightHelper(p_node->p_right) + 1;
	}
     
    if(heightRight > heightLeft) {
		return heightRight; height = heightRight;}
    else{
		return heightLeft;height = heightLeft;}
}
template <class T>
double	BSTree<T>::percentLeaf()//percentage of nodes that are leafs
{
	numLeafs = 0;
	numInterior = 0;
	percentHelper(p_root);
	return (numLeafs/(numInterior+numLeafs));
}
template <class T>
double	BSTree<T>::percentInterior()//percentage of nodes that are interior
{
	numInterior = 0;
	numLeafs = 0;
	percentHelper(p_root);
	return (numInterior/(numInterior+numLeafs));
}
template <class T>
void BSTree<T>::percentHelper(Node*& p_node)
{
	if(p_node != 0)
	{
		percentHelper(p_node->p_left);
		if(p_node -> p_left != 0 || p_node -> p_right !=0)
			numInterior ++;
		else
			numLeafs ++;
		percentHelper(p_node->p_right);
	}
	
}

template <class T>
void	BSTree<T>::printInTreeForm()//print looking like a tree
{
	int vecSize = 0;
	for(int i = 0; i < heightOfTree(); i++)
		vecSize += pow(2.0,heightOfTree()-1-i);
	vector<Node*> arr(vecSize);//create the array with the size of the tree(every possible node)
	for(int i = 0; i < arr.size(); i++)
		arr[i] = 0; //set all the  nodes to null
		
	//building array of the tree
	///build queue starting with p_root
	buildQueue(arr);
	arrInsertHelper(arr, 0);	
	
 }
template <class T>
void BSTree<T>::buildQueue(vector<Node*>& arr)
{	
	queue.enque(p_root);
	Node* x = new Node;
	int count =0;
	while(!queue.isEmpty())
	{
		queue.deque(x);
		cout<<x->data<<endl;
		arr[count] = x;
		count ++;
		if(x->p_left != 0)
			queue.enque(x->p_left);
		if(x->p_right != 0)
			queue.enque(x->p_right);
	}
		/*
			Create a queue Q of nodes to visit.
		Enqueue the tree root into Q.

		While Q is not empty:
		Dequeue an element from the queue, call it u.
		Output u.

		If u has a left child, add that to the queue.
		If u has a right child, add that to the queue.
	*/
}
template <class T>
void BSTree<T>::arrInsertHelper(vector<Node*> arr, int pos)
{
		int left = pos*2 + 1;
		int right = pos*2 +2;
		if(arr[pos] != 0)
			elem = arr[pos]->data;
		if(arr[pos]==NULL)
		{
			arr[pos] = new Node;
			arr[pos]-> data = elem;
			arr[pos]-> p_left = 0;
			arr[pos]->p_right = 0;
				//dasf
		}
		else if(elem <= arr[pos] -> data)
			arrInsertHelper(arr, (2*pos)+1);
		else
			arrInsertHelper(arr, (2*pos)+2);
}
/*
				0
		   1         2
		 3   4     5    6
		7 8 9 10 11 12 13 14


		turning tree into array base tree
		height of tree determis length of array
		
		init all pointers to null
		move through tree and store pointers to nodes at their correct postions in array
		go through array and print:
		leadign spaces
		values
		arr = new Node[pow(2,height)-1]
		xx (or ..)

		  int left = pos*2 + 1;
		int right = pos*2 +2;
		if(arr[pos]==NULL)
		{
			arr[pos] x = new Node;
				//
		}
		else if(data <= arr[pos] -> data)
			arrInsertHelper(data, (2*pos)+1);
		else
			arrInsertHelper(data,(2*pos)+2);

	*/



