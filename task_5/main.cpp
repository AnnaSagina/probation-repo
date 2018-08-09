#include "List.h"


using namespace std;


void main()
{
	List<int> list_int;
	List<char*> list_string;
	for (int i = 0; i < 15; i++)
	{
		list_int.PushEnd(i);
		list_int.PushBegin(i);
	}

	list_int.Print();

	list_int.DeleteNode(6);
	list_int.DeleteNode(28);
	cout << "" << endl;
	cout << "Delete  sixth and last elements" << endl;
	
	list_int.Print();

	list_int.Delete();

	cout << endl;
	if (list_int.IsEmpty())
	cout << "Delete list";
	cout << "" << endl;
	list_int.Print();
	cout << "New list of strings:" << endl;
	list_string.PushEnd("I");
	list_string.PushEnd("have");
	list_string.PushEnd("done");
	list_string.PushEnd("template");
	list_string.PushEnd("list");
	list_string.Print();
	cout << endl;
		system("pause");
	
}