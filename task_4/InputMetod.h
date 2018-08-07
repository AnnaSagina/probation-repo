#include "Handler.h"
using namespace std;
#ifndef __INPUT_METOD_H__
#define __INPUT_METOD_H__

const char INCORR_DATA_MESSEGE[20] = "incorrect data";

bool Is_good_input_config(string str_config)
{
	int i = 0 ;
	while ((i < str_config.size())&&((str_config[i] == '0')||(str_config[i] == '1')))
		i++;
	if (i != 4)
	{
		cout << INCORR_DATA_MESSEGE << endl;
		return 0;
	}
	return 1;
}

#endif