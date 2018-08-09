#include "Node.h"
using namespace std;


template <class Type>

class List
{
private:
	Node<Type>* head;
	Node<Type>* tail;

public:
	List();
	~List();
	bool IsEmpty();
	void PushBegin(Type data);
	void PushEnd(Type data);
	int Count_Node_with_data(Type data);
	void DeleteHead();
	void Delete();
	void DeleteNode(int pos);
	void Print();
};

template <class Type>
List<Type>::List()
{
	head = NULL;
	tail = NULL;
}

template <class Type>
List<Type>::~List()
{
	 Delete();
}

template <class Type>
void List<Type>::PushBegin(Type data)
{
	Node<Type> *temp = new Node<Type>(data);
	temp->SetNext(head);
	head = temp ;
	if(tail == NULL)// if list empty --> head = NULL = tail  , if list have 1 node -- > head = tail = thisnode
		tail = head;
}

template <class Type>
void List<Type>::PushEnd(Type data)
{
	Node<Type> *temp = new Node<Type>(data);
	if (head == NULL) // head = NULL = tail , if list empty , if list have 1 node, head = tail = thisnode
		head = temp;
	else
		tail->SetNext(temp);
	tail = temp ;
}

template <class Type>
bool List<Type>::IsEmpty()
{
	if (head == NULL)
		return 1;
	return 0;
}

template <class Type>
int List<Type>::Count_Node_with_data(Type data)
{
	int count;
	Node<Type> *temp = head;

	while(temp != NULL)
	{
		if (temp->GetData() == data)
			cout++;
		temp = temp->GetNext;
	
	}
	return count;
}

template <class Type>
void List<Type>::DeleteHead()
{
	if(IsEmpty())
		return;
	Node<Type> *curr = head;
	head = curr->GetNext() ;
	delete curr;
}

template <class Type>
void List<Type>::Delete()
{
	while (head != NULL)
		DeleteHead();
}

template <class Type>
void List<Type>::DeleteNode(int pos)
{
	if(IsEmpty())
		return;
	Node<Type> *curr = new Node<Type>;
	Node<Type> *temp = head;
	if (pos == 0)
	{
		DeleteHead();
		return;
	}
	for(int i = 0 ; i < pos - 1 ; i++)
	{
		if (temp->GetNext() == NULL)
			return;
		temp = temp->GetNext();
	}
	curr = temp->GetNext();
	temp->SetNext(curr->GetNext());
	if (curr->GetNext() == NULL)
		tail = temp;
	delete curr;
}

template <class Type>
void List<Type>::Print()
{
	Node<Type> *temp = head; 
	while(temp != NULL)
	{
		cout << temp->GetData() << "  ";
		temp = temp->GetNext() ;
	}
}


