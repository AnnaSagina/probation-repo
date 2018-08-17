#include "List.h"


using namespace std;


void main()
{
	List<int> list_int;
	List<char*> list_string;
	for (int i = 0; i < 15; i++)
	{
		list_int.Push(i);
		list_int.PushBegin(i);
	}
	list_int.Print();
	cout << "" << endl;
	cout << " Count data = 0 :" << list_int.Count_Node_with_data(0);
	cout << "" << endl;
	list_int.DeleteNode(list_int.Find(2));
	list_int.DeleteNode(list_int.Find(13));
	cout << "" << endl;
	cout << "Delete  sixth and last elements" << endl;
	
	list_int.Print();

	
	cout << "" << endl;

	cout << "New list of strings:" << endl;
	list_string.Push("I");
	list_string.Push("have");
	list_string.Push("done");
	list_string.Push("template");
	list_string.Push("list");
	list_string.Print();
	cout << endl;
		system("pause");
	
}