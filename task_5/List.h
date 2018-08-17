#include "Node.h"
using namespace std;


template <class Type>

class List
{
private:
	Node<Type>* head;
	Node<Type>* tail;
	void DeleteHead();
	void Delete();

public:
	List();
	~List();
	bool IsEmpty();
	void PushBegin(Type data);
	void Push(Type data);
	int Find(Type Data);
	int Count_Node_with_data(Type data);
	void DeleteNode(unsigned int pos);
	void Print();
};
template <class Type>
int vdd()
{

}
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
int List<Type>::Find(Type Data)
{
	Node<Type> *temp = head;
	int i = 0;
	if (IsEmpty())
		return -1;
	while (temp->GetData() != Data)
	{
		temp = temp->GetNext();
			if (temp == NULL)
				return -1;
		i++;
	}
	return i;
}
template <class Type>
void List<Type>::PushBegin(Type data)
{
	Node<Type> *temp = new Node<Type>(data);
	if(IsEmpty())
		tail = temp;
	else
		temp->SetNext(head);
	head = temp;
}

template <class Type>
void List<Type>::Push(Type data)
{
	Node<Type> *temp = new Node<Type>(data);
	if (IsEmpty()) // head = NULL = tail , if list empty , if list have 1 node, head = tail = thisnode
		head = temp;
	else
		tail->SetNext(temp);
	tail = temp ;
}

template <class Type>
bool List<Type>::IsEmpty()
{
	if ((head == NULL)&&(tail == NULL))
		return 1;
	return 0;
}

template <class Type>
int List<Type>::Count_Node_with_data(Type data)
{
	int count = 0;
	Node<Type> *temp = head;

	while(temp != NULL)
	{
		if (temp->GetData() == data)
			count++;
		temp = temp->GetNext();
	
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
	curr = NULL;
	if (head ==	NULL)
		tail = NULL;
}

template <class Type>
void List<Type>::Delete()
{
	while (!IsEmpty())
		DeleteHead();
}

template <class Type>
void List<Type>::DeleteNode(unsigned int pos)
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


