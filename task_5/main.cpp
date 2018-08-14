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
	cout << "" << endl;
	cout << " Count data = 0 :" << list_int.Count_Node_with_data(0);
	cout << "" << endl;

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
	cout << "Added 2 elemets";
	cout << "" << endl;
	list_int.PushBegin(1);
	list_int.PushEnd(2);
	list_int.Print();
	list_int.Delete();
	cout << "" << endl;

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