#include "Handler.h"
#include <bitset>
#include "InputMetod.h"


using namespace std;


void main()
{
	map <string,struct_for_Handler> MapForHandler;
	string str_config;
	double a = 10,b = 12;
	int continue_flag = 1;
	int count = 1;
	while (continue_flag == 1)
	{
		cout << "Enter data" << endl;
		cout << "Height a:" << endl;
		cin >> a;
		cout << "Height b:" << endl;
		cin >> b;
		int change_config = 1;
		while (change_config == 1)
		{
			cout << "Enter config" << endl;
			cin >> str_config;
			if (Is_good_input_config(str_config))
			{
				bitset<4> config(str_config);
				Rectangle rectangle(a,b);
				Handler my_handler(config);

				if (!MapForHandler.count(str_config))
				{
					MapForHandler.insert(pair<string,struct_for_Handler>(str_config, my_handler.main_func_of_handler(rectangle)));
				}	
				my_handler.printstruct(MapForHandler,str_config);
			}
			cout << endl;
			cout << "Change the config?" << endl; 
			cout << "1. Yes" << endl;
			cin >> change_config;
		}
			MapForHandler.clear();
			cout << "Continue?" << endl;
			cout << "1.Yes" << endl;
			cin >> continue_flag;
	}
	system("pause");
}