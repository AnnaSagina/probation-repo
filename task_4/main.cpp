#include "Handler.h"
#include <bitset>
#include "InputMetod.h"

using namespace std;
void main()
{
	char *str = new char[4];
	double a = 10,b = 12;
	int continue_flag = 1;
	int change_config = 1;
	while (continue_flag == 1)
	{
		cout << "Enter data" << endl;
		cout << "Height a:" << endl;
		cin >> a;
		cout << "Height b:" << endl;
		cin >> b;
		while (change_config == 1)
		{
			cout << "Enter config" << endl;
			cin >> str ;
			if (Is_good_input_config(str))
			{	
				bitset<4> config(str);
				Rectangle rectangle(a,b);
				Handler my_handler(rectangle,config);
				my_handler.main_func_of_handler();
			}
			cout << endl;
			cout << "Change the config?" << endl; 
			cin >> change_config;
		}
			cout << "Continue?" << endl;
			cout << "1.Yes" << endl;
			cin >> continue_flag;
	}
	system("pause");
}