#pragma once
template <class T>
class Queue
{
public:
	Queue();
	~Queue();
        void enque(const T& elem);
		void deque(T& elem);
		bool isEmpty();
		int size();
		T* getHead();
private:
	struct Node
	{
		T data;
		Node * p_link;
	};
	Node* p_head;
	Node* p_tail;
	int numElements;
};

template <class T>
Queue<T>::Queue()
{
	p_head = NULL;	
	p_tail = NULL;
	numElements = 0;
}
template <class T>
Queue<T>::~Queue()
{

}
template<class T>
void Queue<T>::enque(const T& elem)
{
	int count = 0;
	Node* p_newNode = new Node;
	if(isEmpty())
	{
		p_newNode -> data = elem;
		p_tail = p_newNode;
		p_head = p_newNode;
	}
	else
	{
		p_newNode -> data = elem;
		p_tail->p_link = p_newNode;
		p_tail = p_newNode;
	}
	
	numElements ++;
}
template<class T>
void Queue<T>::deque(T& elem)
{
	if(isEmpty() || size()==1){elem  = p_head->data; p_head = NULL;	p_tail = NULL;	numElements --;}
	else{		
			elem  = p_head->data;
			p_head -> data;
			p_head = p_head->p_link;
			numElements --;	
		}
}
template<class T>
int Queue<T>::size()
{
	return numElements;
}
template<class T>
bool Queue<T>::isEmpty()
{
	if(size()==0)
		return true;
	else
		return false;
}
