#include "Handler.h"
#include <bitset>
#include "InputMetod.h"


using namespace std;

void main()
{
	map <string,Handler*> MapForHandler;
	map <string,Handler*>::iterator i;
	string str_config;
	double a,b;
	int continue_flag = 1;
	int change_rec = 1;
	int change_config = 1;
	cout << "Enter data" << endl;
	while (continue_flag == 1)
	{
		if (change_rec == 1)
		{
			cout << "Height a:" << endl;
			cin >> a;
			cout << "Height b:" << endl;
			cin >> b;
		}
		if (change_config == 1)
		{
			cout << "Enter config" << endl;
			cin >> str_config;
		}
		if (Is_good_input_config(str_config))
		{
			bitset<4> config(str_config);
			Rectangle rectangle(a,b);
			Handler*  my_handler = NULL;
			if ((i = MapForHandler.find(str_config)) != MapForHandler.end())
			{
				my_handler = (*i).second;
				cout << "I FIND IN MAP" << endl;
			}
			else
			{
				my_handler = new Handler(config);
				MapForHandler.insert(pair<string,Handler*>(str_config, my_handler));
			}
			my_handler->main_func_of_handler(rectangle).print();
			cout << "Continue?" << endl;
			cout << "1.Yes" << endl;
			cin >> continue_flag;
			if (continue_flag != 1)
			{
				cout <<" All elelemets of MAP" << endl;
				for (i = MapForHandler.begin() ; i != MapForHandler.end(); i++)
				{
					cout << i->first << ' ' << i->second << endl;
				}
				break;
			}
			cout << "Change the config?" << endl;
			cout << "1.Yes" << endl;
			cin >> change_config;
			cout << "Change the rectangle?" << endl;
			cout << "1.Yes" << endl;
			cin >> change_rec;		
		}			
	}
	system("pause");
}
