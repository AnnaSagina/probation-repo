#include "hard.h"
using namespace std;
void main()
{
	Node** List = new Node*[6];
	for (int i = 0; i < 6; i++)
	{
		List[i] = new Node;
		List[i]->Data = i;
	}
	for (int i = 0; i < 5; i++)
	{
		List[i]->next = List[i + 1];
	}
	List[5]->next = List[2];

	Node* fast = List[0];
	Node* slow = List[0];
	bool flag = 0;
	do
	{
		if (fast == NULL)
		{
			cout << "нет циклов"; 
			break;
		}
		fast = fast->next;
		if (flag)
		{
			slow = slow->next;
		}
		flag = !flag;
	} while(fast != slow);
	
	cout <<slow->Data;
	cout <<fast->Data;
	system ("pause");
}