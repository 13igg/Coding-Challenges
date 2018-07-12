#pragma once

template <class T>
class OrdLinkedList
{
public:
	OrdLinkedList();
	~OrdLinkedList();
	void insert(const T& elem);
	int size();
	bool isEmpty();
	bool first(T& elem);
	bool last(T& elem);
	bool next(T& elem);
	bool previous(T& elem);
	bool find(const T& elem);
	bool remove(const T& elem);
	T& at(int pos);
	T& operator[](int pos);
private:
	struct Node
	{
		T data;
		Node * p_link;
		Node * p_prevLink;
		int CurrentLocation;
	};
	Node* p_head;
	Node* p_tail;

	Node* p_prev;//for insertion
	Node* p_current;//for insertion
	int posCurrent;
	int numElements;
};

template <class T>
OrdLinkedList<T>::OrdLinkedList()
{
	//0 = null
	p_head = 0;
	p_tail = 0;

	p_prev = 0;
	p_current = 0;
	posCurrent=0;
	numElements = 0;
}

template <class T>
void OrdLinkedList<T>::insert(const T& elem)
{
	T x;
	Node* p_newNode = new Node;
		p_newNode -> data = elem;
	if(isEmpty())//if its empty place in the front
	{
		p_newNode -> p_link = p_current;
		p_newNode ->p_prevLink = p_head;
		p_head = p_newNode;
		p_tail = p_newNode;
		first(x);
	}
	//check if the new data is less than the head
	else if(elem < p_head->data)
		{
			p_newNode -> p_link = p_head;
			p_head -> p_prevLink = p_newNode;
			p_head = p_newNode;
			previous(x);
		}//if it is greater than the head and there is only 1 item, throw it at the end
	else if(elem > p_head->data && numElements == 1)
		{
			p_head -> p_link = p_newNode;
			p_newNode -> p_prevLink = p_head;
			p_tail = p_newNode;
			last(x);
		}
	else if(elem >= p_tail->data)
	{
		p_tail -> p_link = p_newNode;
		p_newNode->p_prevLink = p_tail;
		p_tail = p_newNode;
		last(x);
	}
	else if(elem < p_current->data) //step previous
	{
		p_prev = p_current -> p_prevLink;
		while(elem < p_current->data)
		{
			if(elem > p_prev->data)
				break;
			if(p_prev!=p_head)
				p_prev = p_prev->p_prevLink;
			else
				break;
			previous(x);
		}
		p_newNode -> p_link = p_current;
		p_prev -> p_link = p_newNode;
		p_newNode -> p_prevLink = p_prev;
		p_current -> p_prevLink = p_newNode;

	}
	else //step forward
	{
		if(p_current != p_head)
			p_prev = p_current -> p_prevLink;
		else{
			p_prev = p_head;
			next(x);
		}
		while(elem > p_current->data)
		{
			next(x);
			p_prev = p_prev->p_link;
		}
		p_newNode -> p_link = p_current;
		p_current ->p_prevLink = p_newNode;
		p_newNode -> p_prevLink = p_prev;
		p_prev -> p_link = p_newNode;


	}
	numElements++;
}

template <class T>

int OrdLinkedList<T>::size()
{
	return numElements;
}

template <class T>
bool OrdLinkedList<T>::isEmpty()
{
	//return (size()==0);
	return p_head == 0;
}

template <class T>
bool OrdLinkedList<T>::first(T& elem)
{
	if(!isEmpty()) //if the list is not empty
	{
		p_current = p_head;//moce the current pointer back to the beginning of the list
		posCurrent = 0;
		elem = p_head -> data; //store the head nodes data in the passed in elem
		return true;
	}
	return false;
}

template <class T>
bool OrdLinkedList<T>::next(T& elem)
{
	if(p_current!=0 && p_current->p_link !=0)// if the pointers link is NOT null
	{
		p_current = p_current->p_link;// move the pointer
		posCurrent +=1;
		elem = p_current->data; // grab the data from the next node
		return true;
	}
	return false;
}

template <class T>
bool OrdLinkedList<T>::last(T& elem)
{
	if(!isEmpty()) //if the list is not empty
	{
		p_current = p_tail;//moce the current pointer back to the end of the list
		posCurrent = numElements;
		elem = p_tail -> data; //store the tail nodes data in the passed in elem
		return true;
	}
	return false;
}

template <class T>
bool OrdLinkedList<T>::previous(T& elem)
{
	if(p_current!=0 && p_current != p_head)// if the pointers link is NOT null
	{
		p_current = p_current->p_prevLink;// move the pointer
		if(posCurrent-1 >= 0)
			posCurrent -=1;
		if(posCurrent < 0)
			posCurrent = 0;
		elem = p_current->data; // grab the data from the next node
		return true;
	}
	return false;
}

