#pragma once
template <class T>
class StackLinkedList
{
public:
	StackLinkedList();
	~StackLinkedList();
        void push(const T& elem);
		void pop();
		T at(int pos);
		T& top();
		bool isEmpty();
		int size();
		T* getLink(T current);
		T* getHead();
private:
	struct Node
	{
		T data;
		Node * p_link;
	};
	Node* p_head;
	int numElements;
};

template <class T>
StackLinkedList<T>::StackLinkedList()
{
	p_head = NULL;	
	numElements = 0;
}

template <class T>
void StackLinkedList<T>::push(const T& elem)
{
	Node* p_newNode = new Node;
		p_newNode -> data = elem;
		p_newNode -> p_link = p_head;
		p_head = p_newNode;
	numElements++;
}

template <class T>

int StackLinkedList<T>::size()
{
	return numElements;
}

template <class T>
T* StackLinkedList<T>::getLink(T current)
{}
template <class T>
T* StackLinkedList<T>::getHead()
{return p_head->data;}

template<class T>
T StackLinkedList<T>::at(int pos)
{
	Node* p_current;
	T cell;
	p_current = p_head;
	cell = p_current->data;
	if(pos >= 0 && pos <= size()-1)
	{
		for(int i=0;i<pos;i++)
		{
			p_current = p_current->p_link;
			cell = p_current->data;
		}
	}
	return cell;
}
template <class T>
bool StackLinkedList<T>::isEmpty()
{
	return p_head == 0;
}

template <class T>
void StackLinkedList<T>::pop()
{
	Node* p_deleteNode = new Node;
	p_deleteNode = p_head;
		p_head = p_deleteNode -> p_link;
		numElements -= 1;
		delete p_deleteNode;
}

template <class T>
T& StackLinkedList<T>::top()
{
	return p_head->data;
}

template <class T>
StackLinkedList< T>::~StackLinkedList()
{
	cout<<"Deconstructing the linked list"<<endl;
	while(!isEmpty())
	{ 
		pop();
	}
}
