#include "hard.h"
using namespace std;
void main()
{
	Node* One = new Node;
	Node* Two = new Node;
	Node* Three = new Node;
	Node* Four = new Node;
	Node* Five = new Node;
	Node* Six = new Node;
	One->Data = 1;
	One->next = Two;
	Two->Data = 2;
	Two->next = Three;
	Three->Data = 3;
	Three->next = Four;
	Four->Data = 4;
	Four->next = Five;
	Five->Data = 5;
	Five->next = Six;
	Six->Data = 6;
	Six->next = Two;

	Node* fast = One;
	Node* slow = One;
	int i = 1;
	do
	{
		if (fast == NULL)
		{
			cout << "нет циклов"; 
			break;
		}
		fast = fast->next;
		if (i % 2 == 0)
		{
			slow = slow->next;
		}
		i++;
	} while(fast != slow);
	
	cout <<slow->Data;
	cout <<fast->Data;
	system ("pause");
}