template <class T>
bool OrdLinkedList<T>::find(const T& elem)
{
	//this should leave p_current at the first location of elem

	Node* p_searcher;
	p_searcher = p_current;
	//if pcurrent is less than elem search forwards
	//else search backwards
	if(p_searcher -> data < elem)
	{
		while(p_searcher != p_tail && p_searcher -> data <= elem)
		{
			if(p_searcher->data == elem)
			{
				cout<<"\nFound: "<<elem<<endl;
				p_current = p_searcher;
				return true;
			}
			else
				p_searcher = p_searcher -> p_link;
		}
		if(p_searcher->data == elem)
		{
			cout<<"\nFound: "<<elem<<endl;
			p_current = p_searcher;
			return true;
		}
	}
	else if(p_searcher -> data > elem)
	{
		while(p_searcher != p_head && p_searcher -> data >= elem)
		{
			if(p_searcher->data == elem)
			{
				cout<<"\nFound: "<<elem<<endl;
				p_current = p_searcher;
				return true;
			}
			else
				p_searcher = p_searcher -> p_prevLink;
		}
		if(p_searcher->data == elem)
		{
			cout<<"\nFound: "<<elem<<endl;
			p_current = p_searcher;
			return true;
		}
	}
	else
	{
		cout<<"\nFound: "<<elem<<endl;
			p_current = p_searcher;
			return true;
	}



	cout<<"DID NOT FIND: "<<elem<<endl<<endl;
	return false;
}

template <class T>
bool OrdLinkedList<T>::remove(const T& elem)
{
	//pcurrent from above would be set at the first location
	//find first occurance using algorithm from above

	Node* p_deleteNode;
	while(find(elem))
	{
		p_deleteNode = p_current;
		//fix pointers

		if(p_deleteNode == p_head)
		{
			p_head = p_current -> p_link;
			p_current = p_head;
		}
		else if(p_deleteNode == p_tail)
		{
			p_tail = p_current -> p_prevLink;
			p_current = p_tail;
		}
		else
		{
			p_current = p_current->p_link;
			p_current -> p_prevLink = p_deleteNode -> p_prevLink;
			p_current -> p_prevLink -> p_link = p_current;
		}
		//delete node;
		cout<<"DELETING NODE\n";
		delete p_deleteNode;//delete the node
	}
	if(p_current == 0)
		p_current = p_head;
	return false;
}
template <class T>
T& OrdLinkedList<T>::operator[](int pos)
{
	if(pos >= 0 && pos <= size()-1)
		return at[pos];
	//throw exception
}
template<class T>
T& OrdLinkedList<T>::at(int pos)
{

	Node* p_temp;
	p_current = p_head;
	if(pos >= 0 && pos <= size()-1)
	{
		for(int i=0;i<pos;i++)
		{
			p_temp = p_current -> p_link;
			p_current = p_current->p_link;
		}
	}else
		cout<<"throw SafeArrayOutOfBoundsException(); HERE!";

	return p_current -> data;
	//throw exception;

}
/*NOT WORKING CUZ OF posCURRENT NOT CORRECTLY IDENTIFYING WHERE THE CURRENT POSITION IS AT
template<class T>
T& OrdLinkedList<T>::at(int pos)
{
	T x;
	if(pos >= 0 && pos <= size()-1)
	{
		if(pos == 0)
		{
			p_current = p_head;
			posCurrent = 0;
			return p_current -> data;
		}
		while(pos!=posCurrent)

			if(posCurrent < pos)
				next(x);

			else if(posCurrent > pos)
			{
				if(posCurrent-1!=pos)
					previous(x);
				else
					break;
			}
	}

	return p_current -> data;
	//throw exception;
	//else
		//throw SafeArrayOutOfBoundsException();
}
*/
template <class T>
OrdLinkedList< T>::~OrdLinkedList()
{
	cout<<"Deconstructing the linked list"<<endl;
	Node* p_deleteNode;
	while(p_head!= p_tail)//while the head points to a node
	{
		p_deleteNode = p_head;//move the delete pointer to point to the head
		cout<<p_deleteNode->data;
		p_head = p_head -> p_link;// move the head pointer forward
		delete p_deleteNode;//delete the node
	}
		p_deleteNode = p_head;//move the delete pointer to point to the head
		cout<<p_deleteNode->data;
		p_head = p_head -> p_link;// move the head pointer forward
		delete p_deleteNode;//delete the node
}
