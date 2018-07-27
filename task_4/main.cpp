#include "Handler.h"
#include <bitset>
#include "InputMetod.h"

using namespace std;
void main()
{
	char *str = new char[11];
	double a = 10,b = 12;
	int choose_figure;
	cout << "Choose figure" << endl;
	cout << "1. Rectangle" << endl;
	cin >> choose_figure;
	cout << "Enter data" << endl;
	cout << "Height a:" << endl;
	cin >> a;
	cout << "Height b:" << endl;
	cin >> b;
	cout << "Enter config" << endl;
	cin >> str ;
	if (Is_good_input_config(str))
	{	
		bitset<4> bitvec(str);
		Rectangle rectangle(a,b);
		Handler _my_handler(rectangle,bitvec);
		_my_handler.main_func_of_handler();
	}
	system("pause");
